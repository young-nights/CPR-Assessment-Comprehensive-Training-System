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







#define SRAM_READ_CMD       0x03    // 23LC1024 读指令
#define SRAM_WRITE_CMD      0x02    // 23LC1024 写指令


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

    /* 3. HOLD 引脚初始化（CubeMX 已在 bsp_sys 完成，这里只做电平） */
    SRAM_HOLD_SET(1);   // 正常使用必须拉高
    SRAM_CS_SET(1);     // 片选空闲高电平
    rt_kprintf("23LC1024: init ok.\r\n");
}



/**
  * @brief  spi send one byte function
  * @retval rt_err_t
  */
rt_err_t sram_write_byte(rt_uint32_t addr, rt_uint8_t byte)
{

    rt_size_t len;

    /****
     * 说明：23LC1024 内部有 128 K 个存储单元, 每个单元 1 Byte
     *
     *       23LC1024 = 1 Mbit = 128 KByte = 2¹⁷ Byte
     *
     *       因此 有效寻址范围：0x00000 ~ 0x1FFFF → 17 位地址线足够
     *       但 SPI 协议规定 必须以“整字节”为单位发送，所以芯片要求 再补 7 个无效位凑成 24 位（3 字节）
     *       芯片手册规定：
     *                      命令(8 bit) + 地址(24 bit) + 数据(N×8 bit)
     *                      这 24 位地址里 真正用到的只有低 17 位；高 7 位是 Don’t-Care，通常填 0。
     *
     */
    rt_uint8_t cmd[4] = { SRAM_WRITE_CMD,
                          (addr >> 16) & 0xFF,
                          (addr >> 8)  & 0xFF,
                          addr & 0xFF };

    SRAM_CS_SET(0);
    len = rt_spi_send(spi_dev_sram, cmd, 4);
    if (len != 4){
        LOG_I("sram_write_addr error. %d", len);
        return -RT_ERROR;
    }

    len = rt_spi_send(spi_dev_sram, &byte, 1);
    len = rt_spi_send(spi_dev_sram, cmd, 4);
    if (len != 4){
        LOG_I("sram_write_byte error. %d", len);
        return -RT_ERROR;
    }
    SRAM_CS_SET(1);

    return RT_EOK;
}



/**
  * @brief  spi read one byte from special address.
  * @retval read byte's data
  * @note   rt_spi_send_then_recv() 就是 “一条函数完成：先写 N 字节，再读 M 字节，CS 中间不拉高” 的快捷封装，特别适合 “命令+读回数据” 类 SPI 设备。
  */
rt_uint8_t sram_read_byte(rt_uint32_t addr)
{
    rt_uint8_t cmd[4] = { SRAM_READ_CMD,
                          (addr >> 16) & 0xFF,
                          (addr >> 8)  & 0xFF,
                          addr & 0xFF };
    rt_uint8_t rx_byte; // 接受读取到的一个字节的数据

    SRAM_CS_SET(0);
    rt_spi_send_then_recv(spi_dev_sram, cmd, 4, &rx_byte, 1);
    SRAM_CS_SET(1);
    return rx_byte;
}

