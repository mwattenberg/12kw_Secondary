/*******************************************************************************
 * File Name: cycfg_pins.c
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

#include "cycfg_pins.h"

const cy_stc_gpio_pin_config_t SWCLK_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLDOWN,
    .hsiom = SWCLK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t SWCLK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = SWCLK_PORT_NUM,
    .channel_num = SWCLK_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t SWDIO_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_PULLUP,
    .hsiom = SWDIO_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t SWDIO_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = SWDIO_PORT_NUM,
    .channel_num = SWDIO_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_SPI_SS_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PIN_SPI_SS_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_SPI_SS_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_SPI_SS_PORT_NUM,
    .channel_num = PIN_SPI_SS_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_SPI_CLK_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PIN_SPI_CLK_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_SPI_CLK_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_SPI_CLK_PORT_NUM,
    .channel_num = PIN_SPI_CLK_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_SPI_MOSI_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PIN_SPI_MOSI_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_SPI_MOSI_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_SPI_MOSI_PORT_NUM,
    .channel_num = PIN_SPI_MOSI_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_SPI_MISO_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = PIN_SPI_MISO_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_SPI_MISO_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_SPI_MISO_PORT_NUM,
    .channel_num = PIN_SPI_MISO_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_EN_OUTPUT_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = PIN_EN_OUTPUT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_EN_OUTPUT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_EN_OUTPUT_PORT_NUM,
    .channel_num = PIN_EN_OUTPUT_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_DIS_OUTPUT_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = PIN_DIS_OUTPUT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_DIS_OUTPUT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_DIS_OUTPUT_PORT_NUM,
    .channel_num = PIN_DIS_OUTPUT_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_DAC_OC_THR_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PIN_DAC_OC_THR_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_DAC_OC_THR_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_DAC_OC_THR_PORT_NUM,
    .channel_num = PIN_DAC_OC_THR_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t OCD_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = OCD_HSIOM,
    .intEdge = CY_GPIO_INTR_FALLING,
    .intMask = 1UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t OCD_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = OCD_PORT_NUM,
    .channel_num = OCD_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_FLT_CS_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_HIGHZ,
    .hsiom = PIN_FLT_CS_HSIOM,
    .intEdge = CY_GPIO_INTR_FALLING,
    .intMask = 1UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_FLT_CS_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_FLT_CS_PORT_NUM,
    .channel_num = PIN_FLT_CS_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_SCL_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_OD_DRIVESLOW,
    .hsiom = PIN_SCL_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_SCL_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_SCL_PORT_NUM,
    .channel_num = PIN_SCL_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_SDA_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PIN_SDA_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_SDA_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_SDA_PORT_NUM,
    .channel_num = PIN_SDA_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_AC_LOSS_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = PIN_AC_LOSS_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 1,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_AC_LOSS_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_AC_LOSS_PORT_NUM,
    .channel_num = PIN_AC_LOSS_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_LED_FAULT_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = PIN_LED_FAULT_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_LED_FAULT_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_LED_FAULT_PORT_NUM,
    .channel_num = PIN_LED_FAULT_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_PWM_FAN_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PIN_PWM_FAN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_PWM_FAN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_PWM_FAN_PORT_NUM,
    .channel_num = PIN_PWM_FAN_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_DISABLE_FAN_config =
{
    .outVal = 1,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = PIN_DISABLE_FAN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_DISABLE_FAN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_DISABLE_FAN_PORT_NUM,
    .channel_num = PIN_DISABLE_FAN_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

const cy_stc_gpio_pin_config_t PIN_LED_RUN_config =
{
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG,
    .hsiom = PIN_LED_RUN_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
    .nonSec = 0,
};

#if defined (CY_USING_HAL) || (CY_USING_HAL_LITE)
const cyhal_resource_inst_t PIN_LED_RUN_obj =
{
    .type = CYHAL_RSC_GPIO,
    .block_num = PIN_LED_RUN_PORT_NUM,
    .channel_num = PIN_LED_RUN_PIN,
};
#endif /* defined (CY_USING_HAL) || (CY_USING_HAL_LITE) */

