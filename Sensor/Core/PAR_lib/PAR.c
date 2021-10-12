/*
 * PAR.c
 *
 *  Created on: Oct 12, 2021
 *      Author: 0
 */

#include <ParseModbus.h>
#include "stm32l4xx_hal.h"
#include "PAR.h"
#include "Com_RS485.h"
#include "my_lib.h"
#include "string.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm nhận giá trị PAR cảm biến
uint8_t getPAR(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PAR, FUNCODE_COMMON_PAR, REG_ADDRESS_PAR, LENGTH_DATA_PAR);
	if(result != HAL_OK){
		return FALSE;
		//my_printf("not send frame");
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_PAR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
		return TRUE;
	}
}
