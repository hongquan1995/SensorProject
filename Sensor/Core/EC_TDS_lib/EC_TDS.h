/*
 * EC_TDS.h
 *
 *  Created on: Sep 29, 2021
 *      Author: 0
 */

#ifndef EC_TDS_LIB_EC_TDS_H_
#define EC_TDS_LIB_EC_TDS_H_

#define 		REG_ADDRESS_TEMPERATURE							0x0000
#define 		REG_ADDRESS_EC									0x0002
#define 		REG_ADDRESS_SALINITY							0x0003
#define			REG_ADDRESS_TDS									0x0004
#define			REG_ADDRESS_ECRAWAD								0x0008
#define			REG_ADDRESS_TEMPCOMPENSATEEN					0x0020
#define			REG_ADDRESS_ECTEMPCOFF							0x0022
#define			REG_ADDRESS_SALINITYCOFF						0x0023
#define			REG_ADDRESS_TDSCOFF								0x0024
#define			REG_ADDRESS_ELECTRODECONSTANT					0x0025
#define			REG_ADDRESS_ECCALIB_1413						0x0030
#define			REG_ADDRESS_ECCALIB_12880						0x0031
#define			REG_ADDRESS_SLAVEADDRESS						0x0200
#define			REG_ADDRESS_BAUDRATE							0x0201
#define			REG_ADDRESS_PROTOCOL							0x0202
#define			REG_ADDRESS_PARITY								0x0203
#define			REG_ADDRESS_DATABITS							0x0204
#define			REG_ADDRESS_STOPBITS							0x0205
#define			REG_ADDRESS_RESPONSEDELAY						0x0206
#define			REG_ADDRESS_ACTIVEOUTPUTINTERVAL				0x0207

#define 		ADDRESS_SLAVE_EC_TDS							0x01
#define			FUNCODE_EC_TDS_03								0x03
#define			FUNCODE_EC_TDS_04								0x04
#define			FUNCODE_EC_TDS_06								0x06
#define			FUNCODE_EC_TDS_16								0x10

#define			LENGTH_DATA										1


#endif /* EC_TDS_LIB_EC_TDS_H_ */
