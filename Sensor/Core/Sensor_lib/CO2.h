/*
 * CO2.h
 *
 *  Created on: Oct 1, 2021
 *      Author: 0
 */

#ifndef CO2_LIB_CO2_H_
#define CO2_LIB_CO2_H_


#define 		REG_ADDRESS_CO2							0x0000
#define 		REG_ADDRESS_VER_CO2						0x0007
#define 		REG_ADDRESS_SLA_CO2						0x0010
#define 		REG_ADDRESS_BAURATE_CO2					0x0011
#define 		REG_ADDRESS_PARITY_CO2					0x0012
#define 		REG_ADDRESS_STOPBIT_CO2					0x0013
#define 		REG_ADDRESS_PROTOCOL_CO2				0x0014
#define 		REG_ADDRESS_DELAYRESPOND_CO2			0x0020
#define 		REG_ADDRESS_WARMUPTIME_CO2				0x0021



#define 		TRUE										1
#define			FALSE										0

#define 		ADDRESS_SLAVE_CO2_DF						0x01
#define 		ADDRESS_SLAVE_CO2							0x04
#define			FUNCODE_CO2_03								0x03
#define			FUNCODE_CO2_04								0x04
#define			FUNCODE_CO2_06								0x06
#define			FUNCODE_CO2_16								0x10

#define			LENGTH_DATA_CO2								1

typedef struct{
	uint16_t vr_CO2;
	float vr_hardVer;
	float vr_softVer;
	uint16_t vr_modSlave;
	uint16_t vr_baudrate;
	uint16_t vr_parityBits;
	uint16_t vr_stopBits;
	uint16_t vr_modProtocol;
	uint16_t vr_delayResponse;
	uint16_t vr_warmUptime;
}read_sensorCO2_t;

uint8_t getCO2(uint16_t *data);
uint8_t getVERCO2(float *hard_ver, float *soft_ver);
uint8_t getModSlaveAddCO2(uint16_t *data);
uint8_t getBaudRateCO2(uint16_t *data);
uint8_t getParityCO2(uint16_t *data);
uint8_t getStopBitsCO2(uint16_t *data);
uint8_t getModProtocolCO2(uint16_t *data);
uint8_t getDelayResponseCO2(uint16_t *data);
uint8_t getWarmUpTimeCO2(uint16_t *data);
uint8_t writeCO2SlvAddress(uint16_t *addReg, uint16_t *data);

#endif /* CO2_LIB_CO2_H_ */


