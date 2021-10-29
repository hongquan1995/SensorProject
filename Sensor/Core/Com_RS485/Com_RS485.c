/*
 * Com_RS485.c
 *
 *  Created on: Sep 24, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "Com_RS485.h"
#include "stdint.h"
#include "string.h"

/*======================== Funcion Crc ======================*/

uint8_t BUFF_DATA_485[256];
extern UART_HandleTypeDef huart4;

void RS485_Direct_on(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
}

void RS485_Direct_off(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
}

// Compute the MODBUS RTU CRC
uint16_t ModRTU_CRC(uint8_t* buf, int len)
{
  uint16_t crc = 0xFFFF;

  for (int pos = 0; pos < len; pos++)
  {
    crc ^= (uint16_t)buf[pos];          // XOR byte into least sig. byte of crc

    for (int i = 8; i != 0; i--) {    // Loop over each bit
      if ((crc & 0x0001) != 0) {      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      }
      else                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
    }
  }
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return crc;
}

/*======================== Funcion Master ======================*/
uint8_t Master_Read_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData)
{
    uint16_t crc;
    HAL_StatusTypeDef Result = HAL_ERROR;
    uint16_t Count = 0;
    memset(BUFF_DATA_485, '\0', 256);
    // Ðong goi frame
    //1 byte Add Slave
    BUFF_DATA_485[Count++] = Address;
    //1 byte Funcode
    BUFF_DATA_485[Count++] = FunCode;
    //2 byte Add Data
    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data>>8) & 0xFF;
    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data & 0xFF);
    //2 byte Data length
    BUFF_DATA_485[Count++] = (uint8_t) (LengthData>>8) & 0xFF;
    BUFF_DATA_485[Count++] = (uint8_t) (LengthData & 0xFF);
    //Tinh 2 byte Crc
    crc = ModRTU_CRC(&BUFF_DATA_485[0],Count);
    //them 2 byte crc
    BUFF_DATA_485[Count++] = (uint8_t) (crc & 0xFF);
    BUFF_DATA_485[Count++] = (uint8_t) (crc>>8) & 0xFF;

    // Chon chan DE sang send
    RS485_Direct_on();
    // Send
    Result = HAL_UART_Transmit(&huart4, &BUFF_DATA_485[0], Count, 1000);
    //Dua DE ve Receive
    RS485_Direct_off();

    return Result;
}

// write multiple register
uint8_t Master_Write_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData, uint8_t* aData)
{
    uint16_t crc;
    HAL_StatusTypeDef Result = HAL_ERROR;
    uint16_t Count = 0;
    uint16_t i = 0;

    // Ðong goi frame
    //1 byte Add Slave
    BUFF_DATA_485[Count++] = Address;
    //1 byte Funcode
    BUFF_DATA_485[Count++] = FunCode;
    //2 byte Add Data
    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data>>8) & 0xFF;
    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data & 0xFF);
    //2 byte Data length
    BUFF_DATA_485[Count++] = (uint8_t) (LengthData>>8) & 0xFF;
    BUFF_DATA_485[Count++] = (uint8_t) (LengthData & 0xFF);
    BUFF_DATA_485[Count++] = 2*LengthData;
    //n byte data
    for(i = 0; i < 2*LengthData; i++)
        BUFF_DATA_485[Count++] = *(aData + i);
    //Tinh 2 byte Crc
    crc = ModRTU_CRC(&BUFF_DATA_485[0],Count);
    //them 2 byte crc
    BUFF_DATA_485[Count++] = (uint8_t) (crc & 0xFF);
    BUFF_DATA_485[Count++] = (uint8_t) (crc>>8) & 0xFF;

    // Chon chan DE sang send
    RS485_Direct_on();
    // Send
    Result = HAL_UART_Transmit(&huart4, &BUFF_DATA_485[0], Count, 1000);
    //Dua DE ve Receive
    RS485_Direct_off();

    return Result;
}

