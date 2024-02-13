################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Lumiere.c \
../Src/audio_loopback.c \
../Src/audio_play.c \
../Src/audio_rec.c \
../Src/camera.c \
../Src/eeprom.c \
../Src/fonctions_gestion_ecran.c \
../Src/lcd.c \
../Src/log.c \
../Src/main.c \
../Src/qspi.c \
../Src/sd.c \
../Src/sdram.c \
../Src/sdram_dma.c \
../Src/stm32f7xx_it.c \
../Src/structures.c \
../Src/system_stm32f7xx.c \
../Src/touchscreen.c \
../Src/variables.c 

C_DEPS += \
./Src/Lumiere.d \
./Src/audio_loopback.d \
./Src/audio_play.d \
./Src/audio_rec.d \
./Src/camera.d \
./Src/eeprom.d \
./Src/fonctions_gestion_ecran.d \
./Src/lcd.d \
./Src/log.d \
./Src/main.d \
./Src/qspi.d \
./Src/sd.d \
./Src/sdram.d \
./Src/sdram_dma.d \
./Src/stm32f7xx_it.d \
./Src/structures.d \
./Src/system_stm32f7xx.d \
./Src/touchscreen.d \
./Src/variables.d 

OBJS += \
./Src/Lumiere.o \
./Src/audio_loopback.o \
./Src/audio_play.o \
./Src/audio_rec.o \
./Src/camera.o \
./Src/eeprom.o \
./Src/fonctions_gestion_ecran.o \
./Src/lcd.o \
./Src/log.o \
./Src/main.o \
./Src/qspi.o \
./Src/sd.o \
./Src/sdram.o \
./Src/sdram_dma.o \
./Src/stm32f7xx_it.o \
./Src/structures.o \
./Src/system_stm32f7xx.o \
./Src/touchscreen.o \
./Src/variables.o 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Src

clean-Src:
	-$(RM) ./Src/Lumiere.d ./Src/Lumiere.o ./Src/audio_loopback.d ./Src/audio_loopback.o ./Src/audio_play.d ./Src/audio_play.o ./Src/audio_rec.d ./Src/audio_rec.o ./Src/camera.d ./Src/camera.o ./Src/eeprom.d ./Src/eeprom.o ./Src/fonctions_gestion_ecran.d ./Src/fonctions_gestion_ecran.o ./Src/lcd.d ./Src/lcd.o ./Src/log.d ./Src/log.o ./Src/main.d ./Src/main.o ./Src/qspi.d ./Src/qspi.o ./Src/sd.d ./Src/sd.o ./Src/sdram.d ./Src/sdram.o ./Src/sdram_dma.d ./Src/sdram_dma.o ./Src/stm32f7xx_it.d ./Src/stm32f7xx_it.o ./Src/structures.d ./Src/structures.o ./Src/system_stm32f7xx.d ./Src/system_stm32f7xx.o ./Src/touchscreen.d ./Src/touchscreen.o ./Src/variables.d ./Src/variables.o

.PHONY: clean-Src

