################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NLP/Grammar/Rule.cpp 

OBJS += \
./src/NLP/Grammar/Rule.o 

CPP_DEPS += \
./src/NLP/Grammar/Rule.d 


# Each subdirectory must supply rules for building sources it contributes
src/NLP/Grammar/%.o: ../src/NLP/Grammar/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


