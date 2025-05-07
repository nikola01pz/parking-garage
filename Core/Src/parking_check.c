/*
 * parking_check.c
 *
 *  Created on: May 7, 2025
 *      Author: Nikola
 */

#include "parking_check.h"
#include "main.h"

#define TIME_LIMIT 30

extern int current_seconds;
extern int parking_started[12];
extern int parking_time[12];
extern int parking_timeout[12];

void check_parking1()
{
	int parking = HAL_GPIO_ReadPin(GPIOE, P1_Pin);

	if(parking == 1)
	{

		if(parking_started[0] == 0)
		{
			parking_time[0] = current_seconds;
			parking_started[0] = 1;
		}

		int timespan = current_seconds - parking_time[7];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[0] = 1;
			HAL_GPIO_WritePin(GPIOA, P1_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOB, P1_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, P1_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOB, P1_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, P1_G_Pin, 1);

		parking_started[0] = 0;
		parking_timeout[0] = 0;
	}
}

void check_parking2()
{
	int parking = HAL_GPIO_ReadPin(GPIOB, P2_Pin);

	if(parking == 1)
	{

		if(parking_started[1] == 0)
		{
			parking_time[1] = current_seconds;
			parking_started[1] = 1;
		}

		int timespan = current_seconds - parking_time[8];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[1] = 1;
			HAL_GPIO_WritePin(GPIOE, P2_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOA, P2_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOE, P2_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOA, P2_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOE, P2_G_Pin, 1);

		parking_started[1] = 0;
		parking_timeout[1] = 0;
	}
}

void check_parking3()
{
	int parking = HAL_GPIO_ReadPin(GPIOD, P3_Pin);

	if(parking == 1)
	{

		if(parking_started[2] == 0)
		{
			parking_time[2] = current_seconds;
			parking_started[2] = 1;
		}

		int timespan = current_seconds - parking_time[2];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[2] = 1;
			HAL_GPIO_WritePin(GPIOE, P3_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOE, P3_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOE, P3_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOE, P3_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOE, P3_G_Pin, 1);

		parking_started[2] = 0;
		parking_timeout[2] = 0;
	}
}

void check_parking4()
{
	int parking = HAL_GPIO_ReadPin(GPIOD, P4_Pin);

	if(parking == 1)
	{

		if(parking_started[3] == 0)
		{
			parking_time[3] = current_seconds;
			parking_started[3] = 1;
		}

		int timespan = current_seconds - parking_time[3];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[3] = 1;
			HAL_GPIO_WritePin(GPIOE, P4_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOE, P4_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOE, P4_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOE, P4_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOE, P4_G_Pin, 1);

		parking_started[3] = 0;
		parking_timeout[3] = 0;
	}
}

void check_parking5()
{
	int parking = HAL_GPIO_ReadPin(GPIOB, P5_Pin);

	if(parking == 1)
	{

		if(parking_started[4] == 0)
		{
			parking_time[4] = current_seconds;
			parking_started[4] = 1;
		}

		int timespan = current_seconds - parking_time[4];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[4] = 1;
			HAL_GPIO_WritePin(GPIOE, P5_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOD, P5_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOE, P5_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOD, P5_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOE, P5_G_Pin, 1);

		parking_started[4] = 0;
		parking_timeout[4] = 0;
	}
}

void check_parking6()
{
	int parking = HAL_GPIO_ReadPin(GPIOB, P6_Pin);

	if(parking == 1)
	{

		if(parking_started[5] == 0)
		{
			parking_time[5] = current_seconds;
			parking_started[5] = 1;
		}

		int timespan = current_seconds - parking_time[5];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[5] = 1;
			HAL_GPIO_WritePin(GPIOA, P6_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOB, P6_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, P6_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOB, P6_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, P6_G_Pin, 1);

		parking_started[5] = 0;
		parking_timeout[5] = 0;
	}
}

void check_parking7()
{
	int parking = HAL_GPIO_ReadPin(GPIOF, P7_Pin);

	if(parking == 1)
	{

		if(parking_started[6] == 0)
		{
			parking_time[6] = current_seconds;
			parking_started[6] = 1;
		}

		int timespan = current_seconds - parking_time[6];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[6] = 1;
			HAL_GPIO_WritePin(GPIOG, P7_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOF, P7_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOG, P7_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOF, P7_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOG, P7_G_Pin, 1);

		parking_started[6] = 0;
		parking_timeout[6] = 0;
	}
}

void check_parking8()
{
	int parking = HAL_GPIO_ReadPin(GPIOE, P8_Pin);

	if(parking == 1)
	{

		if(parking_started[7] == 0)
		{
			parking_time[7] = current_seconds;
			parking_started[7] = 1;
		}

		int timespan = current_seconds - parking_time[7];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[7] = 1;
			HAL_GPIO_WritePin(GPIOG, P8_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOE, P8_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOG, P8_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOE, P8_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOG, P8_G_Pin, 1);

		parking_started[7] = 0;
		parking_timeout[7] = 0;
	}
}

void check_parking9()
{
	int parking = HAL_GPIO_ReadPin(GPIOE, P9_Pin);

	if(parking == 1)
	{

		if(parking_started[8] == 0)
		{
			parking_time[8] = current_seconds;
			parking_started[8] = 1;
		}

		int timespan = current_seconds - parking_time[8];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[8] = 1;
			HAL_GPIO_WritePin(GPIOG, P9_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOE, P9_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOG, P9_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOE, P9_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOG, P9_G_Pin, 1);

		parking_started[8] = 0;
		parking_timeout[8] = 0;
	}
}


void check_parking10()
{
	int parking = HAL_GPIO_ReadPin(GPIOF, P10_Pin);

	if(parking == 1)
	{

		if(parking_started[9] == 0)
		{
			parking_time[9] = current_seconds;
			parking_started[9] = 1;
		}

		int timespan = current_seconds - parking_time[9];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[9] = 1;
			HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOD, P10_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOD, P10_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 1);

		parking_started[9] = 0;
		parking_timeout[9] = 0;
	}
}

void check_parking11()
{
	int parking = HAL_GPIO_ReadPin(GPIOG, P11_Pin);

	if(parking == 1)
	{

		if(parking_started[10] == 0)
		{
			parking_time[10] = current_seconds;
			parking_started[10] = 1;
		}

		int timespan = current_seconds - parking_time[10];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[10] = 1;
			HAL_GPIO_WritePin(GPIOD, P11_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOG, P11_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, P11_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOG, P11_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOD, P11_G_Pin, 1);

		parking_started[10] = 0;
		parking_timeout[10] = 0;
	}
}

void check_parking12()
{
	int parking = HAL_GPIO_ReadPin(GPIOD, P12_Pin);

	if(parking == 1)
	{

		if(parking_started[11] == 0)
		{
			parking_time[11] = current_seconds;
			parking_started[11] = 1;
		}

		int timespan = current_seconds - parking_time[11];
		if(timespan >= TIME_LIMIT)
		{
			parking_timeout[11] = 1;
			HAL_GPIO_WritePin(GPIOF, P12_G_Pin, 0);

		} else
		{
			HAL_GPIO_WritePin(GPIOF, P12_R_Pin, 1);
			HAL_GPIO_WritePin(GPIOF, P12_G_Pin, 0);
		}

	}
	else if(parking==0)
	{
		HAL_GPIO_WritePin(GPIOF, P12_R_Pin, 0);
		HAL_GPIO_WritePin(GPIOF, P12_G_Pin, 1);

		parking_started[11] = 0;
		parking_timeout[11] = 0;
	}
}
