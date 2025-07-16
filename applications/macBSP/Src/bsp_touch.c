/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-17     Administrator       the first version
 */

#include "bsp_touch.h"



/***
 *
 *
 *
 **/
rt_uint8_t AI12_ReadBCD(void)
{
   rt_uint8_t BCD0,BCD1,BCD2,BCD3 = 0;
   rt_uint32_t BCD_Value = 0;

   BCD0 = HAL_GPIO_ReadPin(AI12_P0_GPIO_Port, AI12_P0_Pin);
   BCD1 = HAL_GPIO_ReadPin(AI12_P1_GPIO_Port, AI12_P1_Pin);
   BCD2 = HAL_GPIO_ReadPin(AI12_P2_GPIO_Port, AI12_P2_Pin);
   BCD3 = HAL_GPIO_ReadPin(AI12_P3_GPIO_Port, AI12_P3_Pin);




}









/*---------------------------------------------------------------------------------------------------------------*/
/* 以下是触摸按键扫描线程的创建以及回调函数                                                                                                                                                 */
/*---------------------------------------------------------------------------------------------------------------*/
/**
  * @brief  AI12Timer Callback Function
  * @note   scanning time -- 10ms
  * @retval void
  */
static void AI12Timer_callback(void* parameter)
{

}



/**
  * @brief  AI12Timer initialize
  * @retval int
  */
int AI12Timer_Init(void)
{
    static rt_timer_t AI12Timer;
    /* 创建AI12软件定时器线程 */
    AI12Timer = rt_timer_create("AI12Timer_callback", AI12Timer_callback, RT_NULL, 10, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_SOFT_TIMER);
    /* 如果句柄创建成功，就开启AI12Timer软件定时器 */
    if(AI12Timer != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. AI12Timer initialize succeed!\r\n",Record.kprintf_cnt++);
        rt_timer_start(AI12Timer);
    }
    return RT_EOK;
}




