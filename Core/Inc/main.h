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
#define P3_G_Pin GPIO_PIN_6
#define P3_G_GPIO_Port GPIOE
#define P10_Pin GPIO_PIN_3
#define P10_GPIO_Port GPIOF
#define P12_R_Pin GPIO_PIN_7
#define P12_R_GPIO_Port GPIOF
#define P12_G_Pin GPIO_PIN_9
#define P12_G_GPIO_Port GPIOF
#define P2_R_Pin GPIO_PIN_0
#define P2_R_GPIO_Port GPIOA
#define P1_G_Pin GPIO_PIN_3
#define P1_G_GPIO_Port GPIOA
#define P6_G_Pin GPIO_PIN_5
#define P6_G_GPIO_Port GPIOA
#define P2_Pin GPIO_PIN_0
#define P2_GPIO_Port GPIOB
#define P5_Pin GPIO_PIN_2
#define P5_GPIO_Port GPIOB
#define P7_R_Pin GPIO_PIN_12
#define P7_R_GPIO_Port GPIOF
#define P7_Pin GPIO_PIN_13
#define P7_GPIO_Port GPIOF
#define P11_R_Pin GPIO_PIN_0
#define P11_R_GPIO_Port GPIOG
#define P11_Pin GPIO_PIN_1
#define P11_GPIO_Port GPIOG
#define P4_R_Pin GPIO_PIN_7
#define P4_R_GPIO_Port GPIOE
#define P5_G_Pin GPIO_PIN_8
#define P5_G_GPIO_Port GPIOE
#define P9_R_Pin GPIO_PIN_9
#define P9_R_GPIO_Port GPIOE
#define P4_G_Pin GPIO_PIN_10
#define P4_G_GPIO_Port GPIOE
#define P9_Pin GPIO_PIN_11
#define P9_GPIO_Port GPIOE
#define P3_R_Pin GPIO_PIN_12
#define P3_R_GPIO_Port GPIOE
#define P8_R_Pin GPIO_PIN_13
#define P8_R_GPIO_Port GPIOE
#define P8_Pin GPIO_PIN_14
#define P8_GPIO_Port GPIOE
#define P2_G_Pin GPIO_PIN_15
#define P2_G_GPIO_Port GPIOE
#define P1_R_Pin GPIO_PIN_10
#define P1_R_GPIO_Port GPIOB
#define RAMP_EXIT_Pin GPIO_PIN_12
#define RAMP_EXIT_GPIO_Port GPIOB
#define P3_Pin GPIO_PIN_11
#define P3_GPIO_Port GPIOD
#define P4_Pin GPIO_PIN_12
#define P4_GPIO_Port GPIOD
#define P5_R_Pin GPIO_PIN_13
#define P5_R_GPIO_Port GPIOD
#define P10_G_Pin GPIO_PIN_14
#define P10_G_GPIO_Port GPIOD
#define P10_R_Pin GPIO_PIN_15
#define P10_R_GPIO_Port GPIOD
#define P7_G_Pin GPIO_PIN_6
#define P7_G_GPIO_Port GPIOG
#define SG_ENTER_Pin GPIO_PIN_6
#define SG_ENTER_GPIO_Port GPIOC
#define SG_EXIT_Pin GPIO_PIN_7
#define SG_EXIT_GPIO_Port GPIOC
#define P12_Pin GPIO_PIN_0
#define P12_GPIO_Port GPIOD
#define P11_G_Pin GPIO_PIN_1
#define P11_G_GPIO_Port GPIOD
#define RAMP_ENTER_Pin GPIO_PIN_10
#define RAMP_ENTER_GPIO_Port GPIOG
#define P9_G_Pin GPIO_PIN_12
#define P9_G_GPIO_Port GPIOG
#define P8_G_Pin GPIO_PIN_14
#define P8_G_GPIO_Port GPIOG
#define P6_Pin GPIO_PIN_8
#define P6_GPIO_Port GPIOB
#define P6_R_Pin GPIO_PIN_9
#define P6_R_GPIO_Port GPIOB
#define P1_Pin GPIO_PIN_0
#define P1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
