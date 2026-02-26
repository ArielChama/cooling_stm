/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Flow1_Pulse_Pin GPIO_PIN_13
#define Flow1_Pulse_GPIO_Port GPIOC
#define Flow2_Pulse_Pin GPIO_PIN_14
#define Flow2_Pulse_GPIO_Port GPIOC
#define Flow3_Pulse_Pin GPIO_PIN_15
#define Flow3_Pulse_GPIO_Port GPIOC
#define FAN1_TACH_Pin GPIO_PIN_0
#define FAN1_TACH_GPIO_Port GPIOC
#define FAN2_TACH_Pin GPIO_PIN_1
#define FAN2_TACH_GPIO_Port GPIOC
#define FAN3_TACH_Pin GPIO_PIN_2
#define FAN3_TACH_GPIO_Port GPIOC
#define FAN4_TACH_Pin GPIO_PIN_3
#define FAN4_TACH_GPIO_Port GPIOC
#define Pump_PWM_Pin GPIO_PIN_0
#define Pump_PWM_GPIO_Port GPIOA
#define FAN1_PWM_Pin GPIO_PIN_1
#define FAN1_PWM_GPIO_Port GPIOA
#define FAN2_PWM_Pin GPIO_PIN_2
#define FAN2_PWM_GPIO_Port GPIOA
#define NTC1__Pin GPIO_PIN_4
#define NTC1__GPIO_Port GPIOA
#define NTC2__Pin GPIO_PIN_6
#define NTC2__GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
