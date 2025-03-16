/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : FreeRTOS applicative file
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

/* Includes ------------------------------------------------------------------*/
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "i2c-lcd.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern TIM_HandleTypeDef htim3;

/* USER CODE END Variables */
/* Definitions for rampControlTask */
osThreadId_t rampControlTaskHandle;
const osThreadAttr_t rampControlTask_attributes = {
  .name = "rampControlTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for parkingControlTask */
osThreadId_t parkingControlTaskHandle;
const osThreadAttr_t parkingControlTask_attributes = {
  .name = "parkingControlTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void raise_ramp(char channel);
void check_capacity();

/* USER CODE END FunctionPrototypes */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of rampControlTask */
  rampControlTaskHandle = osThreadNew(StartRampControlTask, NULL, &rampControlTask_attributes);

  /* creation of parkingControlTask */
  parkingControlTaskHandle = osThreadNew(StartParkingControlTask, NULL, &parkingControlTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_StartRampControlTask */
/**
* @brief Function implementing the rampControlTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRampControlTask */
void StartRampControlTask(void *argument)
{
  /* USER CODE BEGIN rampControlTask */
  //LCD
  lcd_init();
  //HAL_Delay(50);
  //  HAL_Delay(500);
	//__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 750);
	//__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, 750);
  /* Infinite loop */
  for(;;)
  {
	int r1 = 0, r2 = 0;
	r1 = HAL_GPIO_ReadPin(GPIOG, RAMP_ENTER_Pin);
	r2 = HAL_GPIO_ReadPin(GPIOB, RAMP_EXIT_Pin);

	if(r1==1)
	{
    	lcd_send_string("ramp up");
		raise_ramp(TIM_CHANNEL_1);
		lcd_send_cmd(1);
	}

	if(r2==1)
	{
    	lcd_send_string("ramp down");
		raise_ramp(TIM_CHANNEL_2);
		lcd_send_cmd(1);
	}

    osDelay(1);

  }
  /* USER CODE END rampControlTask */
}

/* USER CODE BEGIN Header_StartParkingControlTask */
/**
* @brief Function implementing the parkingControlTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartParkingControlTask */
void StartParkingControlTask(void *argument)
{
  /* USER CODE BEGIN parkingControlTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
    check_capacity();
  }
  /* USER CODE END parkingControlTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void check_capacity()
{
	int p1 = HAL_GPIO_ReadPin(GPIOE, P1_Pin);
	if(p1==1)
	{
		HAL_GPIO_WritePin(GPIOB, P1_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, P1_G_Pin, 0);
	}
	else if(p1==0)
	{
		HAL_GPIO_WritePin(GPIOB, P1_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, P1_G_Pin, 1);
	}

	int p2 = HAL_GPIO_ReadPin(GPIOB, P2_Pin);
	if(p2==1)
	{
		HAL_GPIO_WritePin(GPIOA, P2_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P2_G_Pin, 0);
	}
	else if(p2==0)
	{
		HAL_GPIO_WritePin(GPIOE, P2_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, P2_R_Pin, 0);
	}

	int p3 = HAL_GPIO_ReadPin(GPIOD, P3_Pin);
	if(p3==1)
	{
		HAL_GPIO_WritePin(GPIOE, P3_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P3_G_Pin, 0);
	}
	else if(p3==0)
	{
		HAL_GPIO_WritePin(GPIOE, P3_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P3_R_Pin, 0);
	}

	int p4 = HAL_GPIO_ReadPin(GPIOD, P4_Pin);
	if(p4==1)
	{
		HAL_GPIO_WritePin(GPIOE, P4_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P4_G_Pin, 0);
	}
	else if(p4==0)
	{
		HAL_GPIO_WritePin(GPIOE, P4_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P4_R_Pin, 0);
	}

	int p5 = HAL_GPIO_ReadPin(GPIOB, P5_Pin);
	if(p5==1)
	{
		HAL_GPIO_WritePin(GPIOD, P5_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P5_G_Pin, 0);
	}
	else if(p5==0)
	{
		HAL_GPIO_WritePin(GPIOE, P5_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, P5_R_Pin, 0);
	}

	int p6 = HAL_GPIO_ReadPin(GPIOB, P6_Pin);
	if(p6==1)
	{
		HAL_GPIO_WritePin(GPIOB, P6_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, P6_G_Pin, 0);
	}
	else if(p6==0)
	{
		HAL_GPIO_WritePin(GPIOA, P6_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, P6_R_Pin, 0);
	}

	int p7 = HAL_GPIO_ReadPin(GPIOF, P7_Pin);
	if(p7==1)
	{
		HAL_GPIO_WritePin(GPIOF, P7_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOG, P7_G_Pin, 0);
	}
	else if(p7==0)
	{
		HAL_GPIO_WritePin(GPIOG, P7_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOF, P7_R_Pin, 0);
	}

	int p8 = HAL_GPIO_ReadPin(GPIOE, P8_Pin);
	if(p8==1)
	{
		HAL_GPIO_WritePin(GPIOE, P8_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOG, P8_G_Pin, 0);
	}
	else if(p8==0)
	{
		HAL_GPIO_WritePin(GPIOG, P8_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P8_R_Pin, 0);
	}

	int p9 = HAL_GPIO_ReadPin(GPIOE, P9_Pin);
	if(p9==1)
	{
		HAL_GPIO_WritePin(GPIOE, P9_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOG, P9_G_Pin, 0);
	}
	else if(p9==0)
	{
		HAL_GPIO_WritePin(GPIOG, P9_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOE, P9_R_Pin, 0);
	}

	int p10 = HAL_GPIO_ReadPin(GPIOF, P10_Pin);
	if(p10==1)
	{
		HAL_GPIO_WritePin(GPIOD, P10_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 0);
	}
	else if(p10==0)
	{
		HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, P10_R_Pin, 0);
	}

	int p11 = HAL_GPIO_ReadPin(GPIOG, P11_Pin);
	if(p11==1)
	{
		HAL_GPIO_WritePin(GPIOG, P11_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, P11_G_Pin, 0);
	}
	else if(p11==0)
	{
		HAL_GPIO_WritePin(GPIOD, P11_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOG, P11_R_Pin, 0);
	}

	int p12 = HAL_GPIO_ReadPin(GPIOD, P12_Pin);
	if(p12==1)
	{
		HAL_GPIO_WritePin(GPIOF, P12_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOF, P12_G_Pin, 0);
	}
	else if(p12==0)
	{
		HAL_GPIO_WritePin(GPIOF, P12_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOF, P12_R_Pin, 0);
	}
}

void raise_ramp(char channel)
{
	int x = 0;
	for(x=750; x>250; x=x-1)
	{
		__HAL_TIM_SET_COMPARE(&htim3,channel, x);
		osDelay(5);
	}
	osDelay(3000);
	for(x=250; x<750; x=x+1)
	{
		__HAL_TIM_SET_COMPARE(&htim3,channel, x);
		osDelay(5);
	}

}

/* USER CODE END Application */

