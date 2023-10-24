################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
KEYPAD_DRIVER_NTI.lss \

FLASH_IMAGE += \
KEYPAD_DRIVER_NTI.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KEYPAD_DRIVER_NTI.elf secondary-outputs

# Tool invocations
KEYPAD_DRIVER_NTI.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KEYPAD_DRIVER_NTI.map -mmcu=atmega32 -o "KEYPAD_DRIVER_NTI.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KEYPAD_DRIVER_NTI.lss: KEYPAD_DRIVER_NTI.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KEYPAD_DRIVER_NTI.elf  >"KEYPAD_DRIVER_NTI.lss"
	@echo 'Finished building: $@'
	@echo ' '

KEYPAD_DRIVER_NTI.hex: KEYPAD_DRIVER_NTI.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KEYPAD_DRIVER_NTI.elf  "KEYPAD_DRIVER_NTI.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KEYPAD_DRIVER_NTI.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KEYPAD_DRIVER_NTI.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KEYPAD_DRIVER_NTI.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
