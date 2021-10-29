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


#define			ADDRESS_SLAVE_TURB_DF						0x01
#define			ADDRESS_SLAVE_TURB							0x07
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

uint8_t getTURBmeasure(uint32_t *data);
uint8_t getTURBWorkingState(uint16_t *data);
uint8_t getTURBAdc(uint32_t *data);
uint8_t getTURBFirstCalib(uint32_t *data);
uint8_t getTURBFirstAdc(uint32_t *data);
uint8_t getTURBSecondCalib(uint32_t *data);
uint8_t getTURBSecondAdc(uint32_t *data);
uint8_t getTURBThirdCalib(uint32_t *data);
uint8_t getTURBThirdAdc(uint32_t *data);
uint8_t getTURBFaFirstCal(uint32_t *data);
uint8_t getTURBFaFirstAdc(uint32_t *data);
uint8_t getTURBFaSecondCal(uint32_t *data);
uint8_t getTURBFaSecondAdc(uint32_t *data);
uint8_t getTURBFaThirdCal(uint32_t *data);
uint8_t getTURBFaThirdAdc(uint32_t *data);
uint8_t getTURBDeviceAdd(uint16_t *data);

#endif /* SENSOR_LIB_TURB_H_ */
