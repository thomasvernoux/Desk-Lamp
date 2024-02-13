################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Log/lcd_log.c 

C_DEPS += \
./Utilities/Log/lcd_log.d 

OBJS += \
./Utilities/Log/lcd_log.o 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Log/%.o: ../Utilities/Log/%.c Utilities/Log/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Utilities-2f-Log

clean-Utilities-2f-Log:
	-$(RM) ./Utilities/Log/lcd_log.d ./Utilities/Log/lcd_log.o

.PHONY: clean-Utilities-2f-Log

