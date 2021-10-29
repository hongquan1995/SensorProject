/*
 * PH1.h
 *
 *  Created on: Oct 9, 2021
 *      Author: 0
 */

#ifndef PH_LIB_PH_H_
#define PH_LIB_PH_H_

#include <stdint.h>

#define 		REG_ADDRESS_TEMP_PH								0x0000
#define 		REG_ADDRESS_VALUE_PH							0x0001
#define 		REG_ADDRESS_TEMPCOMPEN_PH						0x0020
#define 		REG_ADDRESS_PHCALIBRAWAD0						0x0030
#define 		REG_ADDRESS_PHCALIBRAWAD1						0x0031
#define 		REG_ADDRESS_PHCALIBRAWAD2						0x0032
#define 		REG_ADDRESS_SLAVEADD_PH							0x0200
#define 		REG_ADDRESS_BAUDRATE_PH							0x0201
#define 		REG_ADDRESS_PROTOCOL_PH							0x0202
#define 		REG_ADDRESS_PARITY_PH							0x0203
#define 		REG_ADDRESS_DATABITS_PH							0x0204
#define 		REG_ADDRESS_STOPBITS_PH							0x0205
#define 		REG_ADDRESS_RESPONDELAY_PH						0x0206
#define 		REG_ADDRESS_AOI_PH								0x0207

#define 		ADDRESS_SLAVE_PH_DF								0x01
#define 		ADDRESS_SLAVE_PH								0x02
#define			FUNCODE_EC_PH_03								0x03
#define			FUNCODE_EC_PH_04								0x04
#define			FUNCODE_EC_PH_06								0x06
#define			FUNCODE_EC_PH_16								0x10

#define			LENGTH_DATA_PH									1

typedef struct{
	float vr_temp;
	uint16_t vr_ph;
	uint16_t vr_temcomp;
	uint16_t vr_calibrawad0;
	uint16_t vr_calibrawad1;
	uint16_t vr_calibrawad2;
	uint16_t vr_slaAddress;
	uint16_t vr_baudrate;
	uint16_t vr_protocol;
	uint16_t vr_parity;
	uint16_t vr_databits;
	uint16_t vr_stopbits;
	uint16_t vr_responDelay;
	uint16_t vr_aoi;
}read_sensorPh_t;

uint8_t getPHTemperature(float *data);
uint8_t getPH(uint16_t *data);
uint8_t getPHTemcompensateen(uint16_t *data);
uint8_t getPHCalibrawad0(uint16_t *data);
uint8_t getPHCalibrawad1(uint16_t *data);
uint8_t getPHCalibrawad2(uint16_t *data);
uint8_t getPHSlaveaddress(uint16_t *data);
uint8_t getPHBaudrate(uint16_t *data);
uint8_t getPHProtocol(uint16_t *data);
uint8_t getPHParity(uint16_t *data);
uint8_t getPHDatabits(uint16_t *data);
uint8_t getPHStopbits(uint16_t *data);
uint8_t getPHResponsedelay(uint16_t *data);
uint8_t getPHAOI(uint16_t *data);
uint8_t writePHSlvAddress(uint16_t *addReg, uint16_t *data);

#endif /* PH_LIB_PH_H_ */
