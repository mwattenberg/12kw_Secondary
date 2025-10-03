/*
 * System.c
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */

#include "ADC.h"
#include "SPI.h"
#include "DataStream.h"
#include "_CONFIGURATION.h"
#include "cy_gpio.h"
#include "System.h"
#include "PWM.h"
#include "cy_scb_spi.h"
#include "cycfg_peripherals.h"
#include <string.h>
#include <math.h> 

DataStream_data_buffer_t buffer;

int8_t counter = 0;
SystemState_t state;


// --- Control Setpoints (Define these globally) ---
#define TEMP_OFF_THRESHOLD_C      60.0f
#define TEMP_MAX_RAMP_C           90.0f
#define MAX_DUTY_RATIO            0.5f  // For 50% duty cycle

// --- Shared Variable (Declare only ONCE at file scope for debugging) ---
static float FAN_duty_cycle = 0.0f;
static float current_temperature;

static void inline updatePowerScope()
{
	
	int16_t temp[DataStream_NUMBER_OF_CHANNELS];
	
//	temp[0] = (int16_t)(IOUT_CountsToAmps(IOUT));
	temp[0] = (int16_t)(10*IOUT_CountsToAmps(IOUT));
	temp[1] = (int16_t)(10*VOUT_CountsToVolts(VOUT));
	temp[2] = (int16_t)(10*TEMP_CountsToCelsius(TEMP1));		
	temp[3] = (int16_t)(10*TEMP_CountsToCelsius(TEMP2));
	
	
	temp[4] = counter;
	temp[5] = (int16_t)(ADC_config.filter);
	temp[6] = 0;
	temp[7] = 0;
	
	counter++;

	DataStream_addFrame(&buffer, temp);

	if (buffer.current_frame == DataStream_NUMBER_OF_FRAMES)
		DataStream_WriteBufferToOutput(&buffer);
}


void doFanControl(void)
{
    float temp_sensor1;
    float temp_sensor2;
    
    // 1. Read and convert both temperatures
    temp_sensor1 = (float) TEMP_CountsToCelsius(TEMP1);
    temp_sensor2 = (float) TEMP_CountsToCelsius(TEMP2);

    // 2. Set current_temperature to the MAXIMUM of the two readings
    current_temperature = fmaxf(temp_sensor1, temp_sensor2);

    // --- Fan Control Logic (The same as before) ---
    if (current_temperature < TEMP_OFF_THRESHOLD_C)                                                       
    {                                                                      
        // --- 1. Less than 60°C: Fan OFF (0.0 ratio) ---
		FAN_duty_cycle = 0.0f;                                              
    }                                                                       
    else if (current_temperature >= TEMP_MAX_RAMP_C)                              
    {     
        // --- 3. More than or equal to 90°C: Constant 50% Max (0.5 ratio) ---
		FAN_duty_cycle = MAX_DUTY_RATIO;            
    }                                                                       
    else                                                                   
    {        
		// --- 2. 60°C to 90°C: Linear Ramp (0.0 to 0.5) ---

        // The total temperature range for the ramp (90 - 60 = 30)
        const float temp_range = TEMP_MAX_RAMP_C - TEMP_OFF_THRESHOLD_C; 
        
        // Current temperature difference within the ramp
        float temp_above_off = current_temperature - TEMP_OFF_THRESHOLD_C;

        // Ratio of the temperature ramp completed (0.0 to 1.0)
        float temp_ratio = temp_above_off / temp_range;

        // Scale the temperature ratio to the duty cycle ratio (0.0 to 0.5)
        FAN_duty_cycle = temp_ratio * MAX_DUTY_RATIO;                                                            
    }
    
    // Safety check 
    if (FAN_duty_cycle > MAX_DUTY_RATIO) {
        FAN_duty_cycle = MAX_DUTY_RATIO;
    }

    // Apply the calculated duty cycle ratio (0.0f to 0.5f)
    PWM_fanSetDuty(FAN_duty_cycle); 
}


void sendSPIData()
{
	masterData.Vout = VOUT;
	masterData.Iout = IOUT;
	masterData.Iout_Feedforward = 42;	//here we have to implement bandpass filter for feedforward
	masterData.Temp1 = TEMP1;
	masterData.Temp2 = TEMP2;
	masterData.status = 10;
	masterData.checksum = SPI_calculateChecksum(&masterData);
	SPI_DoTheThing();
	
}

void System_init()
{
	Cy_SysTick_SetCallback(0, System_UpdateStateMachine);
	NVIC_SetPriority(CY_SYSTICK_IRQ_NUM,3);
	Cy_SysTick_Enable();
	
	//Use PowerScope for plotting
	Cy_SCB_UART_Init(UART_PowerScope_HW, &UART_PowerScope_config, NULL);
	Cy_SCB_UART_Enable(UART_PowerScope_HW);
	DataStream_init_buffer(&buffer);
	
}

void System_UpdateStateMachine()
{
	static uint32_t myCounter = 0;
	
	if(Cy_SCB_UART_IsTxComplete(UART_PowerScope_HW))
		updatePowerScope();
	
	if(Cy_SCB_SPI_IsTxComplete(mSPI_HW))
		sendSPIData();	
	
	switch (state)
	{
		case STATE_INIT:
			myCounter = 0;
			
			Cy_GPIO_Set(PIN_LED_FAULT_PORT, PIN_LED_FAULT_PIN);
			
			Cy_GPIO_Set(PIN_DISABLE_FAN_PORT, PIN_DISABLE_FAN_PIN);
			
			Cy_GPIO_Set(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_PIN);
			Cy_GPIO_Clr(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_PIN);
			
			PWM_fanSetDuty(0.0f);
			
			state = STATE_CHECK_FAN;
		
			break;
		case STATE_CHECK_FAN:
		
			Cy_GPIO_Clr(PIN_DISABLE_FAN_PORT, PIN_DISABLE_FAN_PIN);
		
			if(myCounter < 50)
				PWM_fanSetDuty(0.25f);
			else if (myCounter < 100)
	 			PWM_fanSetDuty(0.0f);
			else
			{
				state = STATE_CHECK_VOUT;
				myCounter = 0;
			}
				
			myCounter++;
			

			
			break;
		case STATE_CHECK_VOUT:
			state = STATE_ENABLE_LINEAR_FET;
			break;
		case STATE_ENABLE_LINEAR_FET:
			state = STATE_ENABLE_ORING;
			break;
		case STATE_ENABLE_ORING:
		Cy_GPIO_Clr(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_PIN);
		Cy_GPIO_Set(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_PIN);
		
			state = STATE_RUN;
			break;
		case STATE_RUN:
		Cy_GPIO_Clr(PIN_LED_FAULT_PORT, PIN_LED_FAULT_PIN);
		Cy_GPIO_Set(PIN_LED_RUN_PORT, PIN_LED_RUN_PIN);
		doFanControl();
			break;
			
			
			
			
		case STATE_AC_LOSS:
			Cy_GPIO_Set(PIN_AC_LOSS_PORT, PIN_AC_LOSS_PIN);
			break;
		
		case STATE_OTP:
//			break;	//No break, handle all error in same state
		case STATE_OCP:
//			break;	//No break, handle all error in same state
		case STATE_ERROR:
		Cy_GPIO_Set(PIN_LED_FAULT_PORT, PIN_LED_FAULT_PIN);
		
		Cy_GPIO_Set(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_PIN);
		Cy_GPIO_Clr(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_PIN);
			break;
		
	}

}
	






