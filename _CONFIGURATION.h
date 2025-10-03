/*
 * _CONFIGURATION.h
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_


#define VOUT_CountsToVoltsGain 			(0.02038f)
#define VOUT_CountsToVolts(counts) 		((counts) * VOUT_CountsToVoltsGain)
#define VOUT_VoltsToCountsGain 			(1/VOUT_CountsToVoltsGain)
#define VOUT_VoltsToCounts(volts)		((volts) * VOUT_VoltsToCountsGain)

#define IOUT_Offset						(2046)
#define IOUT_CountsToAmpsGain 			(0.3846f)
#define IOUT_CountsToAmps(counts)		((counts - IOUT_Offset) * IOUT_CountsToAmpsGain)
#define IOUT_AmpsToCountsGain 			(1/IOUT_CountsToVoltsGain)
#define IOUT_AmpsToCounts(amps)			((amps) * IOUT_VoltsToCountsGain + IOUT_Offset)


#define TEMP_CelsiusOffset				(-20.5f)	//Vout = 0V at this value
#define TEMP_CountsToCelsiusGain 		(0.0413f)			
#define TEMP_CountsToCelsius(counts)	((counts) * TEMP_CountsToCelsiusGain + TEMP_CelsiusOffset)
#define TEMP_CelsiusToCountsGain 		(1/TEMP_CountsToCelsiusGain)
#define TEMP_CelsiusToCounts(celsius)	((celsius) * TEMP_CelsiusToCountsGain + TEMP_CelsiusOffset/TEMP_CelsiusToCountsGain)



#endif /* CONFIGURATION_H_ */
