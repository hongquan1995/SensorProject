/*
 * CO2.c
 *
 *  Created on: Oct 1, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "CO2.h"
#include "string.h"
#include <ParseModbus.h>
#include "Com_RS485.h"
#include "my_lib.h"


uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

uint8_t getCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_CO2, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getVERSION(uint8_t *hard_ver, uint8_t *soft_ver)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_VER, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*hard_ver = dataField[0] / 10;
		*soft_ver = dataField[1] / 10;
	}
	return TRUE;
}

uint8_t getMSADDRESS(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_SLA, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getBRATE(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_BAURATE, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getPABITS(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_PARITY, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getSTOBITS(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_STOPBIT, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getMODBUSPROTOCOL(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_PROTOCOL, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getDELAYRESPONSE(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_DELAYRESPOND, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getWARMUPTIME(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_WARMUPTIME, LENGTH_DATA);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}
