/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-10-15     Meco Man     The first version
 */

#ifndef LV_RT_THREAD_CONF_H
#define LV_RT_THREAD_CONF_H

#ifdef __RTTHREAD__

#define LV_RTTHREAD_INCLUDE <rtthread.h>
#include LV_RTTHREAD_INCLUDE


/*====================
   COLOR SETTINGS
 *====================*/

/*Color depth: 1 (1 byte per pixel), 8 (RGB332), 16 (RGB565), 32 (ARGB8888)*/
#define LV_COLOR_DEPTH 16

/*Swap the 2 bytes of RGB565 color. Useful if the display has an 8-bit interface (e.g. SPI)*/
#define LV_COLOR_16_SWAP 1



/*=========================
   MEMORY SETTINGS
 *=========================*/

#ifdef RT_USING_HEAP
#  define LV_MEM_CUSTOM 1
#  define LV_MEM_CUSTOM_INCLUDE LV_RTTHREAD_INCLUDE
#  define LV_MEM_CUSTOM_ALLOC   sram_malloc
#  define LV_MEM_CUSTOM_FREE    sram_free
#  define LV_MEM_CUSTOM_REALLOC sram_realloc
//#  define LV_MEM_CUSTOM_ALLOC   rt_malloc
//#  define LV_MEM_CUSTOM_FREE    rt_free
//#  define LV_MEM_CUSTOM_REALLOC rt_realloc
#  define LV_MEM_SIZE (128U * 1024U)          /*[bytes]*/
#endif





/*====================
   HAL SETTINGS
 *====================*/

#define LV_TICK_CUSTOM 1
#define LV_TICK_CUSTOM_INCLUDE LV_RTTHREAD_INCLUDE
#define LV_TICK_CUSTOM_SYS_TIME_EXPR (rt_tick_get_millisecond())    /*Expression evaluating to current system time in ms*/

#ifdef PKG_LVGL_DISP_REFR_PERIOD
#define LV_DISP_DEF_REFR_PERIOD   PKG_LVGL_DISP_REFR_PERIOD
#endif

/*=======================
 * FEATURE CONFIGURATION
 *=======================*/

/*-------------
 * Asserts
 *-----------*/

#define LV_ASSERT_HANDLER_INCLUDE LV_RTTHREAD_INCLUDE
#define LV_ASSERT_HANDLER RT_ASSERT(0);

/*-------------
 * Others
 *-----------*/

#define LV_SPRINTF_CUSTOM 1
#define LV_SPRINTF_INCLUDE LV_RTTHREAD_INCLUDE
#define lv_snprintf  rt_snprintf
#define lv_vsnprintf rt_vsnprintf
#define LV_SPRINTF_USE_FLOAT 0

/*=====================
 *  COMPILER SETTINGS
 *====================*/

#ifdef ARCH_CPU_BIG_ENDIAN
#  define LV_BIG_ENDIAN_SYSTEM 1
#else
#  define LV_BIG_ENDIAN_SYSTEM 0
#endif

#ifdef rt_align /* >= RT-Thread v5.0.0 */
#  define LV_ATTRIBUTE_MEM_ALIGN rt_align(RT_ALIGN_SIZE)
#else
#  define LV_ATTRIBUTE_MEM_ALIGN ALIGN(RT_ALIGN_SIZE)
#endif

/*==================
* EXAMPLES
*==================*/

#ifdef PKG_LVGL_USING_EXAMPLES
#  define LV_BUILD_EXAMPLES 1
#endif

/*--END OF LV_RT_THREAD_CONF_H--*/

#endif /*__RTTHREAD__*/

#endif /*LV_CONF_H*/
