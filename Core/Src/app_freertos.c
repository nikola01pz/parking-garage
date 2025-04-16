#include "app_freertos.h"

#include "main.h"
#include "stdio.h"
#include "liquidcrystal_i2c.h"


extern TIM_HandleTypeDef htim3;

osThreadId_t rampControlTaskHandle;
const osThreadAttr_t rampControlTask_attributes = {
  .name = "rampControlTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

osThreadId_t parkingControlTaskHandle;
const osThreadAttr_t parkingControlTask_attributes = {
  .name = "parkingControlTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};

int main_capacity = 10;
int disabled_capacity = 2;
char string_out[16];

void raise_ramp(char channel);
int check_main_capacity();
int check_disabled_capacity();
void update_availability();


void MX_FREERTOS_Init(void) {

  rampControlTaskHandle = osThreadNew(StartRampControlTask, NULL, &rampControlTask_attributes);

  parkingControlTaskHandle = osThreadNew(StartParkingControlTask, NULL, &parkingControlTask_attributes);

}

void StartRampControlTask(void *argument)
{
	HD44780_Init(2);
	HD44780_Clear();
	int updated = 1;
	int total_capacity = 0;
	int r1, old_r1 = 0;
	int r2 = 0;

	for(;;)
	{

		r1 = HAL_GPIO_ReadPin(GPIOG, RAMP_ENTER_Pin);
		r2 = HAL_GPIO_ReadPin(GPIOB, RAMP_EXIT_Pin);

		if(updated)
		{
			update_availability();

			updated = 0;
		}

		if((r1==1) && (old_r1 != r1))
		{
			if(total_capacity == 12)
			{
				HD44780_Clear();
				HD44780_PrintStr("Parking full");
			} else
			{
				HD44780_Clear();
				HD44780_PrintStr("Welcome.");

				raise_ramp(TIM_CHANNEL_1);
				total_capacity++;
				updated = 1;
			}
		}
		old_r1 = r1;

		if(r2==1)
		{
			HD44780_Clear();
			HD44780_PrintStr("Goodbye.");

			raise_ramp(TIM_CHANNEL_2);
			total_capacity--;
			updated = 1;
		}

	}

}

void StartParkingControlTask(void *argument)
{

	for(;;)
	{
		osDelay(10);
		int new_main_capacity = check_main_capacity();
		if(new_main_capacity != main_capacity)
		{
			main_capacity = new_main_capacity;
			update_availability();
		}

		int new_disabled_capacity = check_disabled_capacity();
		if(new_disabled_capacity != disabled_capacity)
		{
			disabled_capacity = new_disabled_capacity;
			update_availability();
		}
	}

}

void update_availability()
{
	snprintf(string_out, sizeof(string_out), "Main Lot: %d", main_capacity);
	HD44780_Clear();
	HD44780_PrintStr(string_out);
	HD44780_SetCursor(0, 1);
	snprintf(string_out, sizeof(string_out), "Disabled Lot: %d", disabled_capacity);
	HD44780_PrintStr(string_out);
}

int check_disabled_capacity()
{
	int capacity = 2;
	int p11 = HAL_GPIO_ReadPin(GPIOG, P11_Pin);
	if(p11==1)
	{
		HAL_GPIO_WritePin(GPIOG, P11_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, P11_G_Pin, 0);
		capacity--;
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
		capacity--;
	}
	else if(p12==0)
	{
		HAL_GPIO_WritePin(GPIOF, P12_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOF, P12_R_Pin, 0);
	}

	return capacity;
}

int check_main_capacity()
{
	int capacity = 10;

	int p1 = HAL_GPIO_ReadPin(GPIOE, P1_Pin);
	if(p1==1)
	{
		HAL_GPIO_WritePin(GPIOB, P1_R_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, P1_G_Pin, 0);
		capacity--;
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
		capacity--;
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
		capacity--;
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
		capacity--;
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
		capacity--;
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
		capacity--;
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
		capacity--;
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
		capacity--;
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
		capacity--;
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
		capacity--;
	}
	else if(p10==0)
	{
		HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 1);
		HAL_GPIO_WritePin(GPIOD, P10_R_Pin, 0);
	}

	return capacity;
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
