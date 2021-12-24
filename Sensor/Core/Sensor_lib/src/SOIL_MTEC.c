/*
 * MTEC.c
 *
 *  Created on: Oct 12, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "string.h"
#include "ParseModbus.h"
#include "SOIL_MTEC.h"
#include "Com_RS485.h"
#include "my_lib.h"

SENSORS SoilMTEC[] = {{ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_TEMP_MTEC, 			LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getFloatData},
				 	 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_VWC_MTEC, 			LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_EC_MTEC,			LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC,		REG_ADDRESS_SALINITY_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_TDS_MTEC, 			LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_EPSILON_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_SOILTYPE_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_TEMPUNIT_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_ECTEMPCOFF_MTEC, 	LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_SALINITYCOFF_MTEC, 	LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC,		REG_ADDRESS_TDSCOFF_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_MODADDRESS_MTEC, 	LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_BAUDRATE_MTEC,		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_PROTOCOL_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_PARITY_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_DATABITS_MTEC, 		LENGTH_DATA_MTEC,		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC,	 	REG_ADDRESS_STOPBITS_MTEC, 		LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_RESPONDELAY_MTEC, 	LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data},
					 {ADDRESS_SLAVE_MTEC, 		REG_ADDRESS_AOI_MTEC, 			LENGTH_DATA_MTEC, 		(getData)SOIL_MTEC_getUint16Data}
};

// lấy giá trị dữ liệu float của cảm biến
void SOIL_MTEC_getFloatData(uint8_t *rawData, float *vrData){
	if((rawData[0]*256+rawData[1])-0x7FFF < 0){
		*vrData = (rawData[0]*256+rawData[1])/100.0f;
	}
	else
		*vrData = ((rawData[0]*256+rawData[1])-0xFFFF-0x01)/100.0f;
}

// lấy giá trị dữ liệu uint16 của cảm biến
void SOIL_MTEC_getUint16Data(uint8_t *rawData, uint16_t *vrData){
	*vrData = rawData[0]*256+rawData[1];
}
