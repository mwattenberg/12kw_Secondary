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

//The secondary side is master
typedef struct __attribute__((packed)) spi_MasterData_t {
    int16_t Vout;
    int16_t Iout;
    int16_t Iout_Feedforward;
    int16_t Temp1;
    int16_t Temp2;
    int8_t status;
    uint8_t checksum;
} SPI_masterData_t;

//the primary side is slave
typedef struct __attribute__((packed)) spi_SlaveData_t {
    int16_t Vin;
    int16_t Iin;
    int16_t Iout_Feedforward;
    int16_t Temp1;
    int16_t Temp2;
    int8_t status;
    uint8_t checksum;
} SPI_slaveData_t;

extern SPI_masterData_t masterData;
extern SPI_slaveData_t slaveData;


void SPI_init();
void SPI_DoTheThing();
uint8_t SPI_calculateChecksum(SPI_masterData_t* data);

#endif /* SPI_H_ */
