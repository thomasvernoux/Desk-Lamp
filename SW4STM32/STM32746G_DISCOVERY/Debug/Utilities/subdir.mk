################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Utilities/Log/lcd_log.c 

OBJS += \
./Utilities/lcd_log.o 

C_DEPS += \
./Utilities/lcd_log.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/lcd_log.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Utilities/Log/lcd_log.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/lcd_log.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

