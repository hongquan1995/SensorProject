/*
 * PH1.h
 *
 *  Created on: Oct 9, 2021
 *      Author: 0
 */

#ifndef PH_LIB_PH1_H_
#define PH_LIB_PH1_H_

#define 		REG_ADDRESS_TEMPERATURE							0x0000
#define 		REG_ADDRESS_PHVALUE								0x0001


#define 		ADDRESS_SLAVE_PH								0x01
#define			FUNCODE_EC_PH_03								0x03
#define			FUNCODE_EC_PH_04								0x04
#define			FUNCODE_EC_PH_06								0x06
#define			FUNCODE_EC_PH_16								0x10

#define			LENGTH_DATA										1

void getPHTemperature(float *data);
void getPH(uint16_t *data);

#endif /* PH_LIB_PH1_H_ */
