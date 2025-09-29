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
    UnderVoltage,
    OverCurrent,
    OverTemperature,
    OverVoltage
} Status;

typedef struct SPI_data_t
{
	uint16_t Vout;
	uint16_t Iout;
	uint8_t Tmax;
	uint8_t status;
	uint16_t checksum;

} SPI_data_t;

void SPI_init();
void SPI_SendBuffer(SPI_data_t);
void SPI_calculateChecksum();

#endif /* SPI_H_ */
