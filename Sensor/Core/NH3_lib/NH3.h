/*
 * NH3.h
 *
 *  Created on: Sep 24, 2021
 *      Author: 0
 */

#ifndef NH3_LIB_NH3_H_
#define NH3_LIB_NH3_H_

#define 		REG_ADDRESS_NH3							0x2000
#define			REG_ADDRESS_TEMPNH3						0x2004
#define			REG_ADDRESS_HUMINH3						0x2006
#define			REG_ADDRESS_RANGENH3					0x2008

#define 		TRUE										1
#define			FALSE										0
#define			FUNCODE_COMMON_NH3							3
#define 		ADDRESS_SLAVE_NH3							0x0F

#define			LENGTH_DATA_RANGENH3						1
#define			LENGTH_DATA_TEMPNH3							1
#define			LENGTH_DATA_HUMINH3							1
#define			LENGTH_DATA_NH3								2

typedef struct{
	float vr_temp;
	float vr_humi;
	uint32_t vr_nh3;
	uint16_t vr_maxRange;
}read_sensornNH3_t;

uint8_t getNH3TemperatureValue(float *data);
uint8_t getNH3HumidityValue(float *data);
uint8_t getNH3(uint32_t *data);
uint8_t getNH3Maxrange(uint16_t *data);

#endif /* NH3_LIB_NH3_H_ */
