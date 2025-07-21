/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-17     18452       the first version
 */
#include "bsp_sys.h"



/* 把 4 位 BCD 值映射到键码表 */
static const AI12_Key_t key_map[16] =
{
    /* 0x0 */ AI12_KEY_1,
    /* 0x1 */ AI12_KEY_2,
    /* 0x2 */ AI12_KEY_3,
    /* 0x3 */ AI12_KEY_4,
    /* 0x4 */ AI12_KEY_5,
    /* 0x5 */ AI12_KEY_6,
    /* 0x6 */ AI12_KEY_7,
    /* 0x7 */ AI12_KEY_8,
    /* 0x8 */ AI12_KEY_9,
    /* 0x9 */ AI12_KEY_10,
    /* 0xA */ AI12_KEY_11,
    /* 0xB */ AI12_KEY_12,
    /* 0xC..0xE 未使用，返回 NONE */
    [0xC]  = AI12_KEY_NONE,
    [0xD]  = AI12_KEY_NONE,
    [0xE]  = AI12_KEY_NONE,
    /* 0xF = 1111b → 无按键 */
    [0xF]  = AI12_KEY_NONE
};



/***
 *  @brief  触摸芯片扫描函数
 *  @return 返回键值信息
 **/
AI12_Key_t AI12_ScanKey(void)
{
    rt_uint8_t bcd = 0;

    bcd  = HAL_GPIO_ReadPin(AI12_P0_GPIO_Port, AI12_P0_Pin) ? (1 << 3) : 0;
    bcd |= HAL_GPIO_ReadPin(AI12_P1_GPIO_Port, AI12_P1_Pin) ? (1 << 2) : 0;
    bcd |= HAL_GPIO_ReadPin(AI12_P2_GPIO_Port, AI12_P2_Pin) ? (1 << 1) : 0;
    bcd |= HAL_GPIO_ReadPin(AI12_P3_GPIO_Port, AI12_P3_Pin) ? (1 << 0) : 0;

    return key_map[bcd & 0x0F];
}





/**
  * @brief  This thread entry is used for touch check
  * @retval void
  */
void AI12_Thread_entry(void* parameter)
{

    AI12_Key_t keyValue;

    for(;;)
    {
        keyValue = AI12_ScanKey();

        if(keyValue == AI12_KEY_NONE){

        }
        else if(keyValue == AI12_KEY_1){

        }
        else if(keyValue == AI12_KEY_2){

        }
        else if(keyValue == AI12_KEY_3){

        }
        else if(keyValue == AI12_KEY_4){

        }
        else if(keyValue == AI12_KEY_5){

        }
        else if(keyValue == AI12_KEY_6){

        }
        else if(keyValue == AI12_KEY_7){

        }
        else if(keyValue == AI12_KEY_8){

        }
        else if(keyValue == AI12_KEY_9){

        }
        else if(keyValue == AI12_KEY_10){

        }
        else if(keyValue == AI12_KEY_11){

        }
        else if(keyValue == AI12_KEY_12){

        }

        rt_thread_mdelay(10);
    }


}



/**
  * @brief  This is a Initialization for water level Check
  * @retval int
  */
int AI12_Thread_Init(void)
{
    rt_thread_t AI12_Task_Handle = RT_NULL;
    /* 创建检查一些系统状态标志的线程  -- 优先级：25 */
    AI12_Task_Handle = rt_thread_create("AI12_Thread_entry", AI12_Thread_entry, RT_NULL, 512, 25, 30);
    /* 检查是否创建成功,成功就启动线程 */
    if(AI12_Task_Handle != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. AI12_Thread_entry is Succeed!! \r\n",Record.kprintf_cnt++);
        rt_thread_startup(AI12_Task_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. AI12_Thread_entry is Failed \r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(AI12_Thread_Init);



