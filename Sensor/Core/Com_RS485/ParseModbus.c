/*
 * ParseModbus.c
 *
 *  Created on: Sep 28, 2021
 *      Author: 0
 */

#include "ParseModbus.h"
#include "stdint.h"
#include "my_lib.h"



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
