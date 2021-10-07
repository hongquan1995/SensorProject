################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/CO2_lib/CO2.c 

OBJS += \
./Core/CO2_lib/CO2.o 

C_DEPS += \
./Core/CO2_lib/CO2.d 


# Each subdirectory must supply rules for building sources it contributes
Core/CO2_lib/CO2.o: ../Core/CO2_lib/CO2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L452xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"D:/SaoViet/project_1/Wsp_Rs485/Sensor/Core/NH3_lib" -I"D:/SaoViet/project_1/Wsp_Rs485/Sensor/Core/L506" -I"D:/SaoViet/project_1/Wsp_Rs485/Sensor/Core/Com_RS485" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/CO2_lib/CO2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

