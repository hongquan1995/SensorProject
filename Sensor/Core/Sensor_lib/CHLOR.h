/*
 * CHLOR.h
 *
 *  Created on: Oct 27, 2021
 *      Author: 0
 */

#ifndef SENSOR_LIB_CHLOR_H_
#define SENSOR_LIB_CHLOR_H_

#define 		REG_ADDRESS_MEASUREMENTS						0x0001
#define 		REG_ADDRESS_TEMPMEASURE							0x0003
#define 		REG_ADDRESS_OUTPUTVAL							0x0005
#define			REG_ADDRESS_WARNING								0x0007
#define			REG_ADDRESS_UPPERMEASURE						0x000A
#define			REG_ADDRESS_LOWERMEASURE						0x000C
#define			REG_ADDRESS_UPPERTEMP							0x000E
#define			REG_ADDRESS_LOWERTEMP							0x0010
#define			REG_ADDRESS_MEASOFFSET							0x0012
#define			REG_ADDRESS_TEMPOFFSET							0x0014
#define			REG_ADDRESS_DAMPCOEFF							0x0016
#define 		REG_ADDRESS_ADDSLAVE_CHLO						0x0019
#define 		REG_ADDRESS_BAUDRATE_CHLO						0x001A
#define 		REG_ADDRESS_RESTORE								0x001B
#define 		REG_ADDRESS_STANDSOLU							0x0024
#define 		REG_ADDRESS_PHCOMPEN							0x0034
#define 		REG_ADDRESS_MANUALTEMP							0x003A
#define 		REG_ADDRESS_ZEROCALIB							0x003E
#define 		REG_ADDRESS_SLOPECALIB							0x003F
#define 		REG_ADDRESS_MEASUREAD							0x0066

#define			ADDRESS_SLAVE_CHLOR								0x07


#define			LENGTH_DATA_INT										1
#define			LENGTH_DATA_FLOAT									2

typedef enum {
	CLOR_MEASUREMENTS,
	CLOR_TEMPMEASURE,
	CLOR_OUTPUTVAL,
	CLOR_WARNING,
	CLOR_UPPERMEASURE,
	CLOR_LOWERMEASURE,
	CLOR_UPPERTEMP,
	CLOR_LOWERTEMP,
	CLOR_MEASOFFSET,
	CLOR_TEMPOFFSET,
	CLOR_DAMPCOEFF,
	CLOR_ADDSLAVE_CHLO,
	CLOR_BAUDRATE_CHLO,
	CLOR_RESTORE,
	CLOR_STANDSOLU,
	CLOR_PHCOMPEN,
	CLOR_MANUALTEMP,
	CLOR_ZEROCALIB,
	CLOR_SLOPECALIB,
	CLOR_MEASUREAD,
}CHLOR_ID;

typedef struct{
	float vr_measure;
	float vr_temperature;
	float vr_outputval;
	uint16_t vr_warning;
	float vr_uppermeasure;
	float vr_lowermeasure;
	float vr_uppertemp;
	float vr_lowertemp;
	float vr_mesoffset;
	float vr_tempoffset;
	uint16_t vr_dampcoeff;
	uint16_t vr_addslave;
	uint16_t vr_baudrate;
	float vr_standsolution;
	float vr_phcompen;
	float vr_manualtemp;
	uint16_t vr_measuread;
}read_sensorChlor_t;

void Clor_getFloatData(uint8_t *rawData, float *vrData);
void Clor_getIntData(uint8_t *rawData, uint16_t *vrData);

#endif /* SENSOR_LIB_CHLOR_H_ */
