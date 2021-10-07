/*
 * CO2.c
 *
 *  Created on: Oct 1, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "CO2.h"

#include <ParseModbus.h>
#include "Com_RS485.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm nhận giá trị nhiệt độ cảm biến
void getCO2(float *data)
{
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CO2, FUNCODE_CO2_03, REG_ADDRESS_CO2, LENGTH_DATA);
	if(result != HAL_OK){
		my_printf("not send frame");
	}
	wait_receivedata(200);
//	HAL_Delay(6000);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_CO2, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
}

