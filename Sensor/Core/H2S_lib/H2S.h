/*
 * H2S.h
 *
 *  Created on: Oct 11, 2021
 *      Author: 0
 */

#ifndef H2S_LIB_H2S_H_
#define H2S_LIB_H2S_H_

#define 		REG_ADDRESS_H2S							0x2000
#define			REG_ADDRESS_TEMPH2S						0x2004
#define			REG_ADDRESS_HUMIH2S						0x2006
#define			REG_ADDRESS_RANGEH2S					0x2008

#define 		TRUE										1
#define			FALSE										0
#define			FUNCODE_COMMON_H2S							3
#define 		ADDRESS_SLAVE_H2S							0x10

#define			LENGTH_DATA_RANGEH2S						1
#define			LENGTH_DATA_TEMPH2S							1
#define			LENGTH_DATA_HUMIH2S							1
#define			LENGTH_DATA_H2S								2


uint8_t getH2STemperatureValue(float *data);
uint8_t getH2SHumidityValue(float *data);
uint8_t getH2S(float *data);

#endif /* H2S_LIB_H2S_H_ */
