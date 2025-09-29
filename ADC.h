/*
 * ADC.h
 *
 *  Created on: 18.09.2025
 *      Author: wattenberg
 */

#ifndef ADC_H_
#define ADC_H_

#include "cybsp.h"

#define TEMP_1 (ADC_config.results[0])
#define TEMP_2 (ADC_config.results[1])
#define VOUT (ADC_config.results[2])
#define IOUT (ADC_config.results[3])

#define TEMP_CountsToCelsiusGain 0.062f
#define TEMP_CountsToCelsiusOffset -28
#define TEMP_CountsToCelsius(counts) (counts * TEMP_CountsToCelsiusGain + TEMP_CountsToCelsiusOffset)
#define TEMP_CelsiusToCountsGain (1/TEMP_CountsToCelsiusGain)
#define TEMP_CelsiusToCountsOffset (-TEMP_CountsToCelsiusOffset)
#define TEMP_CelsiusToCounts(n) (n * TEMP_CelsiusToCountsGain + TEMP_CelsiusToCountsGain)

#define VOUT_CountsToVoltsGain 0.145f
#define VOUT_CountsToVolts(counts) (counts*VOUT_CountsToVoltsGain)
#define VOUT_VoltToCountsGain 1/VOUT_CountsToVoltsGain
#define VOUT_VoltsToCounts(volt)(volt * VOUT_VoltToCountsGain)

#define IOUT_CountsToAmpsGain 0.0136f
#define IOUT_CountsToAmpsOffset -27.7f
#define IOUT_CountsToAmps(n) (n*IOUT_CountsToAmpsGain + IOUT_CountsToAmpsOffset)
#define IOUT_AmpsToCountsGain 1/IOUT_CountsToAmpsGain
#define IOUT_AmpsToCountsOffset (-IOUT_CountsToAmpsOffset)
#define IOUT_AmpsToCounts(amps)((amps + IOUT_AmpsToCountsOffset) * IOUT_AmpsToCountsGain)


typedef struct ADC_config_t
{
	uint16_t results[4];


} ADC_config_t;



void ADC_init();



#endif /* ADC_H_ */
