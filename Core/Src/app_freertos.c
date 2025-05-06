#include "app_freertos.h"

#include "main.h"
#include "stdio.h"
#include "liquidcrystal_i2c.h"


extern TIM_HandleTypeDef htim3;
extern RTC_HandleTypeDef hrtc;

int main_capacity = 10;
int disabled_capacity = 2;
char string_out[16];
char buffer[100];
int parking_timeout[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int parking_started[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;

void raise_ramp(char channel);
void update_availability();

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

void MX_FREERTOS_Init(void) {

  rampControlTaskHandle = osThreadNew(StartRampControlTask, NULL, &rampControlTask_attributes);

  parkingControlTaskHandle = osThreadNew(StartParkingControlTask, NULL, &parkingControlTask_attributes);

}

void StartRampControlTask(void *argument)
{
	int updated = 1;
	int total_capacity = 0;
	int r1, old_r1 = 0;
	int r2 = 0;

	HD44780_Init(2);
	HD44780_Clear();

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
	int parking = 0;
	int timespan = 0;
	int current_time = 0;

	for(;;)
	{
		HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

//		snprintf(buffer, sizeof(buffer), "Time:%02d:%02d:%02d", sTime.Hours, sTime.Minutes, sTime.Seconds);
//		HD44780_Clear();
//		HD44780_PrintStr(buffer);

		int p10 = HAL_GPIO_ReadPin(GPIOF, P10_Pin);
		if(p10==1)
		{


			if(parking_started[9] == 0)
			{
			    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			    parking = sTime.Hours*60*60 + sTime.Minutes*60 + sTime.Seconds;

				parking_started[9] = 1;
				main_capacity--;
			}

			current_time = sTime.Hours*60*60 + sTime.Minutes*60 + sTime.Seconds;
			timespan = current_time - parking;
			if(timespan >=20)
			{
				parking_timeout[9] = 1;
				HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 0);

			} else
			{
				HAL_GPIO_WritePin(GPIOD, P10_R_Pin, 1);
				HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 0);
			}

		}
		else if(p10==0)
		{
			HAL_GPIO_WritePin(GPIOD, P10_G_Pin, 1);
			HAL_GPIO_WritePin(GPIOD, P10_R_Pin, 0);

			parking_started[9] = 0;
			parking_timeout[9] = 0;

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
