################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/CPU/cpu_utils.c 

C_DEPS += \
./Utilities/CPU/cpu_utils.d 

OBJS += \
./Utilities/CPU/cpu_utils.o 


# Each subdirectory must supply rules for building sources it contributes
Utilities/CPU/%.o: ../Utilities/CPU/%.c Utilities/CPU/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Utilities-2f-CPU

clean-Utilities-2f-CPU:
	-$(RM) ./Utilities/CPU/cpu_utils.d ./Utilities/CPU/cpu_utils.o

.PHONY: clean-Utilities-2f-CPU

