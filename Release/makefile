################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
-include Libraries/Wire/utility/subdir.mk
-include Libraries/Wire/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/arduino.ar \

ELF += \
Scheduler.elf \

EEP += \
Scheduler.eep \

FLASH_IMAGE += \
Scheduler.hex \


# All Target
all: Scheduler

# Tool invocations
Scheduler: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-size" -A "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/Scheduler.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-ar" rcs "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

Scheduler.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/Scheduler.elf"   $(LINK_OBJ) $(AR)  "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/arduino.ar" "-L/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

Scheduler.eep: $(ELF)
	@echo 'Create eeprom image'
	"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/Scheduler.elf" "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/Scheduler.eep"
	@echo 'Finished building: $@'
	@echo ' '

Scheduler.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/Scheduler.elf" "/home/alexandre/Dados/Arduino/workspace_desktop/Scheduler/Release/Scheduler.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(SIZEDUMMY)$(ELF)$(CPP_DEPS) Scheduler
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
