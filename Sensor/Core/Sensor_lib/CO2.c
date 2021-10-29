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
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_CO2, LENGTH_DATA_CO2);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
//	HAL_Delay(1000);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getVERCO2(float *hard_ver, float *soft_ver)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_VER_CO2, LENGTH_DATA_CO2);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*hard_ver = dataField[0] / 10.0f;
		*soft_ver = dataField[1] / 10.0f;
	}
	return TRUE;
}

uint8_t getModSlaveAddCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_SLA_CO2, LENGTH_DATA_CO2);
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

uint8_t getBaudRateCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_BAURATE_CO2, LENGTH_DATA_CO2);
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

uint8_t getParityCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_PARITY_CO2, LENGTH_DATA_CO2);
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

uint8_t getStopBitsCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_STOPBIT_CO2, LENGTH_DATA_CO2);
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

uint8_t getModProtocolCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_PROTOCOL_CO2, LENGTH_DATA_CO2);
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

uint8_t getDelayResponseCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_DELAYRESPOND_CO2, LENGTH_DATA_CO2);
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

uint8_t getWarmUpTimeCO2(uint16_t *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_WARMUPTIME_CO2, LENGTH_DATA_CO2);
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

uint8_t writeCO2SlvAddress(uint16_t *addReg, uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_SingleWrite_Modbus(ADDRESS_SLAVE_CO2_DF, FUNCODE_CO2_06, REG_ADDRESS_SLA_CO2, ADDRESS_SLAVE_CO2);
	if(result != HAL_OK){
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2_DF, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*addReg = dataField[0]<<8|dataField[1];
		*data = dataField[2]<<8|dataField[3];
	}
	return TRUE;
}
