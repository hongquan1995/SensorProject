/*
 * H2S.c
 *
 *  Created on: Oct 11, 2021
 *      Author: 0
 */


#include <ParseModbus.h>
#include "stm32l4xx_hal.h"
#include "H2S.h"
#include "Com_RS485.h"
#include "my_lib.h"
#include "string.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];


// hàm nhận giá trị nhiệt độ cảm biến
uint8_t getH2STemperatureValue(float *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_H2S, FUNCODE_COMMON_H2S, REG_ADDRESS_TEMPH2S, LENGTH_DATA_TEMPH2S);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_H2S, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

// hàm nhận giá trị độ ẩm cảm biến
uint8_t getH2SHumidityValue(float *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_H2S, FUNCODE_COMMON_H2S, REG_ADDRESS_HUMIH2S, LENGTH_DATA_HUMIH2S);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_H2S, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

// hàm nhận giá trị H2S cảm biến
uint8_t getH2S(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_H2S, FUNCODE_COMMON_H2S, REG_ADDRESS_H2S, LENGTH_DATA_H2S);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_H2S, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
//		math_reverseBigLittleEndian(dataField, datalen);
//		memcpy(data, dataField, datalen);
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

// hàm nhận giá trị độ ẩm cảm biến
uint8_t getH2SMaxrange(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_H2S, FUNCODE_COMMON_H2S, REG_ADDRESS_RANGEH2S, LENGTH_DATA_RANGEH2S);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_H2S, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}
