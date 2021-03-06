/*
 * CHLOR.c
 *
 *  Created on: Oct 27, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "CHLOR.h"
#include "string.h"
#include "ParseModbus.h"
#include "Com_RS485.h"
#include "my_lib.h"

SENSORS Chlorine[] = {{ADDRESS_SLAVE_CHLOR, 	REG_ADDRESS_MEASUREMENTS, 		LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
				 	 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_TEMPMEASURE, 		LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_OUTPUTVAL,			LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR,		REG_ADDRESS_WARNING, 			LENGTH_DATA_INT, 		(getData)Clor_getUint16Data},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_UPPERMEASURE, 		LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_LOWERMEASURE, 		LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_UPPERTEMP, 			LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_LOWERTEMP, 			LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_MEASOFFSET, 		LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_TEMPOFFSET, 		LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR,		REG_ADDRESS_DAMPCOEFF, 			LENGTH_DATA_INT, 		(getData)Clor_getUint16Data},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_ADDSLAVE_CHLO, 		LENGTH_DATA_INT, 		(getData)Clor_getUint16Data},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_BAUDRATE_CHLO,		LENGTH_DATA_INT, 		(getData)Clor_getUint16Data},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_RESTORE, 			LENGTH_DATA_INT, 		NULL},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_STANDSOLU, 			LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_PHCOMPEN, 			LENGTH_DATA_FLOAT,		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR,	 	REG_ADDRESS_MANUALTEMP, 		LENGTH_DATA_FLOAT, 		(getData)Clor_getFloatData},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_ZEROCALIB, 			LENGTH_DATA_INT, 		NULL},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_SLOPECALIB, 		LENGTH_DATA_INT, 		NULL},
					 {ADDRESS_SLAVE_CHLOR, 		REG_ADDRESS_MEASUREAD, 			LENGTH_DATA_INT, 		(getData)Clor_getUint16Data}
};

// l???y gi?? tr??? d??? li???u float c???a c???m bi???n
void Clor_getFloatData(uint8_t *rawData, float *vrData){
	uint8_t aTemp[4];
	float vrTemp = 0;
	aTemp[0] = rawData[2];
	aTemp[1] = rawData[3];
	aTemp[2] = rawData[0];
	aTemp[3] = rawData[1];
	math_reverseBigLittleEndian(aTemp, sizeof(aTemp));
	memcpy(&vrTemp, aTemp, sizeof(aTemp));
	*vrData = vrTemp;
}

// l???y d??? li???u int c???a c???m bi???n
void Clor_getUint16Data(uint8_t *rawData, uint16_t *vrData){
	*vrData = rawData[0] <<8 | rawData[1];
}

