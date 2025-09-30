/*
 * SPI.c
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */


#include "SPI.h"
#include "cy_scb_common.h"
#include "cy_scb_spi.h"

cy_stc_scb_spi_context_t context;
uint16_t TxBuffer[16];
uint16_t RxBuffer[16];

void SPI_init()
{
	//Context can also be null
	Cy_SCB_SPI_Init(mSPI_HW, &mSPI_config, &context);
	Cy_SCB_SPI_Enable(mSPI_HW);
	
	
	for(uint32_t i = 0; i < sizeof(TxBuffer); i++)
	{
		TxBuffer[i] = i;	
	}
	
}


void SPI_SendBuffer(SPI_data_t* data)
{
	Cy_SCB_SPI_Transfer(mSPI_HW, TxBuffer, RxBuffer, sizeof(TxBuffer), &context);
}
void SPI_calculateChecksum()
{
	
	
}