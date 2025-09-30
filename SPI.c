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

SPI_masterData_t masterData;
SPI_slaveData_t slaveData;

void SPI_init()
{
	//Context can also be null
	Cy_SCB_SPI_Init(mSPI_HW, &mSPI_config, NULL);
	Cy_SCB_SPI_Enable(mSPI_HW);
	
	masterData.Vout = 42;
	masterData.Iout = 100;
	masterData.Iout_Feedforward = 420;
	masterData.Temp1 = 666;
	masterData.Temp2 = 69;		
	masterData.status = 0b10101010;
	masterData.checksum = 0b11001100;
	
}


void SPI_DoTheThing()
{
	Cy_SCB_SPI_WriteArray	(mSPI_HW, &masterData, sizeof(masterData));
	Cy_SCB_SPI_ReadArray(mSPI_HW, &slaveData, sizeof(masterData));
}



uint8_t SPI_calculateChecksum(SPI_masterData_t* data) 
{
    uint8_t checksum = 0;
    for (uint16_t i = 0; i < sizeof(*data); i++) 
    {
        checksum ^= ((uint8_t*)data)[i];
    }
    return checksum;
}