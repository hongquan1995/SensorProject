/*
 * PH1.c
 *
 *  Created on: Oct 9, 2021
 *      Author: 0
 */

#include "PH.h"
#include "stm32l4xx_hal.h"
#include "ParseModbus.h"
#include "Com_RS485.h"
#include "my_lib.h"
#include "string.h"


SENSORS PH[] = {{ADDRESS_SLAVE_PH, 		REG_ADDRESS_TEMP_PH, 			LENGTH_DATA_PH, 		(getData)PH_getFloatData},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_VALUE_PH, 			LENGTH_DATA_PH, 		(getData)PH_getFloatData},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_TEMPCOMPEN_PH,		LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH,		REG_ADDRESS_PHCALIBRAWAD0, 		LENGTH_DATA_PH, 		(getData)PH_getIntData},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_PHCALIBRAWAD1, 		LENGTH_DATA_PH, 		(getData)PH_getIntData},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_PHCALIBRAWAD2, 		LENGTH_DATA_PH, 		(getData)PH_getIntData},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_SLAVEADD_PH, 		LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_BAUDRATE_PH, 		LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_PROTOCOL_PH, 		LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_PARITY_PH, 			LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH,		REG_ADDRESS_DATABITS_PH, 		LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_STOPBITS_PH, 		LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_RESPONDELAY_PH,		LENGTH_DATA_PH, 		(getData)PH_getUint16Data},
				{ADDRESS_SLAVE_PH, 		REG_ADDRESS_AOI_PH, 			LENGTH_DATA_PH, 		(getData)PH_getUint16Data}
};

// lấy giá trị dữ liệu float của cảm biến
void PH_getFloatData(uint8_t *rawData, float *vrData){
	if((rawData[0]*256+rawData[1])-0x7FFF < 0){
		*vrData = (rawData[0]*256+rawData[1])/100.0f;
	}
	else
		*vrData = ((rawData[0]*256+rawData[1])-0xFFFF-0x01)/100.0f;
}

// lấy giá trị dữ liệu int của cảm biến
void PH_getIntData(uint8_t *rawData, int *vrData){
	if((rawData[0]*256+rawData[1])-0x7FFF < 0){
		*vrData = rawData[0]*256+rawData[1];
	}
	else
		*vrData = (rawData[0]*256+rawData[1])-0xFFFF-0x01;
}

// lấy giá trị dữ liệu uint16 của cảm biến
void PH_getUint16Data(uint8_t *rawData, uint16_t *vrData){
	*vrData = rawData[0]*256+rawData[1];
}

