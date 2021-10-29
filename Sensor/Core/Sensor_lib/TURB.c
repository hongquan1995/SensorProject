/*
 * TURB.c
 *
 *  Created on: Oct 26, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "TURB.h"
#include "string.h"
#include <ParseModbus.h>
#include "Com_RS485.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm đọc giá trị measure value cảm biến
uint8_t getTURBmeasure(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_VMEASURE, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBWorkingState(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_WORKINGSTATE, LENGTH_DATA_1);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBAdc(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_ADC, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFirstCalib(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FIRSTCALIB, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFirstAdc(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FIRSTADC, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBSecondCalib(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_SECONDCALIB, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBSecondAdc(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_SECONDADC, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBThirdCalib(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_THIRDCALIB, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBThirdAdc(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_THIRDADC, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFaFirstCal(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FAFIRSTCAL, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFaFirstAdc(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FAFIRSTADC, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFaSecondCal(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FASECONDCAL, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFaSecondAdc(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FASECONDADC, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFaThirdCal(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FATHIRDCAL, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBFaThirdAdc(uint32_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_FATHIRDADC, LENGTH_DATA_2);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getTURBDeviceAdd(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_TURB, FUNCODE_TURB_03, REG_ADDRESS_ADDSLAVE_TURB, LENGTH_DATA_1);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_TURB, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}
