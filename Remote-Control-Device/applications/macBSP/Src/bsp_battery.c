
/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-28     18452       the first version
 */


#include "bsp_battery.h"




/**
  * @brief  battery recharge enable function.
  * @retval void
  */
void battery_recharge_enable(void)
{
    HAL_GPIO_WritePin(BAT_EN_GPIO_Port, BAT_EN_Pin, GPIO_PIN_SET);
}




/**
  * @brief  battery recharge disable function.
  * @retval void
  */
void battery_recharge_disable(void)
{
    HAL_GPIO_WritePin(BAT_EN_GPIO_Port, BAT_EN_Pin, GPIO_PIN_RESET);
}


/**
  * @brief  check if charging is enable.
  * @retval rt_uint8_t
  */
rt_uint8_t battery_check_if_recharging(void)
{

}


