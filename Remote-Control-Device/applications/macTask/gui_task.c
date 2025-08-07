/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-07     18452       the first version
 */
#include "bsp_sys.h"


rt_mutex_t xGuiMutex;


/**
  * @brief  This thread entry is used for touch check
  * @retval void
  */
void GUI_Thread_entry(void* parameter)
{

    rt_err_t pdTRUE = 1;

    for(;;)
    {
        rt_thread_mdelay(10);

        if( pdTRUE == rt_mutex_take(xGuiMutex, RT_WAITING_FOREVER))
        {
            lv_task_handler();
            rt_mutex_release(xGuiMutex);
        }
    }


}



/**
  * @brief  This is a Initialization for water level Check
  * @retval int
  */
rt_thread_t GUI_Task_Handle = RT_NULL;
int GUI_Thread_Init(void)
{
    /* 创建检查一些系统状态标志的线程  -- 优先级：25 */
    GUI_Task_Handle = rt_thread_create("GUI_Thread_entry", GUI_Thread_entry, RT_NULL, 512, 25, 300);
    /* 检查是否创建成功,成功就启动线程 */
    if(GUI_Task_Handle != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. GUI_Thread_entry is Succeed!! \r\n",Record.kprintf_cnt++);

        /* 创建一个动态互斥量 */
        xGuiMutex = rt_mutex_create("gui_mutex", RT_IPC_FLAG_FIFO);
        if (xGuiMutex == RT_NULL)
        {
            rt_kprintf("create xGuiMutex failed.\n");
            return -1;
        }

        rt_thread_startup(GUI_Task_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. GUI_Thread_entry is Failed \r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}
//INIT_APP_EXPORT(GUI_Thread_Init);





