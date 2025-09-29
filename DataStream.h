/*
 * DataStream.h
 *
 *  Created on: 11 Apr 2024
 *      Author: wattenberg
 */




#ifndef DATA_BUFFER_H
#define DATA_BUFFER_H

#include "cybsp.h"

// #define USE_DMA

#define SCB_number UART_PowerScope_HW

// Define the data type for each channel
typedef uint16_t channel_data_t;

// Define the number of frames and channels
#define DataStream_NUMBER_OF_FRAMES 1UL	//1920		//Needs to be UL
#define DataStream_NUMBER_OF_CHANNELS 8			//9

// Define the start sequence. Be aware it is limited to channel_data_t size.
#define DataStream_START_SEQUENCE 0xAAAA

// Define the size of the channel data
#define DataStream_CHANNEL_DATA_SIZE sizeof(channel_data_t)

// Define the data buffer structure
typedef struct {
	channel_data_t data[DataStream_NUMBER_OF_FRAMES * (DataStream_NUMBER_OF_CHANNELS + 1)];
    uint16_t current_frame;
    bool data_is_currently_being_written;
} DataStream_data_buffer_t;

// Function prototypes
void DataStream_init_buffer(DataStream_data_buffer_t *buffer);
void DataStream_writeData(DataStream_data_buffer_t *buffer, uint32_t frame_number, uint32_t channel_number, channel_data_t data);
void DataStream_addFrame(DataStream_data_buffer_t *buffer, channel_data_t *channel_data);
void DataStream_WriteBufferToOutput(DataStream_data_buffer_t *buffer);

#endif  // DATA_BUFFER_H
