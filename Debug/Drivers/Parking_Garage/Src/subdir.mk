################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Parking_Garage/Src/i2c-lcd.c 

OBJS += \
./Drivers/Parking_Garage/Src/i2c-lcd.o 

C_DEPS += \
./Drivers/Parking_Garage/Src/i2c-lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Parking_Garage/Src/%.o Drivers/Parking_Garage/Src/%.su Drivers/Parking_Garage/Src/%.cyclo: ../Drivers/Parking_Garage/Src/%.c Drivers/Parking_Garage/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Parking_Garage-2f-Src

clean-Drivers-2f-Parking_Garage-2f-Src:
	-$(RM) ./Drivers/Parking_Garage/Src/i2c-lcd.cyclo ./Drivers/Parking_Garage/Src/i2c-lcd.d ./Drivers/Parking_Garage/Src/i2c-lcd.o ./Drivers/Parking_Garage/Src/i2c-lcd.su

.PHONY: clean-Drivers-2f-Parking_Garage-2f-Src

