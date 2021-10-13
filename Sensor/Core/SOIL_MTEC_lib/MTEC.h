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
#define			REG_ADDRESS_SOILTYPE							0x0020
#define			REG_ADDRESS_TEMPUNIT							0x0021
#define			REG_ADDRESS_ECTEMPCOFF							0x0022
#define			REG_ADDRESS_SALINITYCOFF						0x0023
#define			REG_ADDRESS_TDSCOFF								0x0024
#define			REG_ADDRESS_MODADDRESS							0x0200
#define			REG_ADDRESS_BAUDRATE							0x0201
#define			REG_ADDRESS_PROTOCOL							0x0202
#define			REG_ADDRESS_PARITY								0x0203
#define			REG_ADDRESS_DATABITS							0x0204
#define			REG_ADDRESS_STOPBITS							0x0205
#define			REG_ADDRESS_RESPONSEDELAY						0x0206
#define			REG_ADDRESS_AOI									0x0207


#define 		ADDRESS_SLAVE_MTEC								0x01
#define			FUNCODE_MTEC_03									0x03
#define			FUNCODE_MTEC_04									0x04
#define			FUNCODE_MTEC_06									0x06
#define			FUNCODE_MTEC_16									0x10

#define			LENGTH_DATA										1

#endif /* SOIL_MTEC_LIB_MTEC_H_ */
