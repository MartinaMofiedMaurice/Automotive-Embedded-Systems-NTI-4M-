################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXIT_INT_DRIVER_NTI/EXIT_INT_Program.c 

OBJS += \
./MCAL/EXIT_INT_DRIVER_NTI/EXIT_INT_Program.o 

C_DEPS += \
./MCAL/EXIT_INT_DRIVER_NTI/EXIT_INT_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXIT_INT_DRIVER_NTI/%.o: ../MCAL/EXIT_INT_DRIVER_NTI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


