/*
 * MTEC.h
 *
 *  Created on: Oct 12, 2021
 *      Author: 0
 */

#ifndef SOIL_MTEC_LIB_MTEC_H_
#define SOIL_MTEC_LIB_MTEC_H_
#include "stdint.h"

#define 		REG_ADDRESS_TEMP_MTEC							0x0000
#define 		REG_ADDRESS_VWC_MTEC							0x0001
#define 		REG_ADDRESS_EC_MTEC								0x0002
#define			REG_ADDRESS_SALINITY_MTEC						0x0003
#define			REG_ADDRESS_TDS_MTEC							0x0004
#define			REG_ADDRESS_EPSILON_MTEC						0x0005
#define			REG_ADDRESS_SOILTYPE_MTEC						0x0020
#define			REG_ADDRESS_TEMPUNIT_MTEC						0x0021
#define			REG_ADDRESS_ECTEMPCOFF_MTEC						0x0022
#define			REG_ADDRESS_SALINITYCOFF_MTEC					0x0023
#define			REG_ADDRESS_TDSCOFF_MTEC						0x0024
#define			REG_ADDRESS_MODADDRESS_MTEC						0x0200
#define			REG_ADDRESS_BAUDRATE_MTEC						0x0201
#define			REG_ADDRESS_PROTOCOL_MTEC						0x0202
#define			REG_ADDRESS_PARITY_MTEC							0x0203
#define			REG_ADDRESS_DATABITS_MTEC						0x0204
#define			REG_ADDRESS_STOPBITS_MTEC						0x0205
#define			REG_ADDRESS_RESPONDELAY_MTEC					0x0206
#define			REG_ADDRESS_AOI_MTEC							0x0207

#define 		ADDRESS_SLAVE_MTEC								0x06

#define			LENGTH_DATA_MTEC								1

typedef struct{
	float vr_temp;
	uint16_t vr_ph;
	uint16_t vr_vwc;
	uint16_t vr_ec;
	uint16_t vr_salinity;
	uint16_t vr_tds;
	uint16_t vr_epsilon;
	uint16_t vr_tempunit;
	uint16_t vr_ectemcoff;
	uint16_t vr_salinitycoff;
	uint16_t vr_tdscoff;
	uint16_t vr_slaAddress;
	uint16_t vr_baudrate;
	uint16_t vr_protocol;
	uint16_t vr_parity;
	uint16_t vr_databits;
	uint16_t vr_stopbits;
	uint16_t vr_responDelay;
	uint16_t vr_aoi;
}read_sensorMtec_t;

void SOIL_MTEC_getFloatData(uint8_t *rawData, float *vrData);
void SOIL_MTEC_getUint16Data(uint8_t *rawData, uint16_t *vrData);
#endif /* SOIL_MTEC_LIB_MTEC_H_ */
