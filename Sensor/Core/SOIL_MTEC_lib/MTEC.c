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
uint8_t getTEMPsoil(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_TEMP_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
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
	return TRUE;
}

// hàm nhận giá trị volumetric water content
uint8_t getVWCsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_VWC_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

// hàm nhận giá trị volumetric water content
uint8_t getECsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_EC_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getSALINITYsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_SALINITY_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getTDSsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_TDS_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getEPSILONsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_EPSILON_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getTEMPUNITsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_TEMPUNIT_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getECTEMPCOFFsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_ECTEMPCOFF_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getSALINITYCOFFsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_SALINITYCOFF_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getTDSCOFFsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_TDSCOFF_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getSLAVEADDRsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_MODADDRESS_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getBAUDRATEsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_BAUDRATE_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getPROTOCOLsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_PROTOCOL_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getPARITYsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_PARITY_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getDATABITSsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_DATABITS_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getSTOPBITSsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_STOPBITS_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getRESPONSEDELAYsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_RESPONDELAY_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}

uint8_t getAOIsoil(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_MTEC, FUNCODE_MTEC_03, REG_ADDRESS_AOI_MTEC, LENGTH_DATA_MTEC);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_MTEC, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = (dataField[0]*256+dataField[1]);
	}
	return TRUE;
}
