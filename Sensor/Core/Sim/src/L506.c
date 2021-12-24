/*
 * L506.c
 *
 *  Created on: Jul 4, 2021
 *      Author: 0
 */

#include "stm32l4xx_hal.h"
#include "time.h"
#include "string.h"
#include "stdlib.h"
#include "my_lib.h"
#include "stdbool.h"
#include "MQTTPacket.h"
#include "mqtt.h"
#include "cmsis_os.h"
#include "L506.h"
#include "UartRingbuffer.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

extern uint8_t vr_count;
extern uint32_t Time_send_sv;

int8_t gsm_state = -1;
uint8_t result;
uint8_t answer;
uint8_t count_time = 0;

extern struct_string gsm_uart;
extern uint32_t RT_Count_Systick_u32;
uint32_t Systick_Last_Recerver_u32;

//static uint8_t arr_cmd_send[] = "AT+CIPSEND=1,";

const uint8_t DataConack_8a[4] = {MY_CONNACK, 0x02, 0x00, 0x00};				//ma ban tin tra ve neu connect MQTT OK
static uint8_t serverText1[] = "gui thanh cong ban tin len server\r\n";
static uint8_t serverText2[] = "gui khong thanh cong ban tin len server\r\n";


t_uartAt arrInitialSim[]={{CHECK_CMD_AT, 				{(uint8_t*)"AT\r\n",4},															fnParseOKPacket},
					  	  {CHECK_STATUS_SIM, 			{(uint8_t*)"AT+CPIN?\r\n",10},													fnParseCPINPacket},
						  {CHECK_CMD_CSQ,	 			{(uint8_t*)"AT+CSQ\r\n",8},														fnParseCSQPacket},
						  {CHECK_STATUS_NETWORK, 		{(uint8_t*)"AT+CGREG?\r\n",11},													fnParseCGREGPacket},
						  {CMD_REPORT_NETWORK,			{(uint8_t*)"AT+CREG?\r\n",10},													fnParseCREGPacket},
						  {CHECK_ATTACHED_STATUS, 		{(uint8_t*)"AT+CGATT?\r\n",11},													fnParseCGATTPacket},
						  {CMD_CIPTIMEOUT, 				{(uint8_t*)"AT+CIPTIMEOUT=30000,20000,40000,50000\r\n",39},						fnParseOKPacket},
						  {CHECK_MODE_TCP, 				{(uint8_t*)"AT+CIPMODE=0\r\n",14},												fnParseOKPacket},
						  {CHECK_CMD_NETOPEN, 			{(uint8_t*)"AT+NETOPEN\r\n",12},												fnParseNETOPENPacket},
						  {CMD_GET_IPADDR, 				{(uint8_t*)"AT+IPADDR\r\n",11},													fnParseIPADDRPacket},
						  {CMD_CREATE_TCP, 				{(uint8_t*)"AT+CIPOPEN=1,\"TCP\",\"broker.mqttdashboard.com\",1883\r\n",56},	fnCheckCreateTCPPacket},
						  {CHECK_CMD_CIPOPQUERY, 		{(uint8_t*)"AT+CIPOPQUERY=1\r\n",17},											fnParseCIPOPQUERYPacket},
						  {AT_SEND, 					{(uint8_t*)"AT+CIPSEND=1,", 13},												fnParseSendSVPacket}};
//						  {MQTT_PUBLISH, 				{(uint8_t*)"AT+CIPSEND=1,", 13},												fnParseSendSVPacket}};


void Sim_PWON(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
}

void Sim_PWOFF(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}

void Pow_ON_OFF(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	osDelay(1000);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
	osDelay(1000);
}

void getBuffRx(bool needWaitAtFirstTime) {
	if(needWaitAtFirstTime) {
		while(!IsDataAvailable());
	}
	while(IsDataAvailable()){
		gsm_uart.buffer[gsm_uart.buffer_index] = Uart_read();
		gsm_uart.buffer_index ++;
		osDelay(1);
	}
	// xử lý THA
}

void GSM_Init(){
	  Pow_ON_OFF();;
	  Sim_PWON();
	  osDelay(2000);
	  Sim_PWOFF();
	  osDelay(25000);
	  gsm_uart.buffer_index = 0;
	  memset(gsm_uart.buffer, '\0', 256);
	  getBuffRx(true);
	  HAL_UART_Transmit(&huart1, gsm_uart.buffer, strlen((char*)gsm_uart.buffer), 1000);
}

uint8_t fnParseOKPacket(struct_string arrRes) { 			//kiem tra Sim
	if(memcmp((const char*)arrRes.buffer, (const char*)"\r\nOK", 4) == 0){
		return 1;
	}
    return 0;
}

