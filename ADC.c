/*
 * ADC.c
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */

#include "ADC.h"
#include "cy_tcpwm.h"
#include "cy_tcpwm_counter.h"

#define fs_VoutIout (100000UL)	//100kHz sampling frequency
#define fs_Temp (1000UL)		//1kHz sampling frequency		


volatile ADC_config_t ADC_config;
const float a1 = -1.36f;
const float a2 =  0.686f;

const float b0 = 2.408f;
const float b1 = -1.364f;
const float b2 = -0.7222f;

float x2, x1, y2, y1;


static inline float calculateBiquadFilter(float x)
{
	float y;
    y = b0 * x + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y;
    return (y - x);
}

void ISR_VoutIoutEOC()
{
	IOUT =  Cy_HPPASS_SAR_Result_ChannelRead(0);
	VOUT = Cy_HPPASS_SAR_Result_ChannelRead(2);
	
	ADC_config.filter = calculateBiquadFilter(IOUT);
	
    uint32_t interrupts = Cy_TCPWM_GetInterruptStatusMasked(TIMER_ADC_VOUT_IOUT_HW, TIMER_ADC_VOUT_IOUT_NUM);
    Cy_TCPWM_ClearInterrupt(TIMER_ADC_VOUT_IOUT_HW, TIMER_ADC_VOUT_IOUT_NUM, interrupts);
	NVIC_ClearPendingIRQ(TIMER_ADC_VOUT_IOUT_IRQ);

}

void ISR_TempEOC()
{
	TEMP1 = Cy_HPPASS_SAR_Result_ChannelRead(5); 
	TEMP2 = Cy_HPPASS_SAR_Result_ChannelRead(9);
		
    uint32_t interrupts = Cy_TCPWM_GetInterruptStatusMasked(TIMER_ADC_TEMP_HW, TIMER_ADC_TEMP_NUM);
    Cy_TCPWM_ClearInterrupt(TIMER_ADC_TEMP_HW, TIMER_ADC_TEMP_NUM, interrupts);
	NVIC_ClearPendingIRQ(TIMER_ADC_TEMP_IRQ);
	
}

void ADC_init()
{
	Cy_HPPASS_Init(&pass_0_config);
	Cy_HPPASS_AC_Start(0, 500);
	Cy_HPPASS_SAR_Init(&pass_0_sar_0_config);
	Cy_HPPASS_SAR_SetTempSensorCurrent(false);
	
	Cy_TCPWM_Counter_Init(TIMER_ADC_VOUT_IOUT_HW, TIMER_ADC_VOUT_IOUT_NUM, &TIMER_ADC_VOUT_IOUT_config);
	Cy_TCPWM_Counter_Enable(TIMER_ADC_VOUT_IOUT_HW, TIMER_ADC_VOUT_IOUT_NUM);
	
	//Start trigger for fast sequencer (Vout / Iout)
	uint32_t period = (uint32_t)(180e6 / fs_VoutIout);	//fast clock, 180Mhz
	Cy_TCPWM_Counter_SetPeriod(TIMER_ADC_VOUT_IOUT_HW, TIMER_ADC_VOUT_IOUT_NUM, period);
	
	//For the moment we are not using DMA - it is planned eventually
	//Now we just use and ISR.
	cy_stc_sysint_t interruptus;
	interruptus.intrSrc = TIMER_ADC_VOUT_IOUT_IRQ; // @suppress("Field cannot be resolved")
	interruptus.intrPriority = 1; // @suppress("Field cannot be resolved")
	Cy_SysInt_Init(&interruptus, ISR_VoutIoutEOC);
	NVIC_ClearPendingIRQ(interruptus.intrSrc); // @suppress("Field cannot be resolved")
	NVIC_EnableIRQ(interruptus.intrSrc);
	
	Cy_TCPWM_TriggerStart_Single(TIMER_ADC_VOUT_IOUT_HW, TIMER_ADC_VOUT_IOUT_NUM);
	
	
	
	
	
	Cy_TCPWM_Counter_Init(TIMER_ADC_TEMP_HW, TIMER_ADC_TEMP_NUM, &TIMER_ADC_TEMP_config);
	Cy_TCPWM_Counter_Enable(TIMER_ADC_TEMP_HW, TIMER_ADC_TEMP_NUM);
		
	//Start trigger for slow sequencer (Temp1 / Temp2)
	period = (uint32_t)(18e6 / fs_Temp);
	Cy_TCPWM_Counter_SetPeriod(TIMER_ADC_VOUT_IOUT_HW, TIMER_ADC_VOUT_IOUT_NUM, period);

	//setup ISR for same reason as above
	interruptus.intrSrc = TIMER_ADC_TEMP_IRQ; // @suppress("Field cannot be resolved")
	interruptus.intrPriority = 2; // @suppress("Field cannot be resolved")
	Cy_SysInt_Init(&interruptus, ISR_TempEOC);
	NVIC_ClearPendingIRQ(interruptus.intrSrc); // @suppress("Field cannot be resolved")
	NVIC_EnableIRQ(interruptus.intrSrc);
	
	Cy_TCPWM_TriggerStart_Single(TIMER_ADC_TEMP_HW, TIMER_ADC_TEMP_NUM);
	
}