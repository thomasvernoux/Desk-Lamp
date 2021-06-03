################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/audio_loopback.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/audio_play.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/audio_rec.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/camera.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/eeprom.c \
../Example/User/fonctions_gestion_ecran.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/lcd.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/log.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/main.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/qspi.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/sd.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/sdram.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/sdram_dma.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/stm32f7xx_it.c \
../Example/User/structures.c \
C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/touchscreen.c 

OBJS += \
./Example/User/audio_loopback.o \
./Example/User/audio_play.o \
./Example/User/audio_rec.o \
./Example/User/camera.o \
./Example/User/eeprom.o \
./Example/User/fonctions_gestion_ecran.o \
./Example/User/lcd.o \
./Example/User/log.o \
./Example/User/main.o \
./Example/User/qspi.o \
./Example/User/sd.o \
./Example/User/sdram.o \
./Example/User/sdram_dma.o \
./Example/User/stm32f7xx_it.o \
./Example/User/structures.o \
./Example/User/touchscreen.o 

C_DEPS += \
./Example/User/audio_loopback.d \
./Example/User/audio_play.d \
./Example/User/audio_rec.d \
./Example/User/camera.d \
./Example/User/eeprom.d \
./Example/User/fonctions_gestion_ecran.d \
./Example/User/lcd.d \
./Example/User/log.d \
./Example/User/main.d \
./Example/User/qspi.d \
./Example/User/sd.d \
./Example/User/sdram.d \
./Example/User/sdram_dma.d \
./Example/User/stm32f7xx_it.d \
./Example/User/structures.d \
./Example/User/touchscreen.d 


# Each subdirectory must supply rules for building sources it contributes
Example/User/audio_loopback.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/audio_loopback.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/audio_loopback.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/audio_play.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/audio_play.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/audio_play.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/audio_rec.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/audio_rec.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/audio_rec.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/camera.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/camera.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/camera.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/eeprom.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/eeprom.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/eeprom.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/fonctions_gestion_ecran.o: ../Example/User/fonctions_gestion_ecran.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/fonctions_gestion_ecran.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/lcd.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/lcd.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/log.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/log.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/log.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/main.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/main.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/qspi.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/qspi.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/qspi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/sd.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/sd.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/sdram.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/sdram.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/sdram.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/sdram_dma.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/sdram_dma.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/sdram_dma.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/stm32f7xx_it.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/stm32f7xx_it.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/stm32f7xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/structures.o: ../Example/User/structures.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/structures.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/touchscreen.o: C:/Users/thoma/Downloads/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP-15428a16c978f9f26913fcaae80ce614fb78d6b8/BSP/Src/touchscreen.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Drivers/CMSIS/Include -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Example/User/touchscreen.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

