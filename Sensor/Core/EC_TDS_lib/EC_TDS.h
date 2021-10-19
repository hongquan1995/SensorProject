/*
 * EC_TDS.h
 *
 *  Created on: Sep 29, 2021
 *      Author: 0
 */

#ifndef EC_TDS_LIB_EC_TDS_H_
#define EC_TDS_LIB_EC_TDS_H_

#define 		REG_ADDRESS_TEMP_ECTDS							0x0000
#define 		REG_ADDRESS_EC_ECTDS							0x0002
#define 		REG_ADDRESS_SALINITY_ECTDS						0x0003
#define			REG_ADDRESS_TDS_ECTDS							0x0004
#define			REG_ADDRESS_ECRAWAD_ECTDS						0x0008
#define			REG_ADDRESS_TEMPCOMPEN_ECTDS					0x0020
#define			REG_ADDRESS_ECTEMPCOFF_ECTDS					0x0022
#define			REG_ADDRESS_SALINICOFF_ECTDS					0x0023
#define			REG_ADDRESS_TDSCOFF_ECTDS						0x0024
#define			REG_ADDRESS_ELECTROCONST_ECTDS					0x0025
#define			REG_ADDRESS_ECCALIB_1413_ECTDS					0x0030
#define			REG_ADDRESS_ECCALIB_12880_ECTDS					0x0031
#define			REG_ADDRESS_SLAVEADD_ECTDS						0x0200
#define			REG_ADDRESS_BAUDRATE_ECTDS						0x0201
#define			REG_ADDRESS_PROTOCOL_ECTDS						0x0202
#define			REG_ADDRESS_PARITY_ECTDS						0x0203
#define			REG_ADDRESS_DATABITS_ECTDS						0x0204
#define			REG_ADDRESS_STOPBITS_ECTDS						0x0205
#define			REG_ADDRESS_RESPONDELAY_ECTDS					0x0206
#define			REG_ADDRESS_AOI_ECTDS							0x0207

#define 		ADDRESS_SLAVE_ECTDS								0x03
#define			FUNCODE_EC_TDS_03								0x03
#define			FUNCODE_EC_TDS_04								0x04
#define			FUNCODE_EC_TDS_06								0x06
#define			FUNCODE_EC_TDS_16								0x10

#define			LENGTH_DATA_ECTDS								1

typedef struct{
	float vr_temp;
	uint16_t vr_eletrCond;
	uint16_t vr_salinity;
	uint16_t vr_tds;
	uint16_t vr_ecrawad;
	uint16_t vr_tempCompen;
	uint16_t vr_tempCoff;
	uint16_t vr_salinitycoff;
	uint16_t vr_TdsCoff;
	uint16_t vr_electroConst;
	uint16_t vr_slaAddress;
	uint16_t vr_baudrate;
	uint16_t vr_protocol;
	uint16_t vr_parity;
	uint16_t vr_databits;
	uint16_t vr_stopbits;
	uint16_t vr_responDelay;
	uint16_t vr_aoi;
}read_sensorEcTds_t;

uint8_t getECTDSTemp(float *data);
uint8_t getECTDSElectricalCond(uint16_t *data);
uint8_t getECTDSalinity(uint16_t *data);
uint8_t getTDS(uint16_t *data);
uint8_t getEcrawad(uint16_t *data);
uint8_t getECTDSTempCompen(uint16_t *data);
uint8_t getEcTempCoff(uint16_t *data);
uint8_t getECTDSalinitycoff(uint16_t *data);
uint8_t getTDSCoff(uint16_t *data);
uint8_t getECTDSelectroConst(uint16_t *data);
uint8_t getECTDSlaAddress(uint16_t *data);
uint8_t getECTDSBaudrate(uint16_t *data);
uint8_t getECTDSProtocol(uint16_t *data);
uint8_t getECTDSParity(uint16_t *data);
uint8_t getECTDSdatabits(uint16_t *data);
uint8_t getECTDStopbits(uint16_t *data);
uint8_t getECTDSResponDelay(uint16_t *data);
uint8_t getECTDEAoi(uint16_t *data);

#endif /* EC_TDS_LIB_EC_TDS_H_ */
