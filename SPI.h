/*
 * SPI.h
 *
 *  Created on: 18.09.2025
 *      Author: wattenberg
 */

#ifndef SPI_H_
#define SPI_H_

#include "cybsp.h"

typedef enum Status {
    UnderVoltage = 1,
    OverCurrent = 2,
    OverTemperature = 3,
    OverVoltage = 4
} Status;

typedef struct data_t
{
	int16_t Voltage;
    int16_t Current;
    int16_t Feedforward;
    int16_t Temp1;
    int16_t Temp2;
    int8_t status;
    uint8_t checksum;
} data_t;


//the primary side is slave
typedef struct SPI_data_t 
{
	data_t out;
    data_t in;
} SPI_data_t;

extern SPI_data_t masterData;
extern SPI_data_t slaveData;


void SPI_Master_init();
void SPI_Slave_init();
void SPI_send(data_t* data);
uint8_t SPI_calculateChecksum(data_t* data);

#endif /* SPI_H_ */
