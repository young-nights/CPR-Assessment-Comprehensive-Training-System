/*
 * bsp_led.h
 *
 *  Created on: May 16, 2024
 *      Author: zphu
 */

#ifndef MACBSP_INC_BSP_LED_H_

#define MACBSP_INC_BSP_LED_H_
#include "bsp_sys.h"

#define             LED_NUM             (30)
/****************************** LED 函数宏定义***************************************/
#define             macLED_Debug_OFF()                         HAL_GPIO_WritePin ( DEBUG_LED_GPIO_Port, DEBUG_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Debug_ON()                          HAL_GPIO_WritePin ( DEBUG_LED_GPIO_Port, DEBUG_LED_Pin , GPIO_PIN_SET )

#define             macLED_Consciousness_Judgment_OFF()        HAL_GPIO_WritePin ( CONSCIOUSNESS_JUDGMENT_LED_GPIO_Port, CONSCIOUSNESS_JUDGMENT_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Consciousness_Judgment_ON()         HAL_GPIO_WritePin ( CONSCIOUSNESS_JUDGMENT_LED_GPIO_Port, CONSCIOUSNESS_JUDGMENT_LED_Pin , GPIO_PIN_SET )

#define             macLED_Pulse_Detecting_OFF()               HAL_GPIO_WritePin ( PULSE_DETECTING_LED_GPIO_Port, PULSE_DETECTING_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Pulse_Detecting_ON()                HAL_GPIO_WritePin ( PULSE_DETECTING_LED_GPIO_Port, PULSE_DETECTING_LED_Pin , GPIO_PIN_SET )

#define             macLED_Check_Breath_OFF()                  HAL_GPIO_WritePin ( CHECK_BREATH_LED_GPIO_Port, CHECK_BREATH_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Check_Breath_ON()                   HAL_GPIO_WritePin ( CHECK_BREATH_LED_GPIO_Port, CHECK_BREATH_LED_Pin , GPIO_PIN_SET )

#define             macLED_Emergency_OFF()                     HAL_GPIO_WritePin ( EMERGENCY_LED_GPIO_Port, EMERGENCY_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Emergency_ON()                      HAL_GPIO_WritePin ( EMERGENCY_LED_GPIO_Port, EMERGENCY_LED_Pin , GPIO_PIN_SET )

#define             macLED_Remove_Foreign_OFF()                HAL_GPIO_WritePin ( REMOVE_FOREIGN_LED_GPIO_Port, REMOVE_FOREIGN_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Remove_Foreign_ON()                 HAL_GPIO_WritePin ( REMOVE_FOREIGN_LED_GPIO_Port, REMOVE_FOREIGN_LED_Pin , GPIO_PIN_SET )

#define             macLED_Body_Left_OFF()                     HAL_GPIO_WritePin ( BODY_LEFT_LED_GPIO_Port, BODY_LEFT_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Body_Left_ON()                      HAL_GPIO_WritePin ( BODY_LEFT_LED_GPIO_Port, BODY_LEFT_LED_Pin , GPIO_PIN_SET )

#define             macLED_Body_Right_OFF()                    HAL_GPIO_WritePin ( BODY_RIGHT_LED_GPIO_Port, BODY_RIGHT_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Body_Right_ON()                     HAL_GPIO_WritePin ( BODY_RIGHT_LED_GPIO_Port, BODY_RIGHT_LED_Pin , GPIO_PIN_SET )

#define             macLED_Uppest_OFF()                        HAL_GPIO_WritePin ( BODY_UPPEST_LED_GPIO_Port, BODY_UPPEST_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Uppest_ON()                         HAL_GPIO_WritePin ( BODY_UPPEST_LED_GPIO_Port, BODY_UPPEST_LED_Pin , GPIO_PIN_SET )

#define             macLED_Upper_OFF()                         HAL_GPIO_WritePin ( BODY_UPPER_LED_GPIO_Port, BODY_UPPER_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Upper_ON()                          HAL_GPIO_WritePin ( BODY_UPPER_LED_GPIO_Port, BODY_UPPER_LED_Pin , GPIO_PIN_SET )

#define             macLED_Middle_OFF()                        HAL_GPIO_WritePin ( BODY_MIDDLE_LED_GPIO_Port, BODY_MIDDLE_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Middle_ON()                         HAL_GPIO_WritePin ( BODY_MIDDLE_LED_GPIO_Port, BODY_MIDDLE_LED_Pin , GPIO_PIN_SET )

