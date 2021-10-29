/*
 * CHLOR.c
 *
 *  Created on: Oct 27, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "CHLOR.h"
#include "string.h"
#include <ParseModbus.h>
#include "Com_RS485.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm đọc giá trị chlo measure value cảm biến
uint8_t getCHloMeasure(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_MEASUREMENTS, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloTemperature(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_TEMPMEASURE, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloOuputVal(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_OUTPUTVAL, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloWarning(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_WARNING, LENGTH_DATA_INT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloUpperMeasure(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_UPPERMEASURE, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloLowerMeasure(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_LOWERMEASURE, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloUpperTemp(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_UPPERTEMP, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloLowerTemp(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_LOWERTEMP, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloMesOffset(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_MEASOFFSET, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloTempOffset(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_TEMPOFFSET, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloDampCoeff(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_DAMPCOEFF, LENGTH_DATA_INT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloAddSlave(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_ADDSLAVE_CHLO, LENGTH_DATA_INT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloBaudrate(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_BAUDRATE_CHLO, LENGTH_DATA_INT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloStandSolution(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_STANDSOLU, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloPhCompen(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_PHCOMPEN, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloManualTemp(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_MANUALTEMP, LENGTH_DATA_FLOAT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[2] << 24 | dataField[3] << 16 | dataField[0] << 8 | dataField[1];
	}
	return TRUE;
}

uint8_t getCHloMeasureAd(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_CHLOR, FUNCODE_CHLOR_03, REG_ADDRESS_MEASUREAD, LENGTH_DATA_INT);
	if(result != HAL_OK){
		return FALSE;
	}
	//wait sensor send respond
	wait_receivedata(200);
	res = parserModbusRx(ADDRESS_SLAVE_CHLOR, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0] <<8 | dataField[1];
	}
	return TRUE;
}
