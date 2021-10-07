/*
 * EC_TDS.c
 *
 *  Created on: Sep 29, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "EC_TDS.h"

#include <ParseModbus.h>
#include "Com_RS485.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm nhận giá trị nhiệt độ cảm biến
void getTemperature(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_EC_TDS, FUNCODE_EC_TDS_03, REG_ADDRESS_TEMPERATURE, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_EC_TDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		if(dataField[0] != 0xFF){
			*data = (dataField[0]*256+dataField[1])/100.0f;
		}
		else
			*data = ((0xFF*256+dataField[1])-0xFFFF-0x01)/100.0f;
	}
}

// hàm nhận giá trị electrical conductivity
void getElectricalCond(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_EC_TDS, FUNCODE_EC_TDS_03, REG_ADDRESS_EC, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_EC_TDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}

void getSALINITY(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_EC_TDS, FUNCODE_EC_TDS_03, REG_ADDRESS_SALINITY, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_EC_TDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}

void getTDS(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_EC_TDS, FUNCODE_EC_TDS_03, REG_ADDRESS_TDS, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_EC_TDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}

void getECRAWAD(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_EC_TDS, FUNCODE_EC_TDS_03, REG_ADDRESS_ECRAWAD, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_EC_TDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}
