/*
 * mqtt.c
 *
 *  Created on: Oct 5, 2021
 *      Author: 0
 */


#include "stm32l4xx_hal.h"
#include "MQTTPacket.h"
#include "L506.h"

void mqtt_connect(char *username, char *pass, char *id, uint32_t keep_alive)
{
	uint8_t ret = 0;
    uint8_t buf[128] = {0};
    MQTTPacket_connectData mqtt_packet = MQTTPacket_connectData_initializer;

    mqtt_packet.username.cstring = username;//username;
    mqtt_packet.password.cstring = pass;//pass;
    mqtt_packet.clientID.cstring = id;//clientID;
    mqtt_packet.keepAliveInterval = keep_alive;
    mqtt_packet.cleansession = 1;
    int len = MQTTSerialize_connect(buf, sizeof(buf), &mqtt_packet);
    ret = fncSend_DataServer(buf, len);
}

void mqtt_publish(char* topic, char* data)
{
    uint8_t buf[256] = {0};
    uint8_t ret = 0;
    MQTTString topicString = MQTTString_initializer;
    topicString.cstring = topic;
    int mqtt_len = MQTTSerialize_publish(buf, sizeof(buf), 0, 0, 0, 0, topicString, (uint8_t*) data, strlen(data));
    ret = fncSend_DataServer(buf, mqtt_len);
}
