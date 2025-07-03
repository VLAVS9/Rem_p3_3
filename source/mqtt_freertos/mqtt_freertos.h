/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MQTT_FREERTOS_H
#define MQTT_FREERTOS_H

#include "lwip/netif.h"

/*!
 * @brief Create and run example thread
 *
 * @param netif  netif which example should use
 */
void mqtt_freertos_run_thread(struct netif *netif);
void mqtt_send_message(const char *topic, const char *message);

void mqtt_set_subscribe_topics(const char *topics[], size_t topics_count);

void mqtt_send_message(const char *topic, const char *message);
void mqtt_freertos_run_thread(struct netif *netif);
static void publish_message_cb(void *arg);
void mqtt_freertos_run_thread(struct netif *netif);
#endif /* MQTT_FREERTOS_H */
