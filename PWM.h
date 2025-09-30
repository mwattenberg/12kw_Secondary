/*
 * PWM.h
 *
 *  Created on: 18.09.2025
 *      Author: wattenberg
 */

#ifndef PWM_H_
#define PWM_H_

#include "cybsp.h"

#define OVERCURRENT_TO_DUTY(oc_threshold) (oc_threshold * 0.001f)

void PWM_init_OCThreshold();
void PWM_initFan();

void PWM_fanSetDuty(float duty);
void PWM_setOverCurrentThreshold(float OC_threshold);

#endif /* PWM_H_ */
