/*
 * ParseModbus.h
 *
 *  Created on: Sep 28, 2021
 *      Author: 0
 */

#ifndef INC_PARSEMODBUS_H_
#define INC_PARSEMODBUS_H_

#include <stdint.h>

#define 		TRUE									1
#define			FALSE									0

#define			RX_ADDRESS_SL_INDEX						0
#define			RX_FUNCODE_INDEX						1
#define 		RX_DATALEN_34_INDEX						2
#define			RX_DATAFIELD_34_INDEX					3

#define			RX_DATAFIELD_616_INDEX					2

#define 		RX_DATALEN_FC6_16						4

void parseFUNC3_4(uint8_t *rxBuf, uint8_t *datalen, uint8_t *dataField);
void parseFUNC6_16(uint8_t *rxBuf, uint8_t *datalen, uint8_t *dataField);
uint8_t parserModbusRx(uint8_t address_slave, uint8_t *rxBuf, uint8_t lenrx, uint8_t *datalen, uint8_t *dataField);

#endif /* INC_PARSEMODBUS_H_ */
