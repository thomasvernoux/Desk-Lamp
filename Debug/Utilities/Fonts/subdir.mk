################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Fonts/font12.c \
../Utilities/Fonts/font16.c \
../Utilities/Fonts/font20.c \
../Utilities/Fonts/font24.c \
../Utilities/Fonts/font8.c 

C_DEPS += \
./Utilities/Fonts/font12.d \
./Utilities/Fonts/font16.d \
./Utilities/Fonts/font20.d \
./Utilities/Fonts/font24.d \
./Utilities/Fonts/font8.d 

OBJS += \
./Utilities/Fonts/font12.o \
./Utilities/Fonts/font16.o \
./Utilities/Fonts/font20.o \
./Utilities/Fonts/font24.o \
./Utilities/Fonts/font8.o 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Fonts/%.o: ../Utilities/Fonts/%.c Utilities/Fonts/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Utilities-2f-Fonts

clean-Utilities-2f-Fonts:
	-$(RM) ./Utilities/Fonts/font12.d ./Utilities/Fonts/font12.o ./Utilities/Fonts/font16.d ./Utilities/Fonts/font16.o ./Utilities/Fonts/font20.d ./Utilities/Fonts/font20.o ./Utilities/Fonts/font24.d ./Utilities/Fonts/font24.o ./Utilities/Fonts/font8.d ./Utilities/Fonts/font8.o

.PHONY: clean-Utilities-2f-Fonts

