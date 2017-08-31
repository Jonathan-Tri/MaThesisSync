################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NLP/ParsedTree/Node.cpp \
../src/NLP/ParsedTree/ParserTree.cpp \
../src/NLP/ParsedTree/ParserTreeReader.cpp \
../src/NLP/ParsedTree/testParsedTree.cpp \
../src/NLP/ParsedTree/testParserFileReader.cpp 

OBJS += \
./src/NLP/ParsedTree/Node.o \
./src/NLP/ParsedTree/ParserTree.o \
./src/NLP/ParsedTree/ParserTreeReader.o \
./src/NLP/ParsedTree/testParsedTree.o \
./src/NLP/ParsedTree/testParserFileReader.o 

CPP_DEPS += \
./src/NLP/ParsedTree/Node.d \
./src/NLP/ParsedTree/ParserTree.d \
./src/NLP/ParsedTree/ParserTreeReader.d \
./src/NLP/ParsedTree/testParsedTree.d \
./src/NLP/ParsedTree/testParserFileReader.d 


# Each subdirectory must supply rules for building sources it contributes
src/NLP/ParsedTree/%.o: ../src/NLP/ParsedTree/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


