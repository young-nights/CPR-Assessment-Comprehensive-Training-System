/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-20     18452       the first version
 */
#include "23lc1024_sram_spi.h"



//以下是SPI以及SRAM引脚配置相关的函数---------------------------------------------------------------------------------------------

/* 宏定义SPI名称 */
#define     SRAM_SPI_NAME    "tft_spi2"
/* 宏定义SPI总线 */
#define     SRAM_SPI_BUS     "spi2"
/* 宏定义SPI句柄 */
struct rt_spi_device *spi_dev_sram;



/**
  * @brief  SPI Initialization
  * @retval void
  */
void sram_spi_init(void)
{
    /* 将SPI设备名挂载到总线 */
    rt_hw_spi_device_attach(SRAM_SPI_BUS, SRAM_SPI_NAME, SRAM_CS_PORT, SRAM_CS_PIN);
    /* 查找SPI设备 */
    spi_dev_sram = (struct rt_spi_device *)rt_device_find(SRAM_SPI_NAME);
    if(spi_dev_sram == NULL){
        rt_kprintf("SPI Device is not created!\r\n");
    }
    else{
        rt_kprintf("SPI Device is successfully!\r\n");
    }
    /***
     *! 配置SPI结构体参数
     *! data_width: spi传输数据长度为8bits
     *! max_hz: spi的最大工作频率；
     *! mode-> RT_SPI_MASTER: 主机模式；
     *! mode-> RT_SPI_MODE_2: 工作模式0（CPOL:1  CPHA:0）
     *! mode-> RT_SPI_MSB: 通讯数据高位在前低位在后
     * */
    struct rt_spi_configuration spi2_cfg;
    spi2_cfg.data_width = 8;
    spi2_cfg.max_hz = 20*1000*1000; /* 20M,SPI max 20MHz,SRAM 4-wire spi */
    spi2_cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_2 | RT_SPI_MSB;
    rt_spi_configure(spi_dev_sram, &spi2_cfg); /* 使能参数 */
}






