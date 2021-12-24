/*
 * liqlever.h
 *
 *  Created on: Dec 21, 2021
 *      Author: 0
 */

#ifndef SENSOR_LIB_INC_LIQLEVER_H_
#define SENSOR_LIB_INC_LIQLEVER_H_

#define 		REG_ADDRESS_ADDSLAVE_LIQLEVER					0x0000
#define 		REG_ADDRESS_BAUDRATE_LIQLEVER					0x0001
#define 		REG_ADDRESS_UNIT_LIQLEVER						0x0002
#define 		REG_ADDRESS_DECPOINT_LIQLEVER					0x0003
#define 		REG_ADDRESS_MEASUREMENT_LIQLEVER				0x0004
#define 		REG_ADDRESS_ZEROPOINT_LIQLEVER					0x0005


#define			ADDRESS_SLAVE_LIQLEVER							0x1A


#define			LENGTH_DATA_INT										1

void LiqLever_getIntData(uint8_t *rawData, int *vrData);

#endif /* SENSOR_LIB_INC_LIQLEVER_H_ */
