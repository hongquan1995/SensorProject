/*
 * MTEC.h
 *
 *  Created on: Oct 12, 2021
 *      Author: 0
 */

#ifndef SOIL_MTEC_LIB_MTEC_H_
#define SOIL_MTEC_LIB_MTEC_H_

#define 		REG_ADDRESS_TEMPERATURE							0x0000
#define 		REG_ADDRESS_VWC									0x0001
#define 		REG_ADDRESS_EC									0x0002
#define			REG_ADDRESS_SALINITY							0x0003
#define			REG_ADDRESS_TDS									0x0004
#define			REG_ADDRESS_EPSILON								0x0005


#define 		ADDRESS_SLAVE_MTEC								0x01
#define			FUNCODE_MTEC_03									0x03
#define			FUNCODE_MTEC_04									0x04
#define			FUNCODE_MTEC_06									0x06
#define			FUNCODE_MTEC_16									0x10

#define			LENGTH_DATA										1

#endif /* SOIL_MTEC_LIB_MTEC_H_ */