void init_cycfg_pins(void)
{
    Cy_GPIO_Pin_Init(SWCLK_PORT, SWCLK_PIN, &SWCLK_config);
    Cy_GPIO_Pin_Init(SWDIO_PORT, SWDIO_PIN, &SWDIO_config);
    Cy_GPIO_Pin_Init(PIN_SPI_SS_PORT, PIN_SPI_SS_PIN, &PIN_SPI_SS_config);
    Cy_GPIO_Pin_Init(PIN_SPI_CLK_PORT, PIN_SPI_CLK_PIN, &PIN_SPI_CLK_config);
    Cy_GPIO_Pin_Init(PIN_SPI_MOSI_PORT, PIN_SPI_MOSI_PIN, &PIN_SPI_MOSI_config);
    Cy_GPIO_Pin_Init(PIN_SPI_MISO_PORT, PIN_SPI_MISO_PIN, &PIN_SPI_MISO_config);
    Cy_GPIO_Pin_Init(PIN_EN_OUTPUT_PORT, PIN_EN_OUTPUT_PIN, &PIN_EN_OUTPUT_config);
    Cy_GPIO_Pin_Init(PIN_DIS_OUTPUT_PORT, PIN_DIS_OUTPUT_PIN, &PIN_DIS_OUTPUT_config);
    Cy_GPIO_Pin_Init(PIN_DAC_OC_THR_PORT, PIN_DAC_OC_THR_PIN, &PIN_DAC_OC_THR_config);
    Cy_GPIO_Pin_Init(OCD_PORT, OCD_PIN, &OCD_config);
    Cy_GPIO_Pin_Init(PIN_FLT_CS_PORT, PIN_FLT_CS_PIN, &PIN_FLT_CS_config);
    Cy_GPIO_Pin_Init(PIN_SCL_PORT, PIN_SCL_PIN, &PIN_SCL_config);
    Cy_GPIO_Pin_Init(PIN_SDA_PORT, PIN_SDA_PIN, &PIN_SDA_config);
    Cy_GPIO_Pin_Init(PIN_AC_LOSS_PORT, PIN_AC_LOSS_PIN, &PIN_AC_LOSS_config);
    Cy_GPIO_Pin_Init(PIN_LED_FAULT_PORT, PIN_LED_FAULT_PIN, &PIN_LED_FAULT_config);
    Cy_GPIO_Pin_Init(PIN_PWM_FAN_PORT, PIN_PWM_FAN_PIN, &PIN_PWM_FAN_config);
    Cy_GPIO_Pin_Init(PIN_DISABLE_FAN_PORT, PIN_DISABLE_FAN_PIN, &PIN_DISABLE_FAN_config);
    Cy_GPIO_Pin_Init(PIN_LED_RUN_PORT, PIN_LED_RUN_PIN, &PIN_LED_RUN_config);
}
void reserve_cycfg_pins(void)
{
#if defined (CY_USING_HAL)
    cyhal_hwmgr_reserve(&SWCLK_obj);
    cyhal_hwmgr_reserve(&SWDIO_obj);
    cyhal_hwmgr_reserve(&PIN_SPI_SS_obj);
    cyhal_hwmgr_reserve(&PIN_SPI_CLK_obj);
    cyhal_hwmgr_reserve(&PIN_SPI_MOSI_obj);
    cyhal_hwmgr_reserve(&PIN_SPI_MISO_obj);
    cyhal_hwmgr_reserve(&PIN_EN_OUTPUT_obj);
    cyhal_hwmgr_reserve(&PIN_DIS_OUTPUT_obj);
    cyhal_hwmgr_reserve(&PIN_DAC_OC_THR_obj);
    cyhal_hwmgr_reserve(&OCD_obj);
    cyhal_hwmgr_reserve(&PIN_FLT_CS_obj);
    cyhal_hwmgr_reserve(&PIN_SCL_obj);
    cyhal_hwmgr_reserve(&PIN_SDA_obj);
    cyhal_hwmgr_reserve(&PIN_AC_LOSS_obj);
    cyhal_hwmgr_reserve(&PIN_LED_FAULT_obj);
    cyhal_hwmgr_reserve(&PIN_PWM_FAN_obj);
    cyhal_hwmgr_reserve(&PIN_DISABLE_FAN_obj);
    cyhal_hwmgr_reserve(&PIN_LED_RUN_obj);
#endif /* defined (CY_USING_HAL) */
}
