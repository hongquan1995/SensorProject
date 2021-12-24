/*
 * ParseModbus.h
 *
 *  Created on: Sep 28, 2021
 *      Author: 0
 */

#ifndef INC_PARSEMODBUS_H_
#define INC_PARSEMODBUS_H_

#include <stdint.h>

#define 		TRUE									1
#define			FALSE									0

#define			RX_ADDRESS_SL_INDEX						0
#define			RX_FUNCODE_INDEX						1
#define 		RX_DATALEN_34_INDEX						2
#define			RX_DATAFIELD_34_INDEX					3
#define			RX_DATAFIELD_616_INDEX					2
#define 		RX_DATALEN_FC6_16						4

#define			FUNCODE_03								0x03
#define			FUNCODE_04								0x04
#define			FUNCODE_06								0x06
#define			FUNCODE_16								0x10

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

void parseFUNC3_4(uint8_t *rxBuf, uint8_t *datalen, uint8_t *dataField);
void parseFUNC6_16(uint8_t *rxBuf, uint8_t *datalen, uint8_t *dataField);
uint8_t parserModbusRx(uint8_t address_slave, uint8_t *rxBuf, uint8_t lenrx, uint8_t *datalen, uint8_t *dataField);

uint8_t getSensorData(SENSORS sensor[], uint8_t number, RETURN_VAL *data, RETURN_TYPE typeData);
uint8_t writeSensorData6(SENSORS sensor[], uint8_t number, uint8_t data);
uint8_t writeSensorData16(SENSORS sensor[], uint8_t number, uint8_t *data);
void wait_receivedata(uint16_t TIMEOUT_WAIT_RX_MS);

#endif /* INC_PARSEMODBUS_H_ */
