///*
// * DataStream.c
// *
// *  Created on: 18 Jan 2024
// *      Author: wattenberg
// */

#include "DataStream.h"

DataStream_data_buffer_t *myBuffer;

#ifdef USE_DMA
void DMA_done()
{
	myBuffer->data_is_currently_being_written = false;
	myBuffer->current_frame = 0;

	Cy_DMA_Channel_ClearInterrupt(DMA_SPA_HW, DMA_SPA_CHANNEL);
}


void init_DMA(DataStream_data_buffer_t *buffer)
{
	uint32_t framesPerXTransfer = 1;
	uint32_t bytePerFrame = DataStream_CHANNEL_DATA_SIZE*(DataStream_NUMBER_OF_CHANNELS + 1);

	while(((framesPerXTransfer +1) * bytePerFrame) < 128 && framesPerXTransfer < DataStream_NUMBER_OF_FRAMES)
	{
		framesPerXTransfer++;
	}

	DMA_SPA_Descriptor_0_config.xCount = framesPerXTransfer*bytePerFrame;
	DMA_SPA_Descriptor_0_config.dataSize = 0;						//CY_DMA_BYTE = 0UL, 	CY_DMA_HALFWORD = 1UL,	 CY_DMA_WORD = 2UL

	DMA_SPA_Descriptor_0_config.srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA;

	DMA_SPA_Descriptor_0_config.dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD;	//Destination needs to be WORD because of the FIFO implementation

	DMA_SPA_Descriptor_0_config.yCount = DataStream_NUMBER_OF_FRAMES/(framesPerXTransfer);

	if(DMA_SPA_Descriptor_0_config.yCount == 0)
			DMA_SPA_Descriptor_0_config.yCount = 1;

	DMA_SPA_Descriptor_0_config.srcYincrement = DMA_SPA_Descriptor_0_config.xCount;




	//First descriptor...
	Cy_DMA_Descriptor_Init(&DMA_SPA_Descriptor_0, &DMA_SPA_Descriptor_0_config);
	Cy_DMA_Descriptor_SetSrcAddress(&DMA_SPA_Descriptor_0, buffer->data);

	Cy_DMA_Descriptor_SetDstAddress(&DMA_SPA_Descriptor_0, (void*)(&SCB_TX_FIFO_WR(UART_SPA_HW)));

	//...then channel..
	Cy_DMA_Channel_Init(DMA_SPA_HW, DMA_SPA_CHANNEL, &DMA_SPA_channelConfig);
	Cy_DMA_Channel_SetDescriptor(DMA_SPA_HW, DMA_SPA_CHANNEL, &DMA_SPA_Descriptor_0);
	Cy_DMA_Channel_SetInterruptMask(DMA_SPA_HW, DMA_SPA_CHANNEL, CY_DMA_INTR_MASK);
	Cy_DMA_Channel_Enable(DMA_SPA_HW, DMA_SPA_CHANNEL);

//	//...then point ISR to handler...
	cy_stc_sysint_t interruptus;
	interruptus.intrSrc = DMA_SPA_IRQ;
	interruptus.intrPriority = 3;
	Cy_SysInt_Init(&interruptus, DMA_done);
	NVIC_ClearPendingIRQ(interruptus.intrSrc);
	NVIC_EnableIRQ(interruptus.intrSrc);

	//...finally enable DMA
	Cy_DMA_Enable(DMA_SPA_HW);
}
#endif

// Function to initialize the data buffer
void DataStream_init_buffer(DataStream_data_buffer_t *buffer)
{
    myBuffer = buffer;

	buffer->current_frame = 0;
    buffer->data_is_currently_being_written = false;
    for (int i = 0; i < DataStream_NUMBER_OF_FRAMES; i++)
    {
    	// Place frame separator in data buffer
    	//We only need to do it during init
    	buffer->data[i * (DataStream_NUMBER_OF_CHANNELS + 1)] = DataStream_START_SEQUENCE;

        // Prefill the frame with test data
        for (int j = 1; j < DataStream_NUMBER_OF_CHANNELS + 1; j++)
        {
            buffer->data[i * (DataStream_NUMBER_OF_CHANNELS + 1) + j] = 0;
        }
    }

#ifdef USE_DMA
    init_DMA(buffer);
#endif
}

// Function to write data to the data buffer
void DataStream_writeData(DataStream_data_buffer_t *buffer, uint32_t frame_number, uint32_t channel_number, channel_data_t data)
{
    if (buffer->data_is_currently_being_written)
        return;

    // Check if the frame index and channel index are within bounds
    if (frame_number < DataStream_NUMBER_OF_FRAMES && channel_number < DataStream_NUMBER_OF_CHANNELS)
    {
        // Calculate the offset for the channel data
        uint32_t offset = frame_number * (DataStream_NUMBER_OF_CHANNELS + 1);
        // Write the data to the buffer
        buffer->data[offset + 1] = data;
    }
}

// Function to add a frame to the data buffer
void DataStream_addFrame(DataStream_data_buffer_t *buffer, channel_data_t *channel_data) {
    if (buffer->data_is_currently_being_written)
        return;

    // Check if the current frame is within bounds
    if (buffer->current_frame < DataStream_NUMBER_OF_FRAMES)
    {
        // Calculate the offset for the frame data
        uint32_t offset = buffer->current_frame * (DataStream_NUMBER_OF_CHANNELS + 1);
        // Write the channel data to the buffer

        //memcpy(buffer->data[offset],channel_data,DataStream_CHANNEL_DATA_SIZE*DataStream_NUMBER_OF_CHANNELS);

        for (int i = 1; i < DataStream_NUMBER_OF_CHANNELS + 1; i++)
        {
        	buffer->data[offset + i] = channel_data[i-1];
        }

        // Increment the current frame
        buffer->current_frame++;
    }
}

// Function to write the data buffer to an output device

void DataStream_WriteBufferToOutput(DataStream_data_buffer_t *buffer)
{
    buffer->data_is_currently_being_written = true;

#ifdef USE_DMA
    Cy_DMA_Channel_Enable(DMA_SPA_HW, DMA_SPA_CHANNEL);

#else
    uint32_t buffer_length = sizeof(buffer->data);
    uint32_t dataSend = 0;

    while(buffer_length - dataSend > 0)
    	dataSend =  dataSend + Cy_SCB_UART_PutArray(SCB_number, (void *)(buffer->data +dataSend), buffer_length - dataSend);

    buffer->data_is_currently_being_written = false;
        buffer->current_frame = 0;
#endif


}
