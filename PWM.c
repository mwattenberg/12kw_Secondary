/*
 * PWM.c
 *
 *  Created on: 29.09.2025
 *      Author: wattenberg
 */


#include "PWM.h"
#include "cy_tcpwm.h"
#include "cy_tcpwm_pwm.h"
#include "cycfg_peripherals.h"

#define PWM_FAN_FREQ 25000
#define PWM_CURRENT_SENSOR_DAC_FREQ (200000UL)

void PWM_initFan()
{
	Cy_TCPWM_PWM_Init(PWM_FAN_HW, PWM_FAN_NUM, &PWM_FAN_config);
	Cy_TCPWM_PWM_Enable(PWM_FAN_HW, PWM_FAN_NUM);
	
	uint32_t period = (int32_t)(18e6 / PWM_FAN_FREQ);
	Cy_TCPWM_PWM_SetPeriod0(PWM_FAN_HW, PWM_FAN_NUM, period);

	PWM_fanSetDuty(0.0f);
	
	Cy_TCPWM_TriggerStart_Single(PWM_FAN_HW, PWM_FAN_NUM);
	
}


void PWM_init_OCThreshold()
{
	Cy_TCPWM_PWM_Init(PWM_OC_THR_HW, PWM_OC_THR_NUM, &PWM_OC_THR_config);
	Cy_TCPWM_PWM_Enable(PWM_OC_THR_HW, PWM_OC_THR_NUM);
	
	uint32_t period = (int32_t)(180e6 / PWM_CURRENT_SENSOR_DAC_FREQ);
	Cy_TCPWM_PWM_SetPeriod0(PWM_OC_THR_HW, PWM_OC_THR_NUM, period);
	
	PWM_setOverCurrentThreshold(150.0f);

	Cy_TCPWM_TriggerStart_Single(PWM_OC_THR_HW, PWM_OC_THR_NUM);	
}




void PWM_fanSetDuty(float duty)
{
	uint32_t period = Cy_TCPWM_PWM_GetPeriod0(PWM_FAN_HW, PWM_FAN_NUM);
	uint32_t compare = duty * period;
	Cy_TCPWM_PWM_SetCompare0Val(PWM_FAN_HW, PWM_FAN_NUM, compare);
	//Cy_TCPWM_PWM_SetCompare0BufVal(PWM_FAN_HW, PWM_FAN_NUM, compare);
}

//Set the threshold in % from 20 to 180%
void PWM_setOverCurrentThreshold(float OverCurrentThreshold)
{
	if(OverCurrentThreshold < 20.0f)
		OverCurrentThreshold = 20.0f;
	else if(OverCurrentThreshold > 180.0f)
		OverCurrentThreshold = 180.0f;
	
	uint32_t period = Cy_TCPWM_PWM_GetPeriod0(PWM_OC_THR_HW, PWM_OC_THR_NUM); 
	uint32_t compare = period / (2); //First we have to find the sensitivity
	
	Cy_TCPWM_PWM_SetCompare0Val(PWM_OC_THR_HW, PWM_OC_THR_NUM, compare); 	
}