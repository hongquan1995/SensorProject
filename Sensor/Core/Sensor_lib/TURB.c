/*
 * TURB.c
 *
 *  Created on: Oct 26, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "TURB.h"
#include "string.h"
#include "ParseModbus.h"
#include "ParseSensor.h"
#include "Com_RS485.h"
#include "my_lib.h"

uint8_t datalen;
uint8_t dataField[256];
uint8_t result;

extern uint8_t indexBuffer;
extern uint8_t buffer[256];

SENSORS Turbidity[] = {{ADDRESS_SLAVE_TURB, 	REG_ADDRESS_ADDSLAVE_TURB, 		LENGTH_DATA_1, 		Turb_getInt16Data},
				  	  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_VMEASURE, 			LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_WORKINGSTATE,		LENGTH_DATA_1, 		Turb_getInt16Data},
					  {ADDRESS_SLAVE_TURB,		REG_ADDRESS_ADC, 				LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_FIRSTCALIB, 		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_FIRSTADC, 			LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_SECONDCALIB, 		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_SECONDADC, 			LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_THIRDCALIB, 		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_THIRDADC, 			LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB,		REG_ADDRESS_FAFIRSTCAL, 		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_FAFIRSTADC, 		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_FASECONDCAL,		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_FASECONDADC, 		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_FATHIRDCAL, 		LENGTH_DATA_2, 		Turb_getInt32Data},
					  {ADDRESS_SLAVE_TURB, 		REG_ADDRESS_FATHIRDADC, 		LENGTH_DATA_2,		Turb_getInt32Data}
};

// lấy dữ liệu 2 byte của cảm biến
void Turb_getInt16Data(uint8_t *rawData, uint16_t *vrData){
	*vrData = rawData[0] <<8 | rawData[1];
}

// lấy dữ liệu 4 byte của cảm biến
void Turb_getInt32Data(uint8_t *rawData, uint32_t *vrData){
	 *vrData = rawData[0] << 24 | rawData[1] << 16 | rawData[2] << 8 | rawData[3];
}

