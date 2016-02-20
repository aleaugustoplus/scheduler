################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/Wire.cpp 

LINK_OBJ += \
./Libraries/Wire/Wire.cpp.o 

CPP_DEPS += \
./Libraries/Wire/Wire.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Wire/Wire.cpp.o: /home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/Wire.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/home/alexandre/Dados/Ale/Instalações/IDEs/eclipseArduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


