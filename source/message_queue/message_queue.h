/*
 * message_queue.h
 *
 *  Created on: 16 jun. 2025
 *      Author: miguelvladimirvargassanchez
 */

#ifndef MESSAGE_QUEUE_MESSAGE_QUEUE_H_
#define MESSAGE_QUEUE_MESSAGE_QUEUE_H_

#include "FreeRTOS.h"
#include "queue.h"

#define MSG_QUEUE_LENGTH   10
#define MAX_TOPIC_LEN      32
#define MAX_PAYLOAD_LEN    16

typedef struct {
    char topic[MAX_TOPIC_LEN];
    char payload[MAX_PAYLOAD_LEN];
} MqttMsg_t;

extern QueueHandle_t xMqttMsgQueue;


#endif /* MESSAGE_QUEUE_MESSAGE_QUEUE_H_ */
