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
#include "stm32h5xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define P4_G_Pin GPIO_PIN_6
#define P4_G_GPIO_Port GPIOE
#define P4_Pin GPIO_PIN_0
#define P4_GPIO_Port GPIOF
#define P5_Pin GPIO_PIN_1
#define P5_GPIO_Port GPIOF
#define P6I1_Pin GPIO_PIN_2
#define P6I1_GPIO_Port GPIOF
#define P7I2_R_Pin GPIO_PIN_0
#define P7I2_R_GPIO_Port GPIOC
#define P3_R_Pin GPIO_PIN_0
#define P3_R_GPIO_Port GPIOA
#define P1_G_Pin GPIO_PIN_3
#define P1_G_GPIO_Port GPIOA
#define P6I1_R_Pin GPIO_PIN_6
#define P6I1_R_GPIO_Port GPIOA
#define SERVO_EXIT_Pin GPIO_PIN_7
#define SERVO_EXIT_GPIO_Port GPIOA
#define P2_R_Pin GPIO_PIN_0
#define P2_R_GPIO_Port GPIOB
#define P1_Pin GPIO_PIN_0
#define P1_GPIO_Port GPIOG
#define P7I2_Pin GPIO_PIN_4
#define P7I2_GPIO_Port GPIOE
#define P4_R_Pin GPIO_PIN_10
#define P4_R_GPIO_Port GPIOE
#define P5_G_Pin GPIO_PIN_12
#define P5_G_GPIO_Port GPIOE
#define P3_G_Pin GPIO_PIN_15
#define P3_G_GPIO_Port GPIOE
#define P2_G_Pin GPIO_PIN_10
#define P2_G_GPIO_Port GPIOB
#define P5_R_Pin GPIO_PIN_11
#define P5_R_GPIO_Port GPIOD
#define SERVO_ENTER_Pin GPIO_PIN_6
#define SERVO_ENTER_GPIO_Port GPIOC
#define P3_Pin GPIO_PIN_0
#define P3_GPIO_Port GPIOD
#define P2_Pin GPIO_PIN_1
#define P2_GPIO_Port GPIOD
#define P7I2_G_Pin GPIO_PIN_6
#define P7I2_G_GPIO_Port GPIOD
#define P6I1_G_Pin GPIO_PIN_7
#define P6I1_G_GPIO_Port GPIOD
#define DISPLAY_SCL_Pin GPIO_PIN_8
#define DISPLAY_SCL_GPIO_Port GPIOB
#define DISPLAY_SDA_Pin GPIO_PIN_9
#define DISPLAY_SDA_GPIO_Port GPIOB
#define P1_R_Pin GPIO_PIN_0
#define P1_R_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
