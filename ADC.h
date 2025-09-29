/*
 * ADC.h
 *
 *  Created on: 18.09.2025
 *      Author: wattenberg
 */

#ifndef ADC_H_
#define ADC_H_

#include "cybsp.h"

#define IOUT (ADC_config.results[0])
#define VOUT (ADC_config.results[1])
#define TEMP1 (ADC_config.results[3])
#define TEMP2 (ADC_config.results[4])


typedef volatile struct ADC_config_t
{
	uint16_t results[4];


} ADC_config_t;

extern ADC_config_t ADC_config;

void ADC_init();



#endif /* ADC_H_ */
