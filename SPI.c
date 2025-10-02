/*
 * SPI.c
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */


#include "SPI.h"
#include "cy_scb_common.h"
#include "cy_scb_spi.h"
#include <stdint.h>
#include <string.h>

SPI_data_t masterData;
SPI_data_t slaveData;

void ISR_SlaveReceive()
{
	uint32_t bytesInBuffer = Cy_SCB_GetNumInRxFifo(sSPI_HW);
	if(bytesInBuffer > 0)
	{
		Cy_SCB_SPI_ReadArray(sSPI_HW, &slaveData.in, bytesInBuffer);
		Cy_SCB_SPI_ClearRxFifo(sSPI_HW); //Not sure if this is really smart
	}
		
	
	NVIC_ClearPendingIRQ(sSPI_IRQ);
	uint32_t status = Cy_SCB_GetRxInterruptStatus(sSPI_HW);
	Cy_SCB_ClearRxInterrupt(sSPI_HW, status);
}

void ISR_MasterReceive()
{
	uint32_t bytesInBuffer = Cy_SCB_GetNumInRxFifo(mSPI_HW);
	
	if(bytesInBuffer > 0)
	{
		Cy_SCB_SPI_ReadArray(mSPI_HW, &masterData.in, bytesInBuffer);
		Cy_SCB_SPI_ClearRxFifo(mSPI_HW); //Not sure if this is really smart
	}
		
	NVIC_ClearPendingIRQ(mSPI_IRQ);
	uint32_t status = Cy_SCB_GetRxInterruptStatus(mSPI_HW);
	Cy_SCB_ClearRxInterrupt(mSPI_HW, status);
}

void SPI_Master_init()
{
	//Context can also be null
	Cy_SCB_SPI_Init(mSPI_HW, &mSPI_config, NULL);
	
	uint32_t rxTriggerLevel = sizeof(masterData.in) - 1;
	Cy_SCB_SetRxFifoLevel(mSPI_HW,rxTriggerLevel);
	
	Cy_SCB_SPI_Enable(mSPI_HW);


	cy_stc_sysint_t interruptus;
	interruptus.intrSrc = mSPI_IRQ; // @suppress("Field cannot be resolved")
	interruptus.intrPriority = 2; // @suppress("Field cannot be resolved")
	Cy_SysInt_Init(&interruptus, ISR_MasterReceive);
	NVIC_ClearPendingIRQ(interruptus.intrSrc); // @suppress("Field cannot be resolved")
	NVIC_EnableIRQ(interruptus.intrSrc);	
}

void SPI_Slave_init()
{
	//Context can also be null
	Cy_SCB_SPI_Init(sSPI_HW, &sSPI_config, NULL);
		
	uint32_t rxTriggerLevel = sizeof(slaveData.in) - 1;
	Cy_SCB_SetRxFifoLevel(mSPI_HW,rxTriggerLevel);
	
	Cy_SCB_SPI_Enable(sSPI_HW);
	
	
	cy_stc_sysint_t interruptus;
	interruptus.intrSrc = sSPI_IRQ; // @suppress("Field cannot be resolved")
	interruptus.intrPriority = 2; // @suppress("Field cannot be resolved")
	Cy_SysInt_Init(&interruptus, ISR_SlaveReceive);
	NVIC_ClearPendingIRQ(interruptus.intrSrc); // @suppress("Field cannot be resolved")
	NVIC_EnableIRQ(interruptus.intrSrc);		
	
	
	
	
}


void SPI_send(data_t* data)
{
	Cy_SCB_SPI_WriteArray	(mSPI_HW, data, sizeof(data_t));
}

uint8_t SPI_calculateChecksum(data_t* data) 
{
    uint8_t checksum = 0;
    for (uint16_t i = 0; i < sizeof(data_t); i++) 
    {
        checksum ^= ((uint8_t*)data)[i];
    }
    return checksum;
}