uint8_t fnParseCPINPacket(struct_string arrRes) {			// kiem tra trang thai cua Sim
  if (memcmp(arrRes.buffer, "\r\n+CPIN: READY", 14) == 0) {
    return 1;
  }
  return 0;
}

uint8_t fnParseCSQPacket(struct_string arrRes) {			// kiem tra cuong do song
  if (memcmp(arrRes.buffer, "\r\n+CSQ:", 7) == 0) {
    return 1;
  }
  return 0;
}

uint8_t fnParseCGREGPacket(struct_string arrRes) {			// dang ki mạng
  if (memcmp(arrRes.buffer, "\r\n+CGREG:", 9) == 0) {
    return 1;
  }
  return 0;
}

uint8_t fnParseCREGPacket(struct_string arrRes) {			// dang ki mang
  if (memcmp(arrRes.buffer, "\r\n+CREG:", 8) == 0) {
    return 1;
  }
  return 0;
}

uint8_t fnParseCGATTPacket(struct_string arrRes) { 			// kiem tra trang thai GPRS
  if (memcmp(arrRes.buffer, "\r\n+CGATT:", 9) == 0) {
    return 1;
  }
  return 0;
}

uint8_t fnParseNETOPENPacket(struct_string arrRes) {		// mo mang thanh cong
	char *ptr;
	ptr = strstr((char*)arrRes.buffer, "NETOPEN:SUCCESS");
	if(ptr != 0){
		return 1;
	}
	return 0;
}

uint8_t fnParseIPADDRPacket(struct_string arrRes) {			// nhan dia chi IP
	char *ptr;
	ptr = strstr((char*)arrRes.buffer, "IPADDR:SUCCESS");
	if(ptr != 0){
		return 1;
	}
	return 0;
}

uint8_t fnCheckCreateTCPPacket(struct_string arrRes) {		// thiet lap ket noi TCP/UDP thanh cong
	char *ptr;
	ptr = strstr((char*)arrRes.buffer, "CIPOPEN:SUCCESS");
	if(ptr != 0){
		return 1;
	}
	return 0;
}

uint8_t fnParseCIPOPQUERYPacket(struct_string arrRes) {		// quet link ket noi
  if (memcmp(arrRes.buffer, "\r\n+CIPOPQUERY:0", 15) == 0) {
    return 0;
  }
  return 1;
}

uint8_t fnParseSendSVPacket(struct_string arrRes) {			// kiem tra phan hoi gui
  if (memcmp(arrRes.buffer, "\r\n>", 3) == 0) {
    return 1;
  }
  return 0;
}

uint8_t fnCheckDataConack(struct_string arrRes) {			// kiem tra da gui thanh cong?
	char *ptr;
	ptr = strstr((char*)arrRes.buffer, "0x20 0x03 00 00 ");
	if(ptr != 0){
		return 1;
	}
	return 0;
}


uint8_t fnParseReceiveSVPacket(struct_string arrRes) {		// kiem tra phan hoi nhan
	char *ptr;
	ptr = strstr((char*)arrRes.buffer, "CIPRXGET:SUCCESS");
	if(ptr != 0){
		return 1;
	}
	return 0;
}

uint8_t fnCheckPacket(uint8_t* packet, uint16_t len, fncProcess fnParse, uint16_t delayWaitRxMs) { // ham gui du lieu co kiem tra phan hoi
	 gsm_uart.buffer_index = 0;
	 bool isFirstCall = true;
	 memset(gsm_uart.buffer, '\0', 256);
//	 HAL_UART_Transmit(&huart3, packet, len, 1000);
	 Uart_sendArray ((char*)packet,(int)len);// Send dữ liệu
	 HAL_UART_Transmit(&huart1, packet, len, 1000);
	 answer = 0;
	 Systick_Last_Recerver_u32 = RT_Count_Systick_u32;
	 while(Check_Time_Out(Systick_Last_Recerver_u32, delayWaitRxMs) == false && answer == 0) {
		getBuffRx(isFirstCall);
		isFirstCall = false;
		if (fnParse) {
			answer = fnParse(gsm_uart);
		}
			 osDelay(1);
		 }
	 HAL_UART_Transmit(&huart1, gsm_uart.buffer, strlen((char*)gsm_uart.buffer), 1000);
	 return answer;
}


void fncSend_CommandAT(uint8_t curr_cmd, uint8_t next_cmd){
		result = fnCheckPacket(arrInitialSim[curr_cmd].strSend.packetAt, arrInitialSim[curr_cmd].strSend.length, arrInitialSim[curr_cmd].fncType, 1000);
		if(result != 0){
			gsm_state = next_cmd;
		}
		else {
			if(CHECK_CMD_CIPOPQUERY == curr_cmd){
				wait_to_reinitialTCP(10);
			}
			else {
				wait_to_reinitial(10);
			}
		}
}


