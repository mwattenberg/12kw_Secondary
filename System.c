/*
 * System.c
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */

#include "ADC.h"
#include "SPI.h"
#include "DataStream.h"

DataStream_data_buffer_t buffer;

int8_t counter = 0;

static void inline updatePowerScope()
{
	int16_t temp[DataStream_NUMBER_OF_CHANNELS];

	temp[0] = (int16_t)(IOUT);
	temp[1] = (int16_t)(VOUT);
	temp[2] = (int16_t)(TEMP1);
	temp[3] = (int16_t)(TEMP2);
	temp[4] = counter;
	temp[5] = 0;
	temp[6] = 0;
	temp[7] = 0;
	
	counter++;

	DataStream_addFrame(&buffer, temp);

	if (buffer.current_frame == DataStream_NUMBER_OF_FRAMES)
		DataStream_WriteBufferToOutput(&buffer);
}

void System_UpdateStateMachine()
{
	if(Cy_SCB_UART_IsTxComplete(UART_PowerScope_HW))
		updatePowerScope();
	
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





