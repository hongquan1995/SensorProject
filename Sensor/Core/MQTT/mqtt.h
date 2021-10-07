/*
 * mqtt.h
 *
 *  Created on: Oct 5, 2021
 *      Author: 0
 */

#ifndef MQTT_MQTT_H_
#define MQTT_MQTT_H_

void mqtt_connect(char *username, char *pass, char *id, uint32_t keep_alive);
void mqtt_publish(char *topic, char *data);

#endif /* MQTT_MQTT_H_ */
