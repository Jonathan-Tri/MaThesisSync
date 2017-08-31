################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NLP/Analysis/TreeletExt.cpp 

OBJS += \
./src/NLP/Analysis/TreeletExt.o 

CPP_DEPS += \
./src/NLP/Analysis/TreeletExt.d 


# Each subdirectory must supply rules for building sources it contributes
src/NLP/Analysis/%.o: ../src/NLP/Analysis/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