void Sim_work(void){
  switch (gsm_state){
  	 case CMD_PWNON:
  		  GSM_Init();
  		  gsm_state = CHECK_CMD_AT;
  		  break;
  	 case CHECK_CMD_AT:
  		  fncSend_CommandAT(CHECK_CMD_AT, CHECK_STATUS_SIM);
  		  break;
  	 case CHECK_STATUS_SIM:
  		  fncSend_CommandAT(CHECK_STATUS_SIM, CHECK_CMD_CSQ);
  		  break;
  	 case CHECK_CMD_CSQ:
  		  fncSend_CommandAT(CHECK_CMD_CSQ, CHECK_STATUS_NETWORK);
  		  break;
  	 case CHECK_STATUS_NETWORK:
  		  fncSend_CommandAT(CHECK_STATUS_NETWORK, CMD_REPORT_NETWORK);
   		  break;
  	 case CMD_REPORT_NETWORK:
  		  fncSend_CommandAT(CMD_REPORT_NETWORK, CHECK_ATTACHED_STATUS);
    	  break;
  	 case CHECK_ATTACHED_STATUS:
  		  fncSend_CommandAT(CHECK_ATTACHED_STATUS, CMD_CIPTIMEOUT);
     	  break;
  	 case CMD_CIPTIMEOUT:
  		  fncSend_CommandAT(CMD_CIPTIMEOUT, CHECK_MODE_TCP);
      	  break;
  	 case CHECK_MODE_TCP:
  		  fncSend_CommandAT(CHECK_MODE_TCP, CHECK_CMD_NETOPEN);
       	  break;
 	 case CHECK_CMD_NETOPEN:
 		  fncSend_CommandAT(CHECK_CMD_NETOPEN, CMD_GET_IPADDR);
          break;
 	 case CMD_GET_IPADDR:
 		  fncSend_CommandAT(CMD_GET_IPADDR, CMD_CREATE_TCP);
          break;
 	 case CMD_CREATE_TCP:
 		  fncSend_CommandAT(CMD_CREATE_TCP, CHECK_CMD_CIPOPQUERY);
          break;
 	 case CHECK_CMD_CIPOPQUERY:
 		  fncSend_CommandAT(CHECK_CMD_CIPOPQUERY, AT_SEND);
          break;
 	 case AT_SEND:
 		  mqtt_connect(0, 0, "GSM_LENO", 1200);
 		  osDelay(2000);
 		  break;
	 case CMD_PUBLISH_MQTT:
		 mqtt_publish("gsm/lino/l506", "quan123");
		 osDelay(2000);
 		  break;
  	  }
}

void Package_CIPSEND(char *fullCmdSend, uint32_t *lengh, uint32_t lendata){
	char numArr[20]= {0};
	char endChar[] = "\r\n";
	itoa(lendata, numArr, 10);
	strcat(numArr, endChar);
	strcpy(fullCmdSend, (const char*)arrInitialSim[AT_SEND].strSend.packetAt);
	strcat(fullCmdSend, numArr);
	*lengh = arrInitialSim[AT_SEND].strSend.length + strlen(numArr);
}

void fncSend_ATSend(uint8_t *arrSend, uint32_t lendata, uint8_t next_cmd){
	char fullCmdSend[20] = {0};
	uint32_t lengh = 0;
	Package_CIPSEND(fullCmdSend, &lengh, lendata);
	result = fnCheckPacket((uint8_t*)fullCmdSend, lengh, arrInitialSim[AT_SEND].fncType, 1000);
	if(result != 0){
		result = fnCheckPacket(arrSend, lendata, fnCheckDataConack, 1000);
		if(result != 0){
			 gsm_state = next_cmd;
			 HAL_UART_Transmit(&huart1,serverText1, strlen((char*)serverText1), 1000);
		}
		else
			 HAL_UART_Transmit(&huart1,serverText2, strlen((char*)serverText2), 1000);
	}
	else
		wait_to_reinitial(10);
}

// ham cho de khoi tao lai
void wait_to_reinitial(uint8_t time){
	count_time++;
		 if(count_time == time){
		  	gsm_state = CMD_PWNON;
		  	count_time = 0;
		  }
}

// ham quay lai khoi tao TCP
void wait_to_reinitialTCP(uint8_t time){
	count_time++;
		 if(count_time == time){
		  	gsm_state = CMD_CREATE_TCP;
		  	count_time = 0;
		  }
}

