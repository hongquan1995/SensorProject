/*
 * L506.h
 *
 *  Created on: Jul 4, 2021
 *      Author: 0
 */

#ifndef INC_L506_H_
#define INC_L506_H_

#include <stdbool.h>
#include <my_lib.h>

#define 	CMD_PWNON					-1

#define MY_CONNECT             0x10
#define MY_CONNACK             0x20
#define MY_PUBLISH             0x32
#define MY_PUBACK              0x40
#define MY_SUBSCRIBE           0x82
#define MY_SUBACK              0x90


typedef uint8_t (*fncProcess)(struct_string);

typedef struct{
	uint8_t* packetAt;
	uint16_t length;
}message_AT;

typedef struct{
	uint8_t num;
	message_AT strSend;
	fncProcess fncType;
}t_uartAt;


typedef enum
{
	CHECK_CMD_AT = 0,
	CHECK_STATUS_SIM,
	CHECK_CMD_CSQ,
	CHECK_STATUS_NETWORK,
	CMD_REPORT_NETWORK,
	CHECK_ATTACHED_STATUS,
	CMD_CIPTIMEOUT,
	CHECK_MODE_TCP,
	CHECK_CMD_NETOPEN,
	CMD_GET_IPADDR,
	CMD_CREATE_TCP,
	CHECK_CMD_CIPOPQUERY,
	AT_SEND,
//	MQTT_SEND_CONNECT
//	CMD_CONNECT_MQTT
	CMD_PUBLISH_MQTT
}cmd_sim4G;


void Sim_PWON();
void Sim_PWOFF();
void Pow_ON_OFF();
void getBuffRx(bool needWaitAtFirstTime);
void GSM_Init();


uint8_t fnParseOKPacket(struct_string arrRes);
uint8_t fnParseCPINPacket(struct_string arrRes);
uint8_t fnParseCSQPacket(struct_string arrRes);
uint8_t fnParseCGREGPacket(struct_string arrRes);
uint8_t fnParseCREGPacket(struct_string arrRes);
uint8_t fnParseCGATTPacket(struct_string arrRes);
uint8_t fnParseNETOPENPacket(struct_string arrRes);
uint8_t fnParseIPADDRPacket(struct_string arrRes);
uint8_t fnCheckCreateTCPPacket(struct_string arrRes);
uint8_t fnParseCIPOPQUERYPacket(struct_string arrRes);
uint8_t fnParseSendSVPacket(struct_string arrRes);
uint8_t fnCheckDataConack(struct_string arrRes);
uint8_t fnParseReceiveSVPacket(struct_string arrRes);

uint8_t fnCheckPacket(uint8_t* packet, uint16_t len, fncProcess fnParse, uint16_t delayWaitRxMs);
void fncSend_CommandAT(uint8_t curr_cmd, uint8_t next_cmd);
void Sim_work(void);
void fncSend_ATSend(uint8_t *arrSend, uint32_t lendata, uint8_t next_cmd);
void wait_to_reinitial(uint8_t time);
void wait_to_reinitialTCP(uint8_t time);

#endif /* INC_L506_H_ */
