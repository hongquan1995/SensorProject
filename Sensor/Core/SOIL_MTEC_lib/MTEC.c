/*
 * MTEC.c
 *
 *  Created on: Oct 12, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "MTEC.h"
#include "string.h"
#include <ParseModbus.h>
#include "Com_RS485.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm nhận giá trị nhiệt độ cảm biến
void getTemperaturesoil(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_TEMPERATURE, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		if(dataField[0] != 0xFF){
			*data = (dataField[0]*256+dataField[1])/100.0f;
		}
		else
			*data = ((0xFF*256+dataField[1])-0xFFFF-0x01)/100.0f;
	}
}

// hàm nhận giá trị volumetric water content
void getVWCsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_VWC, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}

// hàm nhận giá trị volumetric water content
void getECsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_EC, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}

void getSALINITYsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_SALINITY, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}

void getTDSsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_TDS, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}

void getEPSILONsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_EPSILON, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
}
