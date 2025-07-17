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










/**
  * @brief  This thread entry is used for NixieTube scanning
  * @retval void
  */
void NixieTube_Thread_entry(void* parameter)
{


    for(;;)
    {
        rt_thread_mdelay(10);
    }


}



/**
  * @brief  This is a Initialization for water level Check
  * @retval int
  */
int NixieTube_Thread_Init(void)
{
    rt_thread_t NixieTube_Task_Handle = RT_NULL;
    /* 创建检查一些系统状态标志的线程  -- 优先级：25 */
    NixieTube_Task_Handle = rt_thread_create("NixieTube_Thread_entry", NixieTube_Thread_entry, RT_NULL, 512, 25, 30);
    /* 检查是否创建成功,成功就启动线程 */
    if(NixieTube_Task_Handle != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. NixieTube_Thread_entry is Succeed!! \r\n",Record.kprintf_cnt++);
        rt_thread_startup(NixieTube_Task_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. NixieTube_Thread_entry is Failed \r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(NixieTube_Thread_Init);


