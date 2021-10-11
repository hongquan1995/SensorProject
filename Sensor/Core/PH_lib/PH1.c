/*
 * PH1.c
 *
 *  Created on: Oct 9, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "PH1.h"

#include <ParseModbus.h>
#include "Com_RS485.h"
#include "my_lib.h"
#include "string.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm nhận giá trị nhiệt độ cảm biến
void getPHTemperature(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_TEMPERATURE, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		if(dataField[0] != 0xFF){
			*data = (dataField[0]*256+dataField[1])/100.0f;
		}
		else
			*data = ((0xFF*256+dataField[1])-0xFFFF-0x01)/100.0f;
	}
}

// hàm nhận giá trị PH
void getPH(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_PHVALUE, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1])/100.0f;
	}
}