#define             macLED_Lower_OFF()                         HAL_GPIO_WritePin ( BODY_LOWWER_LED_GPIO_Port, BODY_LOWWER_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Lower_ON()                          HAL_GPIO_WritePin ( BODY_LOWWER_LED_GPIO_Port, BODY_LOWWER_LED_Pin , GPIO_PIN_SET )

#define             macLED_Lowest_OFF()                        HAL_GPIO_WritePin ( BODY_LOWEST_LED_GPIO_Port, BODY_LOWEST_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Lowest_ON()                         HAL_GPIO_WritePin ( BODY_LOWEST_LED_GPIO_Port, BODY_LOWEST_LED_Pin , GPIO_PIN_SET )

#define             macLED_Close_OFF()                         HAL_GPIO_WritePin ( CLOSE_LED_GPIO_Port, CLOSE_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Close_ON()                          HAL_GPIO_WritePin ( CLOSE_LED_GPIO_Port, CLOSE_LED_Pin , GPIO_PIN_SET )

#define             macLED_Competition_OFF()                   HAL_GPIO_WritePin ( COMPETITION_LED_GPIO_Port, COMPETITION_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Competition_ON()                    HAL_GPIO_WritePin ( COMPETITION_LED_GPIO_Port, COMPETITION_LED_Pin , GPIO_PIN_SET )

#define             macLED_Assess_OFF()                        HAL_GPIO_WritePin ( ASSESS_LED_GPIO_Port, ASSESS_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Assess_ON()                         HAL_GPIO_WritePin ( ASSESS_LED_GPIO_Port, ASSESS_LED_Pin , GPIO_PIN_SET )

#define             macLED_Train_OFF()                         HAL_GPIO_WritePin ( TRAIN_LED_GPIO_Port, TRAIN_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Train_ON()                          HAL_GPIO_WritePin ( TRAIN_LED_GPIO_Port, TRAIN_LED_Pin , GPIO_PIN_SET )

#define             macLED_Minus_Sign_OFF()                    HAL_GPIO_WritePin ( MINUS_SIGN_LED_GPIO_Port, MINUS_SIGN_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Minus_Sign_ON()                     HAL_GPIO_WritePin ( MINUS_SIGN_LED_GPIO_Port, MINUS_SIGN_LED_Pin , GPIO_PIN_SET )

#define             macLED_Plus_Sign_OFF()                     HAL_GPIO_WritePin ( PLUS_SIGN_LED_GPIO_Port, PLUS_SIGN_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Plus_Sign_ON()                      HAL_GPIO_WritePin ( PLUS_SIGN_LED_GPIO_Port, PLUS_SIGN_LED_Pin , GPIO_PIN_SET )

#define             macLED_Setting_OFF()                       HAL_GPIO_WritePin ( SETTING_LED_GPIO_Port, SETTING_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Setting_ON()                        HAL_GPIO_WritePin ( SETTING_LED_GPIO_Port, SETTING_LED_Pin , GPIO_PIN_SET )

#define             macLED_Printer_OFF()                       HAL_GPIO_WritePin ( PRINTER_LED_GPIO_Port, PRINTER_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Printer_ON()                        HAL_GPIO_WritePin ( PRINTER_LED_GPIO_Port, PRINTER_LED_Pin , GPIO_PIN_SET )

#define             macLED_Start_OFF()                         HAL_GPIO_WritePin ( START_LED_GPIO_Port, START_LED_Pin , GPIO_PIN_RESET )
#define             macLED_Start_ON()                          HAL_GPIO_WritePin ( START_LED_GPIO_Port, START_LED_Pin , GPIO_PIN_SET )

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
    LED_Name_Close,                     /*! 复位LED */
    LED_Name_Competition,               /*! 竞赛LED */
    LED_Name_Assess,                    /*! 考核LED */
    LED_Name_Train,                     /*! 训练LED */
    LED_Name_Minus_Sign,                /*! 减号LED */
    LED_Name_Plus_Sign,                 /*! 加号LED */
    LED_Name_Setting,                   /*! 设置LED */
    LED_Name_Printer,                   /*! 打印LED */
    LED_Name_Start,                     /*! 开启LED */

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
