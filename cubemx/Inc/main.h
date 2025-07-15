/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bsp_sys.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern UART_HandleTypeDef huart1;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_USART1_UART_Init(void);
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define START_LED_Pin GPIO_PIN_2
#define START_LED_GPIO_Port GPIOE
#define PRINTER_LED_Pin GPIO_PIN_3
#define PRINTER_LED_GPIO_Port GPIOE
#define SETTING_LED_Pin GPIO_PIN_4
#define SETTING_LED_GPIO_Port GPIOE
#define PLUS_SIGN_LED_Pin GPIO_PIN_5
#define PLUS_SIGN_LED_GPIO_Port GPIOE
#define MINUS_SIGN_LED_Pin GPIO_PIN_6
#define MINUS_SIGN_LED_GPIO_Port GPIOE
#define TRAIN_LED_Pin GPIO_PIN_13
#define TRAIN_LED_GPIO_Port GPIOC
#define ASSESS_LED_Pin GPIO_PIN_14
#define ASSESS_LED_GPIO_Port GPIOC
#define COMPETITION_LED_Pin GPIO_PIN_15
#define COMPETITION_LED_GPIO_Port GPIOC
#define CLOSE_LED_Pin GPIO_PIN_0
#define CLOSE_LED_GPIO_Port GPIOF
#define BODY_LOWEST_LED_Pin GPIO_PIN_9
#define BODY_LOWEST_LED_GPIO_Port GPIOE
#define BODY_LOWWER_LED_Pin GPIO_PIN_14
#define BODY_LOWWER_LED_GPIO_Port GPIOE
#define BODY_MIDDLE_LED_Pin GPIO_PIN_15
#define BODY_MIDDLE_LED_GPIO_Port GPIOE
#define BODY_UPPER_LED_Pin GPIO_PIN_10
#define BODY_UPPER_LED_GPIO_Port GPIOB
#define BODY_UPPEST_LED_Pin GPIO_PIN_11
#define BODY_UPPEST_LED_GPIO_Port GPIOB
#define BODY_RIGHT_LED_Pin GPIO_PIN_15
#define BODY_RIGHT_LED_GPIO_Port GPIOD
#define BODY_LEFT_LED_Pin GPIO_PIN_2
#define BODY_LEFT_LED_GPIO_Port GPIOG
#define REMOVE_FOREIGN_LED_Pin GPIO_PIN_3
#define REMOVE_FOREIGN_LED_GPIO_Port GPIOG
#define EMERGENCY_LED_Pin GPIO_PIN_4
#define EMERGENCY_LED_GPIO_Port GPIOG
#define CHECK_BREATH_LED_Pin GPIO_PIN_5
#define CHECK_BREATH_LED_GPIO_Port GPIOG
#define PULSE_DETECTING_LED_Pin GPIO_PIN_6
#define PULSE_DETECTING_LED_GPIO_Port GPIOG
#define CONSCIOUSNESS_JUDGMENT_LED_Pin GPIO_PIN_7
#define CONSCIOUSNESS_JUDGMENT_LED_GPIO_Port GPIOG
#define DEBUG_LED_Pin GPIO_PIN_15
#define DEBUG_LED_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
