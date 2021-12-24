/*
 * ParseModbus.c
 *
 *  Created on: Sep 28, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "stdint.h"
#include "string.h"
#include "Com_RS485.h"
#include "ParseModbus.h"
#include "my_lib.h"
#include "cmsis_os.h"

uint8_t datalen;
uint8_t dataField[256];
extern struct_string gsm_sensor;

// parser function code 3 and 4
void parseFUNC3_4(uint8_t *rxBuf, uint8_t *datalen, uint8_t *dataField){
	*datalen = rxBuf[RX_DATALEN_34_INDEX];
	for(uint8_t loop = 0; loop < *datalen; loop ++){
		dataField[loop] = rxBuf[loop + RX_DATAFIELD_34_INDEX];
	}
}

// parser function code 6 and 16
void parseFUNC6_16(uint8_t *rxBuf, uint8_t *datalen, uint8_t *dataField){
	for(uint8_t loop = 0; loop < *datalen; loop ++){
		dataField[loop] = rxBuf[loop + RX_DATAFIELD_616_INDEX];
	}
}

uint8_t func_code;
// 0F 03 04 3C BB 08 2F 2F 9A modbus address, function code, number of byte data, data, CRC day la 3/4
uint8_t parserModbusRx(uint8_t address_slave, uint8_t *rxBuf, uint8_t lenrx, uint8_t *datalen, uint8_t *dataField){
	uint16_t crc;
	uint16_t crc_frame;
	// check address slave
	if(address_slave != rxBuf[RX_ADDRESS_SL_INDEX]){
		//my_printf("[parseFrame] error modbus address\r\n");
		return FALSE;
	}
	// check CRC
	crc = ModRTU_CRC(rxBuf, lenrx-2);
	crc_frame = rxBuf[lenrx-1]<<8 | rxBuf[lenrx-2]; //little big endian
	if(crc != crc_frame){
		//my_printf("[parseFrame] error CRC\r\n");
		return FALSE;
	}
	func_code = rxBuf[RX_FUNCODE_INDEX];
	switch (func_code){
		case 0x03:
		case 0x04:
			parseFUNC3_4(rxBuf, datalen, dataField);
			break;
		case 0x06:
		case 0x10:
			*datalen = RX_DATALEN_FC6_16;
			parseFUNC6_16(rxBuf, datalen, dataField);
			break;
		default:
			//my_printf("error frame");
			break;
	}
	return TRUE;
}

void wait_receivedata(uint16_t TIMEOUT_WAIT_RX_MS){
	 uint8_t last_indexBuffer = 0;
	 uint16_t timeCount = 0;
//	 indexBuffer = 0;
	while(gsm_sensor.buffer_index == 0 && timeCount < TIMEOUT_WAIT_RX_MS)// break khi có data, timeout là 200 ms
	{
		osDelay(10);// 1 ms
		timeCount++;
	}
	while( last_indexBuffer != gsm_sensor.buffer_index) //break khi không còn nhận ở ngắt, toàn bộ rx đã nhận
	{
		last_indexBuffer = gsm_sensor.buffer_index;
		osDelay(10);
	}
}

// Hàm gửi đọc dữ liệu float, int từ sensor với function code 3
uint8_t getSensorData(SENSORS sensor[], uint8_t number, RETURN_VAL *data, RETURN_TYPE typeData)
{
	uint8_t result, resp;
	gsm_sensor.buffer_index = 0;
	memset(gsm_sensor.buffer, '\0', 256);
	result = Master_Read_Modbus(sensor[number].SENSOR_ADDR, FUNCODE_03, sensor[number].REG_ADDR, sensor[number].LEN);
	if(result != HAL_OK){
		return FALSE;
	}
	//chờ sensor phản hồi
	wait_receivedata(200);
	resp = parserModbusRx(sensor[number].SENSOR_ADDR, gsm_sensor.buffer, gsm_sensor.buffer_index, &datalen, dataField);
	if(resp != 0){
		switch(typeData)
		{
			case RET_FLOAT:
				sensor[number].getDataSensor(dataField, &data->fval);
				break;
			case RET_U8:
				sensor[number].getDataSensor(dataField, &data->u8val);
				break;
			case RET_U16:
				sensor[number].getDataSensor(dataField, &data->u16val);
				break;
			case RET_U32:
				sensor[number].getDataSensor(dataField, &data->u32val);
				break;
			case RET_I16:
				sensor[number].getDataSensor(dataField, &data->i16val);
				break;
			default:
				break;
		}
		return TRUE;
	}
	return FALSE;
}

// Hàm ghi dữ liệu float từ sensor với function code 6
uint8_t writeSensorData6(SENSORS sensor[], uint8_t number, uint8_t data){
	uint8_t result, resp;
	uint16_t addReg;
	gsm_sensor.buffer_index = 0;
	memset(gsm_sensor.buffer, '\0', 256);
	result = Master_SingleWrite_Modbus(sensor[number].SENSOR_ADDR, FUNCODE_06, sensor[number].REG_ADDR, data);
	if(result != HAL_OK){
		return FALSE;
	}
	wait_receivedata(200);
	// chờ sensor phản hồi
	resp = parserModbusRx(sensor[number].SENSOR_ADDR, gsm_sensor.buffer, gsm_sensor.buffer_index, &datalen, dataField);
	if(resp != 0){
		addReg = dataField[0]<<8|dataField[1];
		if(addReg == sensor[number].REG_ADDR){
			return TRUE;
		}
	}
	return FALSE;
}

// Hàm ghi dữ liệu float từ sensor với function code 16
uint8_t writeSensorData16(SENSORS sensor[], uint8_t number, uint8_t *data){
	uint8_t result, resp;
	uint16_t addReg;
	gsm_sensor.buffer_index = 0;
	memset(gsm_sensor.buffer, '\0', 256);
	result = Master_MultiWrite_Modbus(sensor[number].SENSOR_ADDR, FUNCODE_16, sensor[number].REG_ADDR, sensor[number].LEN, data);
	if(result != HAL_OK){
		return FALSE;
	}
	wait_receivedata(200);
	// chờ sensor phản hồi
	resp = parserModbusRx(sensor[number].SENSOR_ADDR, gsm_sensor.buffer, gsm_sensor.buffer_index, &datalen, dataField);
	if(resp != 0){
		addReg = dataField[0]<<8|dataField[1];
		if(addReg == sensor[number].REG_ADDR){
			return TRUE;
		}
	}
	return FALSE;
}

