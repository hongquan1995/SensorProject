################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/EC_TDS_lib/EC_TDS.c 

OBJS += \
./Core/EC_TDS_lib/EC_TDS.o 

C_DEPS += \
./Core/EC_TDS_lib/EC_TDS.d 


# Each subdirectory must supply rules for building sources it contributes
Core/EC_TDS_lib/EC_TDS.o: ../Core/EC_TDS_lib/EC_TDS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L452xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"D:/SaoViet/project_1/Wsp_Rs485/Sensor/Core/NH3_lib" -I"D:/SaoViet/project_1/Wsp_Rs485/Sensor/Core/L506" -I"D:/SaoViet/project_1/Wsp_Rs485/Sensor/Core/Com_RS485" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/EC_TDS_lib/EC_TDS.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

