/*
 * _CONFIGURATION.h
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_


#define VOUT_CountsToVoltsGain 0.00691f
#define VOUT_CountsToVolts(counts)(counts * VOUT_CountsToVoltsGain)
#define VOUT_VoltsToCountsGain (1/VOUT_CountsToVoltsGain)
#define VOUT_VoltsToCounts(volts)(volts * VOUT_VoltsToCountsGain)

#define IOUT_CountsToVoltsGain 0.00691f
#define IOUT_CountsToVolts(counts)(counts * IOUT_CountsToVoltsGain)
#define IOUT_VoltsToCountsGain (1/IOUT_CountsToVoltsGain)
#define IOUT_VoltsToCounts(volts)(volts * IOUT_VoltsToCountsGain)


#define I_INTERLOCK_AmpsToCountsGain (3723)
#define I_INTERLOCK_AmpsToCounts(amps)(amps * I_INTERLOCK_AmpsToCountsGain)
#define I_INTERLOCK_CountsToAmpsGain (1.0f/I_INTERLOCK_AmpsToCountsGain)
#define I_INTERLOCK_CountsToAmps(counts)(counts * I_INTERLOCK_CountsToAmpsGain)

#define VIN_CountsToVoltsGain (0.4029f)
#define VIN_CountsToVolts(counts)(counts * VIN_CountsToVoltsGain)
#define VIN_VoltsToCountsGain (1/VIN_CountsToVoltsGain)
#define VIN_VoltsToCounts(volts)(volts * VIN_VoltsToCountsGain)


#endif /* CONFIGURATION_H_ */
