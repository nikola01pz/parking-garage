/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "i2c.h"
#include "icache.h"
#include "memorymap.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM3_Init();
  MX_ICACHE_Init();
  /* USER CODE BEGIN 2 */

  //LCD
  lcd_init();
  HAL_Delay(50);
  lcd_send_string("parking 2");
  HAL_Delay(500);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	HAL_Delay(10);
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

//	int p6i1 = HAL_GPIO_ReadPin(GPIOF, P6I1_Pin);
//	if(p6i1==1)
//	{
//		HAL_GPIO_WritePin(GPIOA, P6I1_R_Pin, 1);
//		HAL_GPIO_WritePin(GPIOD, P6I1_G_Pin, 0);
//	}
//	else if(p6i1==0)
//	{
//		HAL_GPIO_WritePin(GPIOD, P6I1_G_Pin, 1);
//		HAL_GPIO_WritePin(GPIOA, P6I1_R_Pin, 0);
//	}
//
//	int p7i2 = HAL_GPIO_ReadPin(GPIOE, P7I2_Pin);
//	if(p7i2==1)
//	{
//		HAL_GPIO_WritePin(GPIOC, P7I2_R_Pin, 1);
//		HAL_GPIO_WritePin(GPIOD, P7I2_G_Pin, 0);
//	}
//	else if(p7i2==0)
//	{
//		HAL_GPIO_WritePin(GPIOD, P7I2_G_Pin, 1);
//		HAL_GPIO_WritePin(GPIOC, P7I2_R_Pin, 0);
//	}



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 250;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_1;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the programming delay
  */
  __HAL_FLASH_SET_PROGRAM_DELAY(FLASH_PROGRAMMING_DELAY_2);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
