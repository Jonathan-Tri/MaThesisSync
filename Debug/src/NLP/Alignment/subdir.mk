################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NLP/Alignment/AlignedDataParsing.cpp \
../src/NLP/Alignment/AlignedSentence.cpp \
../src/NLP/Alignment/testAlignmetParser.cpp 

OBJS += \
./src/NLP/Alignment/AlignedDataParsing.o \
./src/NLP/Alignment/AlignedSentence.o \
./src/NLP/Alignment/testAlignmetParser.o 

CPP_DEPS += \
./src/NLP/Alignment/AlignedDataParsing.d \
./src/NLP/Alignment/AlignedSentence.d \
./src/NLP/Alignment/testAlignmetParser.d 


# Each subdirectory must supply rules for building sources it contributes
src/NLP/Alignment/%.o: ../src/NLP/Alignment/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


