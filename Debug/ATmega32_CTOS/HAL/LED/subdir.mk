################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ATmega32_CTOS/HAL/LED/LED_config.c \
../ATmega32_CTOS/HAL/LED/LED_prog.c 

OBJS += \
./ATmega32_CTOS/HAL/LED/LED_config.o \
./ATmega32_CTOS/HAL/LED/LED_prog.o 

C_DEPS += \
./ATmega32_CTOS/HAL/LED/LED_config.d \
./ATmega32_CTOS/HAL/LED/LED_prog.d 


# Each subdirectory must supply rules for building sources it contributes
ATmega32_CTOS/HAL/LED/%.o: ../ATmega32_CTOS/HAL/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


