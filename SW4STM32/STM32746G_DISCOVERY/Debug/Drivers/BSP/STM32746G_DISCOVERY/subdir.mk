################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c 

OBJS += \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_audio.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_camera.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_eeprom.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_lcd.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_qspi.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sd.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sdram.o \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_audio.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_camera.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_eeprom.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_lcd.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_qspi.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sd.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sdram.d \
./Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_audio.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_audio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_camera.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_camera.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_eeprom.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_eeprom.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_lcd.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_qspi.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_qspi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sd.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sdram.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_sdram.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_ts.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c Drivers/BSP/STM32746G_DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32746G_DISCOVERY/stm32746g_discovery_ts.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

