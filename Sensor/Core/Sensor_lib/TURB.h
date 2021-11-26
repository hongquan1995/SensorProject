/*
 * turb.h
 *
 *  Created on: Oct 26, 2021
 *      Author: 0
 */

#ifndef SENSOR_LIB_TURB_H_
#define SENSOR_LIB_TURB_H_

#define 		REG_ADDRESS_ADDSLAVE_TURB						0x0001
#define 		REG_ADDRESS_VMEASURE							0x000D
#define 		REG_ADDRESS_WORKINGSTATE						0x000F
#define			REG_ADDRESS_ADC									0x0042
#define			REG_ADDRESS_FIRSTCALIB							0x0064
#define			REG_ADDRESS_FIRSTADC							0x0066
#define			REG_ADDRESS_SECONDCALIB							0x0068
#define			REG_ADDRESS_SECONDADC							0x006A
#define			REG_ADDRESS_THIRDCALIB							0x006C
#define			REG_ADDRESS_THIRDADC							0x006E
#define			REG_ADDRESS_FAFIRSTCAL							0x00B4
#define			REG_ADDRESS_FAFIRSTADC							0x00B6
#define			REG_ADDRESS_FASECONDCAL							0x00B8
#define			REG_ADDRESS_FASECONDADC							0x00BA
#define			REG_ADDRESS_FATHIRDCAL							0x00BC
#define			REG_ADDRESS_FATHIRDADC							0x00BE


#define			ADDRESS_SLAVE_TURB							0x03
#define			FUNCODE_TURB_03								0x03
#define			FUNCODE_TURB_04								0x04
#define			FUNCODE_TURB_06								0x06
#define			FUNCODE_TURB_16								0x10

#define			LENGTH_DATA_1								1
#define			LENGTH_DATA_2								2

typedef struct{
	uint32_t vr_measure;
	uint16_t vr_workingstate;
	uint32_t vr_adc;
	uint32_t vr_firstcalib;
	uint32_t vr_firstadc;
	uint32_t vr_secondcalib;
	uint32_t vr_secondadc;
	uint32_t vr_thirdcalib;
	uint32_t vr_thirdadc;
	uint32_t vr_fafirstcal;
	uint32_t vr_fafirstadc;
	uint32_t vr_fasecondcal;
	uint32_t vr_fasecondadc;
	uint32_t vr_fathirdcal;
	uint32_t vr_fathirdadc;
	uint16_t vr_devideadd;
}read_sensorTurb_t;

void Turb_getInt16Data(uint8_t *rawData, uint16_t *vrData);
void Turb_getInt32Data(uint8_t *rawData, uint32_t *vrData);

#endif /* SENSOR_LIB_TURB_H_ */
