/*******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the Empty Application Example
*              for ModusToolbox.
*
* Related Document: See README.md
*
*******************************************************************************
* Copyright 2024-2025, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/


/*******************************************************************************
* Header Files
*******************************************************************************/
#include <stdint.h>
#include "PWM.h"
#include "cybsp.h"
#include "ADC.h"
#include "SPI.h"
#include "System.h"


/*******************************************************************************
* Macros
*******************************************************************************/

#define PWM_STEPS 100
#define PWM_PERIOD_US 2000  // Total period in microseconds

/*******************************************************************************
* Global Variables
*******************************************************************************/


/*******************************************************************************
* Function Prototypes
*******************************************************************************/

void pulsate_led(void)
{
        // Fade in
        for (int i = 0; i < PWM_STEPS; i++) {
            Cy_GPIO_Set(PIN_LED_RUN_PORT, PIN_LED_RUN_NUM);
            Cy_SysLib_DelayUs(i * (PWM_PERIOD_US / PWM_STEPS));
            Cy_GPIO_Clr(PIN_LED_RUN_PORT, PIN_LED_RUN_NUM);
            Cy_SysLib_DelayUs((PWM_STEPS - i) * (PWM_PERIOD_US / PWM_STEPS));
        }
        // Fade out
        for (int i = PWM_STEPS; i > 0; i--) {
            Cy_GPIO_Set(PIN_LED_RUN_PORT, PIN_LED_RUN_NUM);
            Cy_SysLib_DelayUs(i * (PWM_PERIOD_US / PWM_STEPS));
            Cy_GPIO_Clr(PIN_LED_RUN_PORT, PIN_LED_RUN_NUM);
            Cy_SysLib_DelayUs((PWM_STEPS - i) * (PWM_PERIOD_US / PWM_STEPS));
        }
}


/*******************************************************************************
* Function Definitions
*******************************************************************************/

void init()
{
	Cy_GPIO_Set(PIN_LED_RUN_PORT, PIN_LED_RUN_NUM);
	Cy_GPIO_Clr(PIN_LED_FAULT_PORT, PIN_LED_FAULT_NUM);


	Cy_GPIO_Set(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_NUM);
	Cy_GPIO_Clr(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_NUM);
	
	ADC_init();
	SPI_init();
	System_init();
	PWM_initFan();
	PWM_init_OCThreshold();
	
	//PWM_fanSetDuty(0.25f);
	
}

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
* This is the main function for CPU. It...
*    1.
*    2.6
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
   result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
    __enable_irq();

    init();

	

    for (;;)
    {
    	pulsate_led();
    
//    	Cy_GPIO_Inv(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_NUM);
//    	Cy_GPIO_Inv(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_NUM);
    }
}

/* [] END OF FILE */
