/*
 * my_lib.h
 *
 *  Created on: Sep 28, 2021
 *      Author: 0
 */

#ifndef INC_MY_LIB_H_
#define INC_MY_LIB_H_

#include <stdint.h>
#include "stdbool.h"

#define 		MAX_NUM_OF_BUFFER		256
typedef struct
{
    uint8_t data;
    uint8_t buffer[MAX_NUM_OF_BUFFER];
    uint8_t buffer_index;
}struct_string;


void my_printf(const char *fmt, ...);
void printArray(uint8_t array[],uint16_t len );
void math_reverseBigLittleEndian(uint8_t *data, uint8_t length);
uint8_t convertBcdToDec(uint8_t vrBCD);
bool Check_Time_Out(uint32_t Millstone_Time, uint32_t Time_Period_ms);
uint32_t Cal_Time(uint32_t Millstone_Time, uint32_t Systick_now);
uint32_t Cal_Time_s(uint32_t Millstone_Time, uint32_t Systick_now);

#endif /* INC_MY_LIB_H_ */
