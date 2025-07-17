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


//---------------------------------------------------------------------------------------
#define TM1629A_A_CLK_H()      HAL_GPIO_WritePin(TM1629A_CLK_GPIO_Port, TM1629A_CLK_Pin, GPIO_PIN_SET)
#define TM1629A_A_CLK_L()      HAL_GPIO_WritePin(TM1629A_CLK_GPIO_Port, TM1629A_CLK_Pin, GPIO_PIN_RESET)
#define TM1629A_A_DIO_H()      HAL_GPIO_WritePin(TM1629A_DIO_GPIO_Port, TM1629A_DIO_Pin, GPIO_PIN_SET)
#define TM1629A_A_DIO_L()      HAL_GPIO_WritePin(TM1629A_DIO_GPIO_Port, TM1629A_DIO_Pin, GPIO_PIN_RESET)
#define TM1629A_A_STB_H()      HAL_GPIO_WritePin(TM1629A_STB_GPIO_Port, TM1629A_STB_Pin,  GPIO_PIN_SET)
#define TM1629A_A_STB_L()      HAL_GPIO_WritePin(TM1629A_STB_GPIO_Port, TM1629A_STB_Pin,  GPIO_PIN_RESET)

//---------------------------------------------------------------------------------------
#define TM1629A_B_CLK_H()      HAL_GPIO_WritePin(TM1629B_CLK_GPIO_Port, TM1629B_CLK_Pin, GPIO_PIN_SET)
#define TM1629A_B_CLK_L()      HAL_GPIO_WritePin(TM1629B_CLK_GPIO_Port, TM1629B_CLK_Pin, GPIO_PIN_RESET)
#define TM1629A_B_DIO_H()      HAL_GPIO_WritePin(TM1629B_DIO_GPIO_Port, TM1629B_DIO_Pin, GPIO_PIN_SET)
#define TM1629A_B_DIO_L()      HAL_GPIO_WritePin(TM1629B_DIO_GPIO_Port, TM1629B_DIO_Pin, GPIO_PIN_RESET)
#define TM1629A_B_STB_H()      HAL_GPIO_WritePin(TM1629B_STB_GPIO_Port, TM1629B_STB_Pin,  GPIO_PIN_SET)
#define TM1629A_B_STB_L()      HAL_GPIO_WritePin(TM1629B_STB_GPIO_Port, TM1629B_STB_Pin,  GPIO_PIN_RESET)

//---------------------------------------------------------------------------------------





//---------------------------------------------------------------------------------------

/**
  * @brief  Delay function(uint:ms)
  * @param  us 微妙数
  * @retval void
  */
static void TM1629A_Delay_us(uint32_t us)
{
    for(; us; us--) __NOP();
}


/**
  * @brief  TM1629A Chip send one byte and select tube to write
  * @param  tube 数码管选择
  *         data 需要写入的数据
  * @retval void
  * @note   这个工程板载了2个TM1629A芯片，因此这个写单个字节函数通过选型进行公用
  */
/* 发送 1 字节（低位先行） */
static void TM1629A_Write_Byte(TM16xxSelect tube , rt_uint8_t data)
{
    if(tube == TM1629A_A){
        for(rt_uint8_t i = 0; i < 8; i++)
        {
            TM1629A_A_CLK_L();
            if(data & 0x01){
                TM1629A_A_DIO_H();
            }
            else {
                TM1629A_A_DIO_L();
            }
            TM1629A_Delay_us(2);
            TM1629A_A_CLK_H();
            TM1629A_Delay_us(2);
            data >>= 1;
        }
    }
    else if(tube == TM1629A_B){
        for(rt_uint8_t i = 0; i < 8; i++)
        {
            TM1629A_B_CLK_L();
            if(data & 0x01){
                TM1629A_B_DIO_H();
            }
            else {
                TM1629A_B_DIO_L();
            }
            TM1629A_Delay_us(2);
            TM1629A_B_CLK_H();
            TM1629A_Delay_us(2);
            data >>= 1;
        }
    }
}



/**
  * @brief  TM1629A Chip send one byte(cmd) and select tube to write
  * @param  tube 数码管选择
  *         cmd 指令数据
  * @retval void
  * @note   STB引脚被拉低后，写入的第一个字节作为指令，STB引脚拉高后，CLK时许被忽略
  */
static void TM1629A_Write_CMD(TM16xxSelect tube , rt_uint8_t cmd)
{
    if(tube == TM1629A_A){
        TM1629A_A_STB_L();
        TM1629A_Write_Byte(tube, cmd);
        TM1629A_A_STB_H();
    }
    else if(tube == TM1629A_B){
        TM1629A_B_STB_L();
        TM1629A_Write_Byte(tube, cmd);
        TM1629A_B_STB_H();
    }
}



/**
  * @brief  TM1629A Chip Initialization
  * @param  void
  * @retval void
  * @note
  */
void TM1629A_Init(void)
{
    // 自动地址增加
    TM1629A_Write_CMD(TM1629A_A, 0x40);
    // 显示开，亮度7
    TM1629A_Write_CMD(TM1629A_A, 0x8F);
}


/**
  * @brief  TM1629A Control digital tube off
  * @param  void
  * @retval void
  * @note
  */
void TM1629A_Digital_Tube_Clear(void)
{

}




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


