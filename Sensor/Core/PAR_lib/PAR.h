/*
 * PAR.h
 *
 *  Created on: Oct 12, 2021
 *      Author: 0
 */

#ifndef PAR_LIB_PAR_H_
#define PAR_LIB_PAR_H_

#define 		REG_ADDRESS_PAR								0x0000

#define 		TRUE										1
#define			FALSE										0
#define			FUNCODE_COMMON_PAR							3
#define 		ADDRESS_SLAVE_PAR							0x05

#define			LENGTH_DATA_PAR								1

float dataPAR;

uint8_t getPAR(float *data);

#endif /* PAR_LIB_PAR_H_ */
