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
#define			REG_ADDRESS_MAXRANGE					0x2008

#define 		TRUE										1
#define			FALSE										0
#define			FUNCODE_COMMON_NH3							3
#define 		ADDRESS_SLAVE_NH3							0x0F

#define			LENGTH_DATA_TEMP							1
#define			LENGTH_DATA_HUMI							1
#define			LENGTH_DATA_NH3								2


uint8_t getNH3TemperatureValue(float *data);
uint8_t getNH3HumidityValue(float *data);
uint8_t getNH3(float *data);


#endif /* NH3_LIB_NH3_H_ */
