################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Comunication/ISocket.cpp \
../src/Comunication/SocketException.cpp \
../src/Comunication/SocketProtocol.cpp \
../src/Comunication/TCPProtocol.cpp \
../src/Comunication/testTCPClient.cpp \
../src/Comunication/testTCPServer.cpp 

OBJS += \
./src/Comunication/ISocket.o \
./src/Comunication/SocketException.o \
./src/Comunication/SocketProtocol.o \
./src/Comunication/TCPProtocol.o \
./src/Comunication/testTCPClient.o \
./src/Comunication/testTCPServer.o 

CPP_DEPS += \
./src/Comunication/ISocket.d \
./src/Comunication/SocketException.d \
./src/Comunication/SocketProtocol.d \
./src/Comunication/TCPProtocol.d \
./src/Comunication/testTCPClient.d \
./src/Comunication/testTCPServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Comunication/%.o: ../src/Comunication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


