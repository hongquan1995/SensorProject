/*
 * EC_TDS.c
 *
 *  Created on: Sep 29, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "EC_TDS.h"
#include "string.h"
#include "ParseModbus.h"
#include "Com_RS485.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

// hàm nhận giá trị nhiệt độ cảm biến
uint8_t getECTDSTemp(float *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS_DF, FUNCODE_EC_TDS_03, REG_ADDRESS_TEMP_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	 //wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS_DF, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		if(dataField[0] != 0xFF){
			*data = dataField[0]*256+dataField[1];
		}
		else
			*data = (0xFF*256+dataField[1])-0xFFFF-0x01;
	}
	return TRUE;
}

// hàm nhận giá trị electrical conductivity
uint8_t getECTDSElectricalCond(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_EC_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSalinity(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_SALINITY_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getTDS(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_TDS_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getEcrawad(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_ECRAWAD_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSTempCompen(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_TEMPCOMPEN_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getEcTempCoff(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_ECTEMPCOFF_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSalinitycoff(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_SALINICOFF_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getTDSCoff(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_TDSCOFF_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSelectroConst(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_ELECTROCONST_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSlaAddress(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_SLAVEADD_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSBaudrate(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_BAUDRATE_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSProtocol(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_PROTOCOL_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSParity(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_PARITY_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSdatabits(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_DATABITS_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDStopbits(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_STOPBITS_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDSResponDelay(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_RESPONDELAY_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t getECTDEAoi(uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_Read_Modbus(ADDRESS_SLAVE_ECTDS, FUNCODE_EC_TDS_03, REG_ADDRESS_AOI_ECTDS, LENGTH_DATA_ECTDS);
	if(result != HAL_OK){
//		my_printf("not send frame");
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*data = dataField[0]*256+dataField[1];
	}
	return TRUE;
}

uint8_t writeECTDSlvAddress(uint16_t *addReg, uint16_t *data){
	uint8_t res;
	indexBuffer = 0;
	memset(buffer, '\0', 256);
	result = Master_SingleWrite_Modbus(ADDRESS_SLAVE_ECTDS_DF, FUNCODE_EC_TDS_06, REG_ADDRESS_SLAVEADD_ECTDS, ADDRESS_SLAVE_ECTDS);
	if(result != HAL_OK){
		return FALSE;
	}
	wait_receivedata(200);
	//wait data respond
	res = parserModbusRx(ADDRESS_SLAVE_ECTDS_DF, buffer, indexBuffer, &datalen, dataField);
	if(res != 0){
		*addReg = dataField[0]<<8|dataField[1];
		*data = dataField[2]<<8|dataField[3];
	}
	return TRUE;
}
