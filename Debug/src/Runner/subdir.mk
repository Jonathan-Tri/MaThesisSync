################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Runner/main.cpp 

OBJS += \
./src/Runner/main.o 

CPP_DEPS += \
./src/Runner/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/Runner/%.o: ../src/Runner/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


