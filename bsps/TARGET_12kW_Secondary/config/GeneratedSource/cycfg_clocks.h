/*******************************************************************************
 * File Name: cycfg_clocks.h
 *
 * Description:
 * Clock configuration
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

#if !defined(CYCFG_CLOCKS_H)
#define CYCFG_CLOCKS_H

#include "cycfg_notices.h"
#include "cy_sysclk.h"

#if defined (CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#define UART_CLK_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define UART_CLK_HW CYHAL_CLOCK_BLOCK_PERIPHERAL4_16_5BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define UART_CLK_HW CY_SYSCLK_DIV_16_5_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define UART_CLK_NUM 0U
#define UART_CLK_GRP_NUM ((4U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (UART_CLK_GRP_NUM)
#define UART_CLK_GRP_NUM UART_CLK_GRP_NUM
#endif /* !defined (UART_CLK_GRP_NUM) */

#define SPI_CLK_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define SPI_CLK_HW CYHAL_CLOCK_BLOCK_PERIPHERAL4_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define SPI_CLK_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define SPI_CLK_NUM 0U
#define SPI_CLK_GRP_NUM ((4U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (SPI_CLK_GRP_NUM)
#define SPI_CLK_GRP_NUM SPI_CLK_GRP_NUM
#endif /* !defined (SPI_CLK_GRP_NUM) */

#define peri_0_group_4_div_8_1_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define peri_0_group_4_div_8_1_HW CYHAL_CLOCK_BLOCK_PERIPHERAL4_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define peri_0_group_4_div_8_1_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define peri_0_group_4_div_8_1_NUM 1U
#define PERI_0_GROUP_4_DIV_8_1_GRP_NUM ((4U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (peri_0_group_4_div_8_1_GRP_NUM)
#define peri_0_group_4_div_8_1_GRP_NUM PERI_0_GROUP_4_DIV_8_1_GRP_NUM
#endif /* !defined (peri_0_group_4_div_8_1_GRP_NUM) */

#define PWM_CLK_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define PWM_CLK_HW CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define PWM_CLK_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define PWM_CLK_NUM 0U
#define PWM_CLK_GRP_NUM ((5U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (PWM_CLK_GRP_NUM)
#define PWM_CLK_GRP_NUM PWM_CLK_GRP_NUM
#endif /* !defined (PWM_CLK_GRP_NUM) */

#define PWM_CLK_SLOW_ENABLED 1U

#if defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE)
#define PWM_CLK_SLOW_HW CYHAL_CLOCK_BLOCK_PERIPHERAL5_8BIT
#endif /* defined (CY_USING_HAL) || defined (CY_USING_HAL_LITE) */

#if !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE)
#define PWM_CLK_SLOW_HW CY_SYSCLK_DIV_8_BIT
#endif /* !defined (CY_USING_HAL) && !defined (CY_USING_HAL_LITE) */

#define PWM_CLK_SLOW_NUM 1U
#define PWM_CLK_SLOW_GRP_NUM ((5U << PERI_PCLK_GR_NUM_Pos) | (0U << PERI_PCLK_INST_NUM_Pos))

#if !defined (PWM_CLK_SLOW_GRP_NUM)
#define PWM_CLK_SLOW_GRP_NUM PWM_CLK_SLOW_GRP_NUM
#endif /* !defined (PWM_CLK_SLOW_GRP_NUM) */

#if defined (CY_USING_HAL)
extern const cyhal_resource_inst_t UART_CLK_obj;
extern const cyhal_resource_inst_t SPI_CLK_obj;
extern const cyhal_resource_inst_t peri_0_group_4_div_8_1_obj;
extern const cyhal_resource_inst_t PWM_CLK_obj;
extern const cyhal_resource_inst_t PWM_CLK_SLOW_obj;
#endif /* defined (CY_USING_HAL) */

void init_cycfg_clocks(void);
void reserve_cycfg_clocks(void);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* CYCFG_CLOCKS_H */
