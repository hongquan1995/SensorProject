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

#define 		ADDRESS_SLAVE_PH								0x01

#define			LENGTH_DATA_PH									1

typedef struct{
	float vr_temp;
	float vr_ph;
	uint16_t vr_temcomp;
	int vr_calibrawad0;
	int vr_calibrawad1;
	int vr_calibrawad2;
	uint16_t vr_slaAddress;
	uint16_t vr_baudrate;
	uint16_t vr_protocol;
	uint16_t vr_parity;
	uint16_t vr_databits;
	uint16_t vr_stopbits;
	uint16_t vr_responDelay;
	uint16_t vr_aoi;
}read_sensorPh_t;

void PH_getFloatData(uint8_t *rawData, float *vrData);
void PH_getIntData(uint8_t *rawData, int *vrData);
void PH_getUint16Data(uint8_t *rawData, uint16_t *vrData);

#endif /* PH_LIB_PH_H_ */
