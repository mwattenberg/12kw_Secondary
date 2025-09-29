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
void PWM_init_Fan();

void PWM_setFanDuty(float duty);
void PWM_setOverCurrentDuty(float OC_threshold);

#endif /* PWM_H_ */
