/*
 * my_lib.h
 *
 *  Created on: Sep 28, 2021
 *      Author: 0
 */

#ifndef INC_MY_LIB_H_
#define INC_MY_LIB_H_

#include <stdint.h>

void my_printf(const char *fmt, ...);
void printArray(uint8_t array[],uint16_t len );
void math_reverseBigLittleEndian(uint8_t *data, uint8_t length);
void wait_receivedata(uint16_t TIMEOUT_WAIT_RX_MS);
uint8_t convertBcdToDec(uint8_t vrBCD);

#endif /* INC_MY_LIB_H_ */
