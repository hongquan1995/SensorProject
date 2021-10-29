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

#define			ADDRESS_SLAVE_CHLOR_DF							0x01
#define			ADDRESS_SLAVE_CHLOR								0x08
#define			FUNCODE_CHLOR_03								0x03
#define			FUNCODE_CHLOR_04								0x04
#define			FUNCODE_CHLOR_06								0x06
#define			FUNCODE_CHLOR_16								0x10

#define			LENGTH_DATA_INT										1
#define			LENGTH_DATA_FLOAT									2

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

uint8_t getCHloMeasure(float *data);
uint8_t getCHloTemperature(float *data);
uint8_t getCHloOuputVal(float *data);
uint8_t getCHloWarning(uint16_t *data);
uint8_t getCHloUpperMeasure(float *data);
uint8_t getCHloLowerMeasure(float *data);
uint8_t getCHloUpperTemp(float *data);
uint8_t getCHloLowerTemp(float *data);
uint8_t getCHloMesOffset(float *data);
uint8_t getCHloTempOffset(float *data);
uint8_t getCHloDampCoeff(uint16_t *data);
uint8_t getCHloAddSlave(uint16_t *data);
uint8_t getCHloBaudrate(uint16_t *data);
uint8_t getCHloStandSolution(float *data);
uint8_t getCHloPhCompen(float *data);
uint8_t getCHloManualTemp(float *data);
uint8_t getCHloMeasureAd(uint16_t *data);

#endif /* SENSOR_LIB_CHLOR_H_ */
