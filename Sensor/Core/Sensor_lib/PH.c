/*
 * PH1.c
 *
 *  Created on: Oct 9, 2021
 *      Author: 0
 */

#include "PH.h"
#include "stm32l4xx_hal.h"
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
uint8_t getPHTemperature(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_TEMP_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
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
	return TRUE;
}

// hàm nhận giá trị PH
uint8_t getPH(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_VALUE_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHTemcompensateen(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_TEMPCOMPEN_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHCalibrawad0(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_PHCALIBRAWAD0, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHCalibrawad1(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_PHCALIBRAWAD1, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHCalibrawad2(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_PHCALIBRAWAD2, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHSlaveaddress(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_SLAVEADD_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHBaudrate(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_BAUDRATE_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHProtocol(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_PROTOCOL_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHParity(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_PARITY_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHDatabits(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_DATABITS_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHStopbits(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_STOPBITS_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHResponsedelay(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_RESPONDELAY_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getPHAOI(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, REG_ADDRESS_AOI_PH, LENGTH_DATA_PH);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t writePHSlvAddress(uint16_t *addReg, uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_SingleWrite_Modbus(ADDRESS_SLAVE_PH_DF, FUNCODE_EC_PH_06, REG_ADDRESS_SLAVEADD_PH, ADDRESS_SLAVE_PH);
	if(result != HAL_OK){
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_PH_DF, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*addReg = dataField[0]<<8|dataField[1];
		*data = dataField[2]<<8|dataField[3];
	}
	return TRUE;
}
//uint8_t getMultiPHdata(uint16_t *data, uint8_t lenData, uint16_t Add_Data){
//	uint8_t res;
//		indexBuffer = 0;
//		memset(buffer, '\0', 256);
//		result = Master_Read_Modbus(ADDRESS_SLAVE_PH, FUNCODE_EC_PH_03, lenData, Add_Data);
//		if(result != HAL_OK){
//			return FALSE;
//		}
//		wait_receivedata(200);
//		//wait data respond
//		res = parserModbusRx(ADDRESS_SLAVE_PH, buffer, indexBuffer, &datalen, dataField);
//		if(res != 0){
//
//		}
//		return TRUE;
//}

