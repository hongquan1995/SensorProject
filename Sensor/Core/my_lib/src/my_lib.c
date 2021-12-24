/*
 * my_lib.c
 *
 *  Created on: Sep 28, 2021
 *      Author: 0
 */


#include "stm32l4xx_hal.h"
#include <stdio.h>
#include <string.h>
#include "stdint.h"
#include <stdarg.h>
#include <my_lib.h>
#include "cmsis_os.h"
#include "stdbool.h"

#define 		MAX_NUM_OF_BUFFER		256

extern UART_HandleTypeDef huart1;
extern struct_string gsm_sensor;
uint32_t RT_Count_Systick_u32;

void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string,fmt,argp)) // build string
    {
        HAL_UART_Transmit(&huart1, (uint8_t*)string, strlen(string), 0xffffff); // send message via UART
    }
}

void my_printf(const char *fmt, ...) // custom printf() function
{
    va_list argp;
    va_start(argp, fmt);
    vprint(fmt, argp);
    va_end(argp);
}

void printArray(uint8_t array[],uint16_t len ) {
	if (0 == len) {
		my_printf("");
		return;
	}

	uint8_t loop = 0;
	for (loop = 0; loop < len; loop++) {
		my_printf("%02X ", array[loop]);
	}
	my_printf("\r\n");
}

void math_reverseBigLittleEndian(uint8_t *data, uint8_t length) {
	for (int i = 0; i < length / 2; i++) {
		uint8_t bTmp = data[i];

		data[i] = data[length - 1 - i];
		data[length - 1 - i] = bTmp;
	}
}

uint8_t convertBcdToDec(uint8_t vrBCD){
		uint8_t lowByte = (vrBCD & 0x0F);
		uint8_t highByte = ((vrBCD >> 4) & 0x0F);
		return 	(10*highByte + lowByte);
}

// return = 1 : time_run >= time period
//				= 0 : don't need check time || not time out
bool Check_Time_Out(uint32_t Millstone_Time, uint32_t Time_Period_ms)
{
	if (Millstone_Time == 0) return 0;

	if (Cal_Time(Millstone_Time,RT_Count_Systick_u32) >= Time_Period_ms) return 1;

	return 0;
}

// Return : ms - time period (count Systick Timer)
uint32_t Cal_Time(uint32_t Millstone_Time, uint32_t Systick_now)
{
	if (Systick_now < Millstone_Time)
		return (0xFFFFFFFF - Millstone_Time + Systick_now);
	return (Systick_now - Millstone_Time);
}

// Return : second - time period (count Systick Timer)
uint32_t Cal_Time_s(uint32_t Millstone_Time, uint32_t Systick_now)
{
	if (Systick_now < Millstone_Time)
		return ((0xFFFFFFFF - Millstone_Time + Systick_now)/1000);
	return ((Systick_now - Millstone_Time)/1000);
}
