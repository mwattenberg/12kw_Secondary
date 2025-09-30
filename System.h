/*
 * System.h
 *
 *  Created on: 18.09.2025
 *      Author: wattenberg
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "cybsp.h"


typedef enum {
	STATE_INIT = 0,
	STATE_CHECK_VOUT = 1,
	STATE_CHECK_FAN = 2,
	STATE_ENABLE_LINEAR_FET = 4,
	STATE_ENABLE_ORING = 5,
	STATE_RUN = 10,
		
	//Error states
	STATE_AC_LOSS = 97,
	STATE_OTP = 98,
	STATE_OCP = 99,
	STATE_ERROR = 100
} SystemState_t;


void System_init();
void System_UpdateStateMachine();


#endif /* SYSTEM_H_ */
