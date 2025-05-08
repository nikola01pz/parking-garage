#include "app_freertos.h"

#include "main.h"
#include "stdio.h"
#include "liquidcrystal_i2c.h"
#include "parking_check.h"

#define MAX_CAPACITY 4

extern TIM_HandleTypeDef htim3;
extern RTC_HandleTypeDef hrtc;

int main_capacity = 10;
int disabled_capacity = 2;
char display_out[16];
char buffer[32];
char old_buffer[32];

int current_seconds = 0;
int parking_started[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int parking_time[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int parking_timeout[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;

void raise_ramp(char channel);
void update_availability();
int check_main_capacity();
int check_disabled_capacity();
void check_capacity();

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
			if(total_capacity == MAX_CAPACITY)
			{
				HD44780_Clear();
				HD44780_PrintStr("Parking full.");
			} else
			{
				HD44780_Clear();
				HD44780_PrintStr("Welcome.");

				raise_ramp(TIM_CHANNEL_2);
				total_capacity++;
				updated = 1;
			}
		}
		old_r1 = r1;

		if(r2==1)
		{
			HD44780_Clear();
			HD44780_PrintStr("Goodbye.");

			raise_ramp(TIM_CHANNEL_1);
			total_capacity--;
			updated = 1;
		}

	}

}

void StartParkingControlTask(void *argument)
{

	for(;;)
	{
		HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
		current_seconds = sTime.Hours * 3600 + sTime.Minutes * 60 + sTime.Seconds;

		check_capacity();

		check_parking1();
		check_parking2();
		check_parking3();
		check_parking4();
		check_parking5();
		check_parking6();
		check_parking7();
		check_parking8();
		check_parking9();
		check_parking10();
		check_parking11();
		check_parking12();
	}

}

void check_capacity()
{
	static int old_main = 0;
	static int old_disabled = 0;

    main_capacity = check_main_capacity();
	if(old_main != main_capacity)
	{
		update_availability();
	    old_main = main_capacity;
	}

    disabled_capacity = check_disabled_capacity();
	if(old_disabled != disabled_capacity)
	{
		update_availability();
		old_disabled = disabled_capacity;
	}
}

int check_main_capacity()
{
	int capacity[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	capacity[0] = HAL_GPIO_ReadPin(GPIOE, P1_Pin);
	capacity[1] = HAL_GPIO_ReadPin(GPIOB, P2_Pin);
	capacity[2] = HAL_GPIO_ReadPin(GPIOD, P3_Pin);
	capacity[3] = HAL_GPIO_ReadPin(GPIOD, P4_Pin);
	capacity[4] = HAL_GPIO_ReadPin(GPIOB, P5_Pin);
	capacity[5] = HAL_GPIO_ReadPin(GPIOB, P6_Pin);
	capacity[6] = HAL_GPIO_ReadPin(GPIOF, P7_Pin);
	capacity[7] = HAL_GPIO_ReadPin(GPIOE, P8_Pin);
	capacity[8] = HAL_GPIO_ReadPin(GPIOE, P9_Pin);
	capacity[9] = HAL_GPIO_ReadPin(GPIOF, P10_Pin);

	int temp = 10;
	for(int i = 0; i < 10; i++)
	{
		if(capacity[i] == 1)
			temp--;
	}


	return temp;
}

int check_disabled_capacity()
{
	int capacity[2] = {0, 0};

	capacity[0] = HAL_GPIO_ReadPin(GPIOG, P11_Pin);
	capacity[1] = HAL_GPIO_ReadPin(GPIOD, P12_Pin);

	int temp = 2;
	for(int i = 0; i < 2; i++)
	{
		if(capacity[i] == 1)
			temp--;
	}


	return temp;
}

void update_availability()
{
	snprintf(display_out, sizeof(display_out), "Main Lot: %d", main_capacity);
	HD44780_Clear();
	HD44780_PrintStr(display_out);
	HD44780_SetCursor(0, 1);
	snprintf(display_out, sizeof(display_out), "Disabled Lot: %d", disabled_capacity);
	HD44780_PrintStr(display_out);
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
