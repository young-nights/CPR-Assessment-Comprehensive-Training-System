/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-05-15     teati       the first version
 */
#ifndef APPLICATIONS_MACSYS_INC_BSP_SYS_H_

#define APPLICATIONS_MACSYS_INC_BSP_SYS_H_

/* RTT实时操作系统的头文件 */
#include <rtthread.h>
#include <drv_common.h>
#include <board.h>
#include <rtdevice.h>
#include <rthw.h>
//#include <drv_spi.h>
#include <rtdbg.h>
/* 该头文件包含了所有CubeMX自动生成的初始化引脚 */
#include "main.h"

/* macAPP 头文件 */
#include "rtt_system_work.h"

/* macBSP 头文件 */
#include "bsp_hard.h"
#include "bsp_led.h"


/* macSYS 头文件 */
#include "bsp_typedef.h"
#include "macLOG.h"




// 这个宏用于使能lv_printf.c文件中的lv_snprintf()函数
#define USE_LV_SNPRINTF     0




#endif /* APPLICATIONS_MACSYS_INC_BSP_SYS_H_ */
