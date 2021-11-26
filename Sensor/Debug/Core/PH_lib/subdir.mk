################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/PH_lib/PH.c 

OBJS += \
./Core/PH_lib/PH.o 

C_DEPS += \
./Core/PH_lib/PH.d 


# Each subdirectory must supply rules for building sources it contributes
Core/PH_lib/PH.o: ../Core/PH_lib/PH.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L452xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/NH3_lib" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/L506" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/Com_RS485" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/CO2_lib" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/EC_TDS_lib" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/H2S_lib" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/PAR_lib" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/PH_lib" -I"D:/SaoViet/git_clone/Sensor_sourcetree/Sensor/Core/SOIL_MTEC_lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/PH_lib/PH.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

