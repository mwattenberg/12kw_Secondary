/*******************************************************************************
 * File Name: cycfg_pins.h
 *
 * Description:
 * Pin configuration
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.60.0
 * device-db 4.29.0.9102
 * mtb-pdl-cat1 3.16.0.40964
 *
 *******************************************************************************
 * Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined (CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define SWCLK_ENABLED 1U
#define SWCLK_PORT GPIO_PRT1
#define SWCLK_PORT_NUM 1U
#define SWCLK_PIN 2U
#define SWCLK_NUM 2U
#define SWCLK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define SWCLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_2_HSIOM
    #define ioss_0_port_1_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define SWCLK_HSIOM ioss_0_port_1_pin_2_HSIOM
#define SWCLK_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define SWCLK_HAL_PORT_PIN P1_2
#define SWCLK P1_2
#define SWCLK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define SWCLK_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define SWCLK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLDOWN
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define SWDIO_ENABLED 1U
#define SWDIO_PORT GPIO_PRT1
#define SWDIO_PORT_NUM 1U
#define SWDIO_PIN 3U
#define SWDIO_NUM 3U
#define SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_1_pin_3_HSIOM
    #define ioss_0_port_1_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define SWDIO_HSIOM ioss_0_port_1_pin_3_HSIOM
#define SWDIO_IRQ ioss_interrupts_sec_gpio_1_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define SWDIO_HAL_PORT_PIN P1_3
#define SWDIO P1_3
#define SWDIO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define SWDIO_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define SWDIO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_PULLUP
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_SPI_SS_ENABLED 1U
#define PIN_SPI_SS_PORT GPIO_PRT2
#define PIN_SPI_SS_PORT_NUM 2U
#define PIN_SPI_SS_PIN 0U
#define PIN_SPI_SS_NUM 0U
#define PIN_SPI_SS_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PIN_SPI_SS_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_0_HSIOM
    #define ioss_0_port_2_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_SPI_SS_HSIOM ioss_0_port_2_pin_0_HSIOM
#define PIN_SPI_SS_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_SPI_SS_HAL_PORT_PIN P2_0
#define PIN_SPI_SS P2_0
#define PIN_SPI_SS_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_SPI_SS_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PIN_SPI_SS_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_SPI_CLK_ENABLED 1U
#define PIN_SPI_CLK_PORT GPIO_PRT2
#define PIN_SPI_CLK_PORT_NUM 2U
#define PIN_SPI_CLK_PIN 1U
#define PIN_SPI_CLK_NUM 1U
#define PIN_SPI_CLK_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PIN_SPI_CLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_1_HSIOM
    #define ioss_0_port_2_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_SPI_CLK_HSIOM ioss_0_port_2_pin_1_HSIOM
#define PIN_SPI_CLK_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_SPI_CLK_HAL_PORT_PIN P2_1
#define PIN_SPI_CLK P2_1
#define PIN_SPI_CLK_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_SPI_CLK_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PIN_SPI_CLK_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_SPI_MOSI_ENABLED 1U
#define PIN_SPI_MOSI_PORT GPIO_PRT2
#define PIN_SPI_MOSI_PORT_NUM 2U
#define PIN_SPI_MOSI_PIN 2U
#define PIN_SPI_MOSI_NUM 2U
#define PIN_SPI_MOSI_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PIN_SPI_MOSI_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_2_HSIOM
    #define ioss_0_port_2_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_SPI_MOSI_HSIOM ioss_0_port_2_pin_2_HSIOM
#define PIN_SPI_MOSI_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_SPI_MOSI_HAL_PORT_PIN P2_2
#define PIN_SPI_MOSI P2_2
#define PIN_SPI_MOSI_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_SPI_MOSI_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PIN_SPI_MOSI_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_SPI_MISO_ENABLED 1U
#define PIN_SPI_MISO_PORT GPIO_PRT2
#define PIN_SPI_MISO_PORT_NUM 2U
#define PIN_SPI_MISO_PIN 3U
#define PIN_SPI_MISO_NUM 3U
#define PIN_SPI_MISO_DRIVEMODE CY_GPIO_DM_HIGHZ
#define PIN_SPI_MISO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_2_pin_3_HSIOM
    #define ioss_0_port_2_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_SPI_MISO_HSIOM ioss_0_port_2_pin_3_HSIOM
#define PIN_SPI_MISO_IRQ ioss_interrupts_sec_gpio_2_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_SPI_MISO_HAL_PORT_PIN P2_3
#define PIN_SPI_MISO P2_3
#define PIN_SPI_MISO_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_SPI_MISO_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define PIN_SPI_MISO_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_EN_OUTPUT_ENABLED 1U
#define PIN_EN_OUTPUT_PORT GPIO_PRT4
#define PIN_EN_OUTPUT_PORT_NUM 4U
#define PIN_EN_OUTPUT_PIN 0U
#define PIN_EN_OUTPUT_NUM 0U
#define PIN_EN_OUTPUT_DRIVEMODE CY_GPIO_DM_STRONG
#define PIN_EN_OUTPUT_INIT_DRIVESTATE 0
#ifndef ioss_0_port_4_pin_0_HSIOM
    #define ioss_0_port_4_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_EN_OUTPUT_HSIOM ioss_0_port_4_pin_0_HSIOM
#define PIN_EN_OUTPUT_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_EN_OUTPUT_HAL_PORT_PIN P4_0
#define PIN_EN_OUTPUT P4_0
#define PIN_EN_OUTPUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_EN_OUTPUT_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define PIN_EN_OUTPUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_DIS_OUTPUT_ENABLED 1U
#define PIN_DIS_OUTPUT_PORT GPIO_PRT4
#define PIN_DIS_OUTPUT_PORT_NUM 4U
#define PIN_DIS_OUTPUT_PIN 1U
#define PIN_DIS_OUTPUT_NUM 1U
#define PIN_DIS_OUTPUT_DRIVEMODE CY_GPIO_DM_STRONG
#define PIN_DIS_OUTPUT_INIT_DRIVESTATE 1
#ifndef ioss_0_port_4_pin_1_HSIOM
    #define ioss_0_port_4_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_DIS_OUTPUT_HSIOM ioss_0_port_4_pin_1_HSIOM
#define PIN_DIS_OUTPUT_IRQ ioss_interrupts_sec_gpio_4_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_DIS_OUTPUT_HAL_PORT_PIN P4_1
#define PIN_DIS_OUTPUT P4_1
#define PIN_DIS_OUTPUT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_DIS_OUTPUT_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define PIN_DIS_OUTPUT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_DAC_OC_THR_ENABLED 1U
#define PIN_DAC_OC_THR_PORT GPIO_PRT6
#define PIN_DAC_OC_THR_PORT_NUM 6U
#define PIN_DAC_OC_THR_PIN 0U
#define PIN_DAC_OC_THR_NUM 0U
#define PIN_DAC_OC_THR_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PIN_DAC_OC_THR_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_0_HSIOM
    #define ioss_0_port_6_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_DAC_OC_THR_HSIOM ioss_0_port_6_pin_0_HSIOM
#define PIN_DAC_OC_THR_IRQ ioss_interrupts_sec_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_DAC_OC_THR_HAL_PORT_PIN P6_0
#define PIN_DAC_OC_THR P6_0
#define PIN_DAC_OC_THR_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_DAC_OC_THR_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PIN_DAC_OC_THR_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define OCD_ENABLED 1U
#define OCD_PORT GPIO_PRT6
#define OCD_PORT_NUM 6U
#define OCD_PIN 2U
#define OCD_NUM 2U
#define OCD_DRIVEMODE CY_GPIO_DM_HIGHZ
#define OCD_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_2_HSIOM
    #define ioss_0_port_6_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define OCD_HSIOM ioss_0_port_6_pin_2_HSIOM
#define OCD_IRQ ioss_interrupts_sec_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define OCD_HAL_PORT_PIN P6_2
#define OCD P6_2
#define OCD_HAL_IRQ CYHAL_GPIO_IRQ_FALL
#define OCD_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define OCD_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_FLT_CS_ENABLED 1U
#define PIN_FLT_CS_PORT GPIO_PRT6
#define PIN_FLT_CS_PORT_NUM 6U
#define PIN_FLT_CS_PIN 3U
#define PIN_FLT_CS_NUM 3U
#define PIN_FLT_CS_DRIVEMODE CY_GPIO_DM_HIGHZ
#define PIN_FLT_CS_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_3_HSIOM
    #define ioss_0_port_6_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_FLT_CS_HSIOM ioss_0_port_6_pin_3_HSIOM
#define PIN_FLT_CS_IRQ ioss_interrupts_sec_gpio_6_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_FLT_CS_HAL_PORT_PIN P6_3
#define PIN_FLT_CS P6_3
#define PIN_FLT_CS_HAL_IRQ CYHAL_GPIO_IRQ_FALL
#define PIN_FLT_CS_HAL_DIR CYHAL_GPIO_DIR_INPUT 
#define PIN_FLT_CS_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_NONE
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_SCL_ENABLED 1U
#define PIN_SCL_PORT GPIO_PRT7
#define PIN_SCL_PORT_NUM 7U
#define PIN_SCL_PIN 0U
#define PIN_SCL_NUM 0U
#define PIN_SCL_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define PIN_SCL_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_0_HSIOM
    #define ioss_0_port_7_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_SCL_HSIOM ioss_0_port_7_pin_0_HSIOM
#define PIN_SCL_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_SCL_HAL_PORT_PIN P7_0
#define PIN_SCL P7_0
#define PIN_SCL_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_SCL_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define PIN_SCL_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_OPENDRAINDRIVESLOW
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_SDA_ENABLED 1U
#define PIN_SDA_PORT GPIO_PRT7
#define PIN_SDA_PORT_NUM 7U
#define PIN_SDA_PIN 1U
#define PIN_SDA_NUM 1U
#define PIN_SDA_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PIN_SDA_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_1_HSIOM
    #define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_SDA_HSIOM ioss_0_port_7_pin_1_HSIOM
#define PIN_SDA_IRQ ioss_interrupts_sec_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_SDA_HAL_PORT_PIN P7_1
#define PIN_SDA P7_1
#define PIN_SDA_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_SDA_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PIN_SDA_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_AC_LOSS_ENABLED 1U
#define PIN_AC_LOSS_PORT GPIO_PRT7
#define PIN_AC_LOSS_PORT_NUM 7U
#define PIN_AC_LOSS_PIN 2U
#define PIN_AC_LOSS_NUM 2U
#define PIN_AC_LOSS_DRIVEMODE CY_GPIO_DM_STRONG
#define PIN_AC_LOSS_INIT_DRIVESTATE 0
#ifndef ioss_0_port_7_pin_2_HSIOM
    #define ioss_0_port_7_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_AC_LOSS_HSIOM ioss_0_port_7_pin_2_HSIOM
#define PIN_AC_LOSS_IRQ ioss_interrupts_gpio_7_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_AC_LOSS_HAL_PORT_PIN P7_2
#define PIN_AC_LOSS P7_2
#define PIN_AC_LOSS_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_AC_LOSS_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define PIN_AC_LOSS_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_LED_FAULT_ENABLED 1U
#define PIN_LED_FAULT_PORT GPIO_PRT8
#define PIN_LED_FAULT_PORT_NUM 8U
#define PIN_LED_FAULT_PIN 0U
#define PIN_LED_FAULT_NUM 0U
#define PIN_LED_FAULT_DRIVEMODE CY_GPIO_DM_STRONG
#define PIN_LED_FAULT_INIT_DRIVESTATE 0
#ifndef ioss_0_port_8_pin_0_HSIOM
    #define ioss_0_port_8_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_LED_FAULT_HSIOM ioss_0_port_8_pin_0_HSIOM
#define PIN_LED_FAULT_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_LED_FAULT_HAL_PORT_PIN P8_0
#define PIN_LED_FAULT P8_0
#define PIN_LED_FAULT_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_LED_FAULT_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define PIN_LED_FAULT_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_PWM_FAN_ENABLED 1U
#define PIN_PWM_FAN_PORT GPIO_PRT8
#define PIN_PWM_FAN_PORT_NUM 8U
#define PIN_PWM_FAN_PIN 1U
#define PIN_PWM_FAN_NUM 1U
#define PIN_PWM_FAN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PIN_PWM_FAN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_1_HSIOM
    #define ioss_0_port_8_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_PWM_FAN_HSIOM ioss_0_port_8_pin_1_HSIOM
#define PIN_PWM_FAN_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_PWM_FAN_HAL_PORT_PIN P8_1
#define PIN_PWM_FAN P8_1
#define PIN_PWM_FAN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_PWM_FAN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PIN_PWM_FAN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_DISABLE_FAN_ENABLED 1U
#define PIN_DISABLE_FAN_PORT GPIO_PRT8
#define PIN_DISABLE_FAN_PORT_NUM 8U
#define PIN_DISABLE_FAN_PIN 2U
#define PIN_DISABLE_FAN_NUM 2U
#define PIN_DISABLE_FAN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PIN_DISABLE_FAN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_8_pin_2_HSIOM
    #define ioss_0_port_8_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_DISABLE_FAN_HSIOM ioss_0_port_8_pin_2_HSIOM
#define PIN_DISABLE_FAN_IRQ ioss_interrupts_sec_gpio_8_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_DISABLE_FAN_HAL_PORT_PIN P8_2
#define PIN_DISABLE_FAN P8_2
#define PIN_DISABLE_FAN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_DISABLE_FAN_HAL_DIR CYHAL_GPIO_DIR_OUTPUT 
#define PIN_DISABLE_FAN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

#define PIN_LED_RUN_ENABLED 1U
#define PIN_LED_RUN_PORT GPIO_PRT9
#define PIN_LED_RUN_PORT_NUM 9U
#define PIN_LED_RUN_PIN 0U
#define PIN_LED_RUN_NUM 0U
#define PIN_LED_RUN_DRIVEMODE CY_GPIO_DM_STRONG
#define PIN_LED_RUN_INIT_DRIVESTATE 0
#ifndef ioss_0_port_9_pin_0_HSIOM
    #define ioss_0_port_9_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define PIN_LED_RUN_HSIOM ioss_0_port_9_pin_0_HSIOM
#define PIN_LED_RUN_IRQ ioss_interrupts_sec_gpio_9_IRQn

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
#define PIN_LED_RUN_HAL_PORT_PIN P9_0
#define PIN_LED_RUN P9_0
#define PIN_LED_RUN_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define PIN_LED_RUN_HAL_DIR CYHAL_GPIO_DIR_BIDIRECTIONAL 
#define PIN_LED_RUN_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t SWCLK_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SWCLK_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t SWDIO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t SWDIO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_SPI_SS_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_SPI_SS_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_SPI_CLK_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_SPI_CLK_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_SPI_MOSI_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_SPI_MOSI_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_SPI_MISO_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_SPI_MISO_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_EN_OUTPUT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_EN_OUTPUT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_DIS_OUTPUT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_DIS_OUTPUT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_DAC_OC_THR_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_DAC_OC_THR_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t OCD_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t OCD_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_FLT_CS_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_FLT_CS_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_SCL_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_SCL_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_SDA_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_SDA_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_AC_LOSS_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_AC_LOSS_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_LED_FAULT_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_LED_FAULT_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_PWM_FAN_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_PWM_FAN_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_DISABLE_FAN_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_DISABLE_FAN_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

extern const cy_stc_gpio_pin_config_t PIN_LED_RUN_config;

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
extern const cyhal_resource_inst_t PIN_LED_RUN_obj;
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void);
void reserve_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_PINS_H */
