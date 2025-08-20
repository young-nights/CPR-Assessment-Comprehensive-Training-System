/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-20     18452       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_23LC1024_SRAM_SPI_H_
#define APPLICATIONS_MACBSP_INC_23LC1024_SRAM_SPI_H_
#include "bsp_sys.h"


extern struct rt_spi_device *spi_dev_sram;

/* 片选引脚 -- CS */
#define     SRAM_CS_PORT     SRAM_CS_GPIO_Port
#define     SRAM_CS_PIN      SRAM_CS_Pin

#define     SRAM_CS_SET(bit) if(bit) \
                             HAL_GPIO_WritePin ( SRAM_CS_PORT, SRAM_CS_PIN , GPIO_PIN_SET )\
                             else \
                             HAL_GPIO_WritePin ( SRAM_CS_PORT, SRAM_CS_PIN , GPIO_PIN_RESET )



#endif /* APPLICATIONS_MACBSP_INC_23LC1024_SRAM_SPI_H_ */
