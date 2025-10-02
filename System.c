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

DataStream_data_buffer_t buffer;

int8_t counter = 0;
SystemState_t state;



static void inline updatePowerScope()
{
	
	int16_t temp[DataStream_NUMBER_OF_CHANNELS];
	
//	temp[0] = (int16_t)(IOUT_CountsToAmps(IOUT));
	temp[0] = (int16_t)((IOUT));
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


void doFanControl()
{
	
}


void sendSPIData()
{
	slaveData.out.Voltage = 42;
	slaveData.out.Current = 69;
	slaveData.out.Feedforward = 420;
	slaveData.out.Temp1 = 666;
	slaveData.out.Temp2 = 999;
	slaveData.out.status = 12;
	slaveData.out.checksum = 0;
	slaveData.out.checksum = SPI_calculateChecksum(&slaveData.out);
	
	//Normally we don't have to call this function but when we are testing on the same MCU we need
	//different send for primary and secondary
	Cy_SCB_SPI_WriteArray	(sSPI_HW, &slaveData.out, sizeof(data_t));
	
	masterData.out.Voltage = VOUT;
	masterData.out.Current = IOUT;
	masterData.out.Feedforward = 42;
	masterData.out.Temp1 = TEMP1;
	masterData.out.Temp2 = TEMP2;
	masterData.out.status = 10;
	masterData.out.checksum = 0;
	masterData.out.checksum = SPI_calculateChecksum(&masterData.out);
	
	//Normally calling send should be enough because we know what we are slave or master and which HW to use
	SPI_send(&masterData.out);
	
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
	






