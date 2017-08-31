################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FileAdapter/CFileReader.cpp \
../src/FileAdapter/CFileWriter.cpp \
../src/FileAdapter/EFileReader.cpp \
../src/FileAdapter/EFileWriter.cpp \
../src/FileAdapter/FileReaderFactory.cpp \
../src/FileAdapter/FileWriterFactory.cpp \
../src/FileAdapter/testFileReader.cpp \
../src/FileAdapter/testFileWriter.cpp 

OBJS += \
./src/FileAdapter/CFileReader.o \
./src/FileAdapter/CFileWriter.o \
./src/FileAdapter/EFileReader.o \
./src/FileAdapter/EFileWriter.o \
./src/FileAdapter/FileReaderFactory.o \
./src/FileAdapter/FileWriterFactory.o \
./src/FileAdapter/testFileReader.o \
./src/FileAdapter/testFileWriter.o 

CPP_DEPS += \
./src/FileAdapter/CFileReader.d \
./src/FileAdapter/CFileWriter.d \
./src/FileAdapter/EFileReader.d \
./src/FileAdapter/EFileWriter.d \
./src/FileAdapter/FileReaderFactory.d \
./src/FileAdapter/FileWriterFactory.d \
./src/FileAdapter/testFileReader.d \
./src/FileAdapter/testFileWriter.d 


# Each subdirectory must supply rules for building sources it contributes
src/FileAdapter/%.o: ../src/FileAdapter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


