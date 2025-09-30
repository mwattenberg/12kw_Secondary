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
#include <string.h>

DataStream_data_buffer_t buffer;

int8_t counter = 0;
SystemState_t state;

static void inline updatePowerScope()
{
	int16_t temp[DataStream_NUMBER_OF_CHANNELS];

//	temp[0] = (int16_t)(IOUT_CountsToAmps(IOUT));
	temp[0] = (int16_t)((IOUT));
	temp[1] = (int16_t)(VOUT_CountsToVolts(VOUT));
	temp[2] = (int16_t)(TEMP_CountsToCelsius(TEMP1));
	temp[3] = (int16_t)(TEMP_CountsToCelsius(TEMP2));

	
	temp[4] = counter;
	temp[5] = 0;
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
	
	if(	Cy_SCB_SPI_IsTxComplete(mSPI_HW))
		SPI_SendBuffer(NULL);
	
	switch (state)
	{
		case STATE_INIT:
			myCounter = 0;
			
			Cy_GPIO_Set(PIN_LED_FAULT_PORT, PIN_LED_FAULT_PIN);
			
			Cy_GPIO_Set(PIN_DISABLE_FAN_PORT, PIN_DISABLE_FAN_PIN);
			
			Cy_GPIO_Set(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_PIN);
			Cy_GPIO_Clr(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_PIN);
			
			PWM_fanSetDuty(0.0f);
		
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
			break;
		case STATE_ENABLE_LINEAR_FET:
			break;
		case STATE_ENABLE_ORING:
		Cy_GPIO_Clr(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_PIN);
		Cy_GPIO_Set(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_PIN);
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
	






