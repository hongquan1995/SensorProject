/*
 * ParseSensor.c
 *
 *  Created on: Nov 24, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "stdint.h"
#include "ParseSensor.h"
#include "string.h"
#include "Com_RS485.h"
#include "ParseModbus.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// Hàm gửi đọc dữ liệu float, int từ sensor với function code 3
uint8_t getSensorData(SENSORS sensor[], uint8_t number, RETURN_VAL *data, RETURN_TYPE typeData)
{
	uint8_t result, resp;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(sensor[number].SENSOR_ADDR, FUNCODE_03, sensor[number].REG_ADDR, sensor[number].LEN);
	if(result != HAL_OK){
		return FALSE;
	}
	//chờ sensor phản hồi
	wait_receivedata(200);
	resp = parserModbusRx(sensor[number].SENSOR_ADDR, buffer, indexBuffer, &datalen, dataField);
	if(resp != 0){
		switch(typeData)
		{
			case RET_FLOAT:
				sensor[number].getDataSensor(dataField, &data->fval);
				break;
			case RET_U8:
				sensor[number].getDataSensor(dataField, &data->u8val);
				break;
			case RET_U16:
				sensor[number].getDataSensor(dataField, &data->u16val);
				break;
			case RET_U32:
				sensor[number].getDataSensor(dataField, &data->u32val);
				break;
			case RET_I16:
				sensor[number].getDataSensor(dataField, &data->i16val);
				break;
			default:
				break;
		}
		return TRUE;
	}
	return FALSE;
}

// Hàm ghi dữ liệu float từ sensor với function code 6
uint8_t writeSensorData6(SENSORS sensor[], uint8_t number, uint8_t data){
	uint8_t result, resp;
	uint16_t addReg;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_SingleWrite_Modbus(sensor[number].SENSOR_ADDR, FUNCODE_06, sensor[number].REG_ADDR, data);
	if(result != HAL_OK){
		return FALSE;
	}
	wait_receivedata(200);
	// chờ sensor phản hồi
	resp = parserModbusRx(sensor[number].SENSOR_ADDR, buffer, indexBuffer, &datalen, dataField);
	if(resp != 0){
		addReg = dataField[0]<<8|dataField[1];
		if(addReg == sensor[number].REG_ADDR){
			return TRUE;
		}
	}
	return FALSE;
}

// Hàm ghi dữ liệu float từ sensor với function code 16
uint8_t writeSensorData16(SENSORS sensor[], uint8_t number, uint8_t *data){
	uint8_t result, resp;
	uint16_t addReg;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_MultiWrite_Modbus(sensor[number].SENSOR_ADDR, FUNCODE_16, sensor[number].REG_ADDR, sensor[number].LEN, data);
	if(result != HAL_OK){
		return FALSE;
	}
	wait_receivedata(200);
	// chờ sensor phản hồi
	resp = parserModbusRx(sensor[number].SENSOR_ADDR, buffer, indexBuffer, &datalen, dataField);
	if(resp != 0){
		addReg = dataField[0]<<8|dataField[1];
		if(addReg == sensor[number].REG_ADDR){
			return TRUE;
		}
	}
	return FALSE;
}
