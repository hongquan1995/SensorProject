/*
 * Com_RS485.h
 *
 *  Created on: Sep 24, 2021
 *      Author: 0
 */

#ifndef COM_RS485_COM_RS485_H_
#define COM_RS485_COM_RS485_H_

void RS485_Direct_on();
void RS485_Direct_off();
uint16_t ModRTU_CRC(uint8_t* buf, int len);
uint8_t Master_Read_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData);
uint8_t Master_Write_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData, uint8_t* aData);
uint8_t Master_SingleWrite_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t Data);
uint8_t Slave_ACKRead_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData, uint8_t* aData);
uint8_t Slave_ACKWrite_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData);

#endif /* COM_RS485_COM_RS485_H_ */
