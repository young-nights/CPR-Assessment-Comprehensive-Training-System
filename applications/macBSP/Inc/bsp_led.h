/*
 * bsp_led.h
 *
 *  Created on: May 16, 2024
 *      Author: zphu
 */

#ifndef MACBSP_INC_BSP_LED_H_

#define MACBSP_INC_BSP_LED_H_
#include "bsp_sys.h"

#define             LED_NUM             (21)
/****************************** LED 函数宏定义***************************************/
#define             macLED_Debug_OFF()                          HAL_GPIO_WritePin ( DEBUG_LED_GPIO_Port, DEBUG_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Debug_ON()                           HAL_GPIO_WritePin ( DEBUG_LED_GPIO_Port, DEBUG_LED_Pin , GPIO_PIN_SET )



/*LED名称类型*/
typedef	enum
{
    LED_Name_Debug = (0x01),            /*! 调试LED */
    LED_Name_Consciousness_Judgment,    /*! 意识判断LED */
    LED_Name_Pulse_Detecting,           /*! 脉搏检查LED */
    LED_Name_Check_Breath,              /*! 呼吸检查LED */
    LED_Name_Emergency_Call,            /*! 急救呼叫LED */
    LED_Name_Remove_Foreign,            /*! 清除异物LED */
    LED_Name_Body_Left,                 /*! 身形左侧LED */
    LED_Name_Body_Right,                /*! 身形右侧LED */
    LED_Name_Uppest,                    /*! 身形最上侧LED */
    LED_Name_Upper,                     /*! 身形上侧LED */
    LED_Name_Middle,                    /*! 身形中间LED */
    LED_Name_Lower,                     /*! 身形下侧LED */
    LED_Name_Lowest,                    /*! 身形最下侧LED */

}LED_Name_TypeDef;



/************************** PAD 函数声明********************************/
void LED_Init(void);
void LED_Out(int8_t ledName, int8_t ledState);
int8_t 	LED_GetNumber(void);
void LED_Off(int8_t ledName);
void LED_On(int8_t ledName);
void LED_Toggle(int8_t ledName);
void LED_Grad(int8_t ledName);
void LED_BlinkSetCycleDuty(int8_t ledName, int8_t Cycle, int8_t Duty);
void LED_Blink(int8_t ledName, int8_t cry, int8_t mute, int8_t repeat);
void LED_Fancy(int8_t mode);
void LED_DrvScan(void);
int ledTimer_Init(void);



#endif /* MACBSP_INC_BSP_LED_H_ */