// write single register
uint8_t Master_SingleWrite_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t Data)
{
    uint16_t crc;
    HAL_StatusTypeDef Result = HAL_ERROR;
    uint16_t Count = 0;

    // Ðong goi frame
    //1 byte Add Slave
    BUFF_DATA_485[Count++] = Address;
    //1 byte Funcode
    BUFF_DATA_485[Count++] = FunCode;
    //2 byte Add Data
    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data>>8) & 0xFF;
    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data & 0xFF);;
    //2 byte data
    BUFF_DATA_485[Count++] = (uint8_t) (Data>>8) & 0xFF;
    BUFF_DATA_485[Count++] = (uint8_t) (Data & 0xFF);;
    //Tinh 2 byte Crc
    crc = ModRTU_CRC(&BUFF_DATA_485[0],Count);
    //them 2 byte crc
    BUFF_DATA_485[Count++] = (uint8_t) (crc & 0xFF);
    BUFF_DATA_485[Count++] = (uint8_t) (crc>>8) & 0xFF;

    // Chon chan DE sang send
    RS485_Direct_on();
    // Send
    Result = HAL_UART_Transmit(&huart4, &BUFF_DATA_485[0], Count, 1000);
    //Dua DE ve Receive
    RS485_Direct_off();

    return Result;
}


/*======================== Funcion Slave ======================*/
//uint8_t Slave_ACKRead_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData, uint8_t* aData)
//{
//    uint16_t crc;
//    HAL_StatusTypeDef Result = HAL_ERROR;
//    uint16_t Count = 0;
//    uint16_t i = 0;
//
//    // Ðong goi frame
//    //1 byte Add Slave
//    BUFF_DATA_485[Count++] = Address;
//    //1 byte Funcode
//    BUFF_DATA_485[Count++] = FunCode;
//    //2 byte Add Data
//    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data>>8) & 0xFF;
//    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data & 0xFF);
//    //2 byte Data length
//    BUFF_DATA_485[Count++] = (uint8_t) (LengthData>>8) & 0xFF;
//    BUFF_DATA_485[Count++] = (uint8_t) (LengthData & 0xFF);
//    //n byte data
//    for(i = 0; i < LengthData; i++)
//        BUFF_DATA_485[Count++] = *(aData + i);
//
//    //Tinh 2 byte Crc
//    crc = ModRTU_CRC(&BUFF_DATA_485[0],Count);
//    //them 2 byte crc
//
//    BUFF_DATA_485[Count++] = (uint8_t) (crc & 0xFF);
//    BUFF_DATA_485[Count++] = (uint8_t) (crc>>8) & 0xFF;
//
//    // Chon chan DE sang send
//    RS485_Direct_on();
//    // Send
//    Result = HAL_UART_Transmit(&huart1, &BUFF_DATA_485[0], Count, 1000);
//    //Dua DE ve Receive
//    RS485_Direct_off();
//
//    return Result;
//}


//uint8_t Slave_ACKWrite_Modbus (uint8_t Address, uint8_t FunCode, uint16_t Add_Data, uint16_t LengthData)
//{
//    uint16_t crc;
//    HAL_StatusTypeDef Result = HAL_ERROR;
//    uint16_t Count = 0;
//
//    // Ðong goi frame
//    //1 byte Add Slave
//    BUFF_DATA_485[Count++] = Address;
//    //1 byte Funcode
//    BUFF_DATA_485[Count++] = FunCode;
//    //2 byte Add Data
//    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data>>8) & 0xFF;
//    BUFF_DATA_485[Count++] = (uint8_t) (Add_Data & 0xFF);
//    //2 byte Data length
//    BUFF_DATA_485[Count++] = (uint8_t) (LengthData>>8) & 0xFF;
//    BUFF_DATA_485[Count++] = (uint8_t) (LengthData & 0xFF);
//    //Tinh 2 byte Crc
//    crc = ModRTU_CRC(&BUFF_DATA_485[0],Count);
//    //them 2 byte crc
//
//    BUFF_DATA_485[Count++] = (uint8_t) (crc & 0xFF);
//    BUFF_DATA_485[Count++] = (uint8_t) (crc>>8) & 0xFF;
//
//    // Chon chan DE sang send
//    RS485_Direct_on();
//    // Send
//    Result = HAL_UART_Transmit(&huart1, &BUFF_DATA_485[0], Count, 1000);
//    //Dua DE ve Receive
//    RS485_Direct_off();
//
//    return Result;
//}
