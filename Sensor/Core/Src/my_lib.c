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

extern uint8_t indexBuffer;
extern UART_HandleTypeDef huart1;

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

void wait_receivedata(uint16_t TIMEOUT_WAIT_RX_MS){
	 uint8_t last_indexBuffer = 0;
	 uint16_t timeCount = 0;
	 indexBuffer = 0;
	while(indexBuffer == 0 && timeCount < TIMEOUT_WAIT_RX_MS)// break khi có data, timeout là 200 ms
	{
		 HAL_Delay(1);// 1 ms
		 timeCount++;
	}
	while( last_indexBuffer != indexBuffer) //break khi không còn nhận ở ngắt, toàn bộ rx đã nhận
	{
		 last_indexBuffer = indexBuffer;
		 HAL_Delay(1);
	}
}

uint8_t convertBcdToDec(uint8_t vrBCD){
		uint8_t lowByte = (vrBCD & 0x0F);
		uint8_t highByte = ((vrBCD >> 4) & 0x0F);
		return 	(10*highByte + lowByte);
}
