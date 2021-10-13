/*
 * CO2.h
 *
 *  Created on: Oct 1, 2021
 *      Author: 0
 */

#ifndef CO2_LIB_CO2_H_
#define CO2_LIB_CO2_H_


#define 		REG_ADDRESS_CO2							0x0000
#define 		REG_ADDRESS_VER							0x0007
#define 		REG_ADDRESS_SLA							0x0010
#define 		REG_ADDRESS_BAURATE						0x0011
#define 		REG_ADDRESS_PARITY						0x0012
#define 		REG_ADDRESS_STOPBIT						0x0013
#define 		REG_ADDRESS_PROTOCOL					0x0014
#define 		REG_ADDRESS_DELAYRESPOND				0x0020
#define 		REG_ADDRESS_WARMUPTIME					0x0021



#define 		TRUE										1
#define			FALSE										0

#define 		ADDRESS_SLAVE_CO2							0x01
#define			FUNCODE_CO2_03								0x03
#define			FUNCODE_CO2_04								0x04
#define			FUNCODE_CO2_06								0x06
#define			FUNCODE_CO2_16								0x10

#define			LENGTH_DATA									1


#endif /* CO2_LIB_CO2_H_ */


