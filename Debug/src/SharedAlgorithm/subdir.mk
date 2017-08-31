################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SharedAlgorithm/SharedAlgorithm.cpp \
../src/SharedAlgorithm/logging.cpp 

OBJS += \
./src/SharedAlgorithm/SharedAlgorithm.o \
./src/SharedAlgorithm/logging.o 

CPP_DEPS += \
./src/SharedAlgorithm/SharedAlgorithm.d \
./src/SharedAlgorithm/logging.d 


# Each subdirectory must supply rules for building sources it contributes
src/SharedAlgorithm/%.o: ../src/SharedAlgorithm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


