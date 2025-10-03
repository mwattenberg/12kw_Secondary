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

#define PWM_FAN_FREQ (25000UL)
#define PWM_CURRENT_SENSOR_DAC_FREQ (200000UL)
#define V_PWM         3.300f      // V     (stable, non-ratiometric)
#define THR_MIN_V     0.432f      // 20% FS
#define THR_MAX_V     3.890f      // 180% FS
#define S_mV_per_mT   90.0f     // AE24
#define TF_uT_per_A   26.7f   //

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
	
	PWM_setOverCurrentThreshold(180.0f);

	Cy_TCPWM_TriggerStart_Single(PWM_OC_THR_HW, PWM_OC_THR_NUM);	
}




void PWM_fanSetDuty(float duty)
{
	uint32_t period = Cy_TCPWM_PWM_GetPeriod0(PWM_FAN_HW, PWM_FAN_NUM);
	uint32_t compare = duty * period;
	Cy_TCPWM_PWM_SetCompare0Val(PWM_FAN_HW, PWM_FAN_NUM, compare);
	//Cy_TCPWM_PWM_SetCompare0BufVal(PWM_FAN_HW, PWM_FAN_NUM, compare);
}
/*
//Set the threshold in % from 20 to 180%
void PWM_setOverCurrentThreshold(float OverCurrentThreshold)
{
	if(OverCurrentThreshold < 20.0f)
		OverCurrentThreshold = 20.0f;
	else if(OverCurrentThreshold > 180.0f)
		OverCurrentThreshold = 180.0f;
	
	    // Map 20..180 %FS -> 0.432..3.89 V
    float Vthr = THR_MIN_V + (OverCurrentThreshold - 20.0f) * (THR_MAX_V - THR_MIN_V) / (180.0f - 20.0f);
    
	uint32_t period = Cy_TCPWM_PWM_GetPeriod0(PWM_OC_THR_HW, PWM_OC_THR_NUM); 
	float duty = Vthr / V_PWM;
	if (duty < 0.0f) duty = 0.0f; else if (duty > 1.0f) duty = 1.0f;
	uint32_t compare = (uint32_t)(duty * (float)period);
	
	Cy_TCPWM_PWM_SetCompare0Val(PWM_OC_THR_HW, PWM_OC_THR_NUM, compare); 	
}
// Returns duty (0..1)
*/

void PWM_setOverCurrentThreshold(float OverCurrentThreshold)   // in amps
{
    // 1) Convert current to threshold voltage
    float Vthr = (OverCurrentThreshold * S_mV_per_mT * TF_uT_per_A) / 1e6f;

    // 2) Clamp to allowed THR window
    if (Vthr < THR_MIN_V) 
        Vthr = THR_MIN_V;
    else if (Vthr > THR_MAX_V) 
        Vthr = THR_MAX_V;

    // 3) Compute PWM duty from clamped voltage
    float duty = Vthr / V_PWM;
    if (duty < 0.0f) duty = 0.0f;
    else if (duty > 1.0f) duty = 1.0f;

    // 4) Convert to compare value
    uint32_t period  = Cy_TCPWM_PWM_GetPeriod0(PWM_OC_THR_HW, PWM_OC_THR_NUM);
    uint32_t compare = (uint32_t)(duty * period + 0.5f); // round to nearest count

    // 6) Apply to PWM
    Cy_TCPWM_PWM_SetCompare0Val(PWM_OC_THR_HW, PWM_OC_THR_NUM, compare);
}