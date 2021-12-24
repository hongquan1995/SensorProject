/*
 * liqlever.c
 *
 *  Created on: Dec 21, 2021
 *      Author: 0
 */
#include "stm32l4xx_hal.h"
#include "LIQLEVER.h"
#include "string.h"
#include "ParseModbus.h"
#include "Com_RS485.h"
#include "my_lib.h"

SENSORS LiqLever[] = {{ADDRESS_SLAVE_LIQLEVER, 		REG_ADDRESS_ADDSLAVE_LIQLEVER, 			LENGTH_DATA_INT, 		(getData)LiqLever_getIntData},
				 	 {ADDRESS_SLAVE_LIQLEVER, 		REG_ADDRESS_BAUDRATE_LIQLEVER, 			LENGTH_DATA_INT, 		(getData)LiqLever_getIntData},
					 {ADDRESS_SLAVE_LIQLEVER, 		REG_ADDRESS_UNIT_LIQLEVER,				LENGTH_DATA_INT, 		(getData)LiqLever_getIntData},
					 {ADDRESS_SLAVE_LIQLEVER,		REG_ADDRESS_DECPOINT_LIQLEVER, 			LENGTH_DATA_INT, 		(getData)LiqLever_getIntData},
					 {ADDRESS_SLAVE_LIQLEVER, 		REG_ADDRESS_MEASUREMENT_LIQLEVER, 		LENGTH_DATA_INT, 		(getData)LiqLever_getIntData},
					 {ADDRESS_SLAVE_LIQLEVER, 		REG_ADDRESS_ZEROPOINT_LIQLEVER, 		LENGTH_DATA_INT, 		(getData)LiqLever_getIntData}
};

// lấy dữ liệu int của cảm biến
void LiqLever_getIntData(uint8_t *rawData, int *vrData){
	*vrData = rawData[0] <<8 | rawData[1];
}

