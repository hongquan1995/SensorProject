/*
 * NH3.c
 *
 *  Created on: Sep 24, 2021
 *      Author: 0
 */

#include <ParseModbus.h>
#include "stm32l4xx_hal.h"
#include "NH3.h"
#include "Com_RS485.h"
#include "my_lib.h"
#include "string.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];


// hàm nhận giá trị nhiệt độ cảm biến
uint8_t getNH3TemperatureValue(float *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_NH3, FUNCODE_COMMON_NH3, REG_ADDRESS_TEMPNH3, LENGTH_DATA_TEMP);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_NH3, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
		*data = *data / 100.0f;
	}
	return TRUE;
}

// hàm nhận giá trị độ ẩm cảm biến
uint8_t getNH3HumidityValue(float *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_NH3, FUNCODE_COMMON_NH3, REG_ADDRESS_HUMINH3, LENGTH_DATA_HUMI);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_NH3, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
		*data = *data / 100.0f;
	}
	return TRUE;
}

// hàm nhận giá trị NH3 cảm biến
uint8_t getNH3(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_NH3, FUNCODE_COMMON_NH3, REG_ADDRESS_NH3, LENGTH_DATA_NH3);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_NH3, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		math_reverseBigLittleEndian(dataField, datalen);
		memcpy(data, dataField, datalen);
	}
	return TRUE;
}

// hàm nhận giá trị MAX RANGE
uint8_t getNH3Maxrange(float *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_NH3, FUNCODE_COMMON_NH3, REG_ADDRESS_RANGENH3, LENGTH_DATA_RANGENH3);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_NH3, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}
