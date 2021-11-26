/*
 * ParseSenssor.h
 *
 *  Created on: Nov 24, 2021
 *      Author: 0
 */

#ifndef COM_RS485_PARSESENSOR_H_
#define COM_RS485_PARSESENSOR_H_

#include "stdint.h"

typedef void (*getData)(uint8_t *, void *);

typedef struct  {
	uint8_t SENSOR_ADDR;
	uint16_t REG_ADDR;
	uint8_t LEN;
	getData getDataSensor;
} SENSORS;

//union
typedef union {
	float fval;
	uint8_t u8val;
	uint16_t u16val;
	uint32_t u32val;
	int i16val;
} RETURN_VAL;

typedef enum {
	RET_FLOAT,
	RET_U8,
	RET_U16,
	RET_U32,
	RET_I16
}RETURN_TYPE;

#define			FUNCODE_03								0x03
#define			FUNCODE_04								0x04
#define			FUNCODE_06								0x06
#define			FUNCODE_16								0x10

uint8_t getSensorData(SENSORS sensor[], uint8_t number, RETURN_VAL *data, RETURN_TYPE typeData);
uint8_t writeSensorData6(SENSORS sensor[], uint8_t number, uint8_t data);
uint8_t writeSensorData16(SENSORS sensor[], uint8_t number, uint8_t *data);
#endif /* COM_RS485_PARSESENSOR_H_ */
