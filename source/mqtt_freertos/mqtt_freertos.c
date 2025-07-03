/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2022, 2025 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "mqtt_freertos.h"
#include "app.h"
#include "board.h"
#include "fsl_silicon_id.h"

#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/apps/mqtt.h"
#include "lwip/tcpip.h"
#include "message_queue/message_queue.h"
#include "boards_tasks/boards_tasks.h"

// FIXME cleanup

/*******************************************************************************
 * Definitions
 ******************************************************************************/

static char incoming_topic[MAX_TOPIC_LEN];

typedef struct {
    const char *topic;
    const char *message;
} publish_args_t;

/*! @brief MQTT server host name or IP address. */
#ifndef EXAMPLE_MQTT_SERVER_HOST
#define EXAMPLE_MQTT_SERVER_HOST "broker.hivemq.com"
#endif

/*! @brief MQTT server port number. */
#ifndef EXAMPLE_MQTT_SERVER_PORT
#define EXAMPLE_MQTT_SERVER_PORT 1883
#endif

/*! @brief Stack size of the temporary lwIP initialization thread. */
#define INIT_THREAD_STACKSIZE 1024

/*! @brief Priority of the temporary lwIP initialization thread. */
#define INIT_THREAD_PRIO DEFAULT_THREAD_PRIO

/*! @brief Stack size of the temporary initialization thread. */
#define APP_THREAD_STACKSIZE 1024

/*! @brief Priority of the temporary initialization thread. */
#define APP_THREAD_PRIO DEFAULT_THREAD_PRIO

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void connect_to_mqtt(void *ctx);
static void disconnect_from_mqtt(void *ctx);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief MQTT client data. */
static mqtt_client_t *mqtt_client;

/*! @brief MQTT client ID string. */
static char client_id[(SILICONID_MAX_LENGTH * 2) + 5];

/*! @brief MQTT client information. */
static const struct mqtt_connect_client_info_t mqtt_client_info = {
    .client_id   = (const char *)&client_id[0],
    .client_user = NULL,
    .client_pass = NULL,
    .keep_alive  = 100,
    .will_topic  = NULL,
    .will_msg    = NULL,
    .will_qos    = 0,
    .will_retain = 0,
#if LWIP_ALTCP && LWIP_ALTCP_TLS
    .tls_config = NULL,
#endif
};

/*! @brief MQTT broker IP address. */
static ip_addr_t mqtt_addr;

/*! @brief Indicates connection to MQTT broker. */
static volatile bool connected = false;


static const char **g_sub_topics = NULL;
static size_t      g_sub_topics_count = 0;
/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Called when subscription request finishes.
 */
static void mqtt_topic_subscribed_cb(void *arg, err_t err)
{
    const char *topic = (const char *)arg;

    if (err == ERR_OK)
    {
        PRINTF("Subscribed to the topic \"%s\".\r\n", topic);
    }
    else
    {
        PRINTF("Failed to subscribe to the topic \"%s\": %d.\r\n", topic, err);
    }
}

/*!
 * @brief Called when there is a message on a subscribed topic.
 */
static void mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len) {
    LWIP_UNUSED_ARG(arg);
    strncpy(incoming_topic, topic, MAX_TOPIC_LEN-1);
    incoming_topic[MAX_TOPIC_LEN-1] = '\0';
}

/*!
 * @brief Called when recieved incoming published message fragment.
 */
static void mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags) {
    static char payload_buf[MAX_PAYLOAD_LEN];
    static size_t payload_pos;

    LWIP_UNUSED_ARG(arg);

    /* acúmulo bytes en payload_buf */
    size_t copy_len = (len < MAX_PAYLOAD_LEN-payload_pos-1) ? len : (MAX_PAYLOAD_LEN-payload_pos-1);
    memcpy(&payload_buf[payload_pos], data, copy_len);
    payload_pos += copy_len;
    payload_buf[payload_pos] = '\0';

    if (flags & MQTT_DATA_FLAG_LAST) {
        /* una vez completo, empaco en struct y envío a la cola */
        MqttMsg_t msg;
        strncpy(msg.topic,   incoming_topic, MAX_TOPIC_LEN-1);
        msg.topic[MAX_TOPIC_LEN-1] = '\0';
        strncpy(msg.payload, payload_buf,   MAX_PAYLOAD_LEN-1);
        msg.payload[MAX_PAYLOAD_LEN-1] = '\0';

        if (xMqttMsgQueue) {
            xQueueSend(xMqttMsgQueue, &msg, 0);
        }
        payload_pos = 0;  /* reinicio buffer para próximo mensaje */
    }
}

void mqtt_set_subscribe_topics(const char *topics[], size_t topics_count) {
    g_sub_topics = topics;
    g_sub_topics_count = topics_count;
}
/*!
 * @brief Subscribe to MQTT topics.
 */
static void mqtt_subscribe_topics(mqtt_client_t *client)
{
    const char **topics      	= g_sub_topics;
    size_t       topics_count 	= g_sub_topics_count;
    int          qos[]       	= {0, 1};
    err_t        err;

    // Configura el callback de publicación entrante
    mqtt_set_inpub_callback(client,
                            mqtt_incoming_publish_cb,
                            mqtt_incoming_data_cb,
                            LWIP_CONST_CAST(void *, &mqtt_client_info));

    if (!topics || topics_count == 0) {
        PRINTF("No hay tópicos configurados para suscripción.\r\n");
        return;
    }

    for (size_t i = 0; i < topics_count; i++)
    {
        err = mqtt_subscribe(client,
                             topics[i],
                             qos[i],
                             mqtt_topic_subscribed_cb,
                             LWIP_CONST_CAST(void *, topics[i]));

        if (err == ERR_OK) {
            PRINTF("Subscribing to the topic \"%s\" with QoS %d...\r\n",
                   topics[i], qos[i]);
        } else {
            PRINTF("Failed to subscribe to the topic \"%s\" with QoS %d: %d.\r\n",
                   topics[i], qos[i], err);
        }
    }
}


/*!
 * @brief Called when connection state changes.
 */
static void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status)
{
    const struct mqtt_connect_client_info_t *client_info = (const struct mqtt_connect_client_info_t *)arg;

    connected = (status == MQTT_CONNECT_ACCEPTED);

    switch (status)
    {
        case MQTT_CONNECT_ACCEPTED:
            PRINTF("MQTT client \"%s\" connected.\r\n", client_info->client_id);
            mqtt_subscribe_topics(client);

            if(BOARD_1 == get_selected_board()){
            	mqtt_send_message("tank/availability", "online");
            }else if(BOARD_2 == get_selected_board()){
            	mqtt_send_message("incubator/availability", "online");
            }

            start_adc_timer();
            break;

        case MQTT_CONNECT_DISCONNECTED:
            PRINTF("MQTT client \"%s\" not connected.\r\n", client_info->client_id);
            if(BOARD_1 == get_selected_board()){
            	mqtt_send_message("tank/availability", "offline");
            }else if(BOARD_2 == get_selected_board()){
            	mqtt_send_message("incubator/availability", "offline");
            }
            sys_timeout(1000, connect_to_mqtt, NULL);
            break;

        case MQTT_CONNECT_TIMEOUT:
            PRINTF("MQTT client \"%s\" connection timeout.\r\n", client_info->client_id);
            /* Try again 1 second later */
            sys_timeout(1000, connect_to_mqtt, NULL);
            break;

        case MQTT_CONNECT_REFUSED_PROTOCOL_VERSION:
        case MQTT_CONNECT_REFUSED_IDENTIFIER:
        case MQTT_CONNECT_REFUSED_SERVER:
        case MQTT_CONNECT_REFUSED_USERNAME_PASS:
        case MQTT_CONNECT_REFUSED_NOT_AUTHORIZED_:
            PRINTF("MQTT client \"%s\" connection refused: %d.\r\n", client_info->client_id, (int)status);
            /* Try again 10 seconds later */
            sys_timeout(10000, connect_to_mqtt, NULL);
            break;

        default:
            PRINTF("MQTT client \"%s\" connection status: %d.\r\n", client_info->client_id, (int)status);
            /* Try again 10 seconds later */
            sys_timeout(10000, connect_to_mqtt, NULL);
            break;
    }
}

/*!
 * @brief Starts connecting to MQTT broker. To be called on tcpip_thread.
 */
static void connect_to_mqtt(void *ctx)
{
    LWIP_UNUSED_ARG(ctx);

    PRINTF("Connecting to MQTT broker at %s...\r\n", ipaddr_ntoa(&mqtt_addr));

    mqtt_client_connect(mqtt_client, &mqtt_addr, EXAMPLE_MQTT_SERVER_PORT, mqtt_connection_cb,
                        LWIP_CONST_CAST(void *, &mqtt_client_info), &mqtt_client_info);
}

/*!
 * @brief Disconnects from MQTT broker. To be called on tcpip_thread.
 */
static void disconnect_from_mqtt(void *ctx)
{
    LWIP_UNUSED_ARG(ctx);

    mqtt_disconnect(mqtt_client);
    connected = false;
    PRINTF("Disconnected from MQTT broker.\r\n");
}

/*!
 * @brief Called when publish request finishes.
 */
static void mqtt_message_published_cb(void *arg, err_t err)
{
    const char *topic = (const char *)arg;

    if (err == ERR_OK)
    {
        //PRINTF("Published to the topic \"%s\".\r\n", topic);
    }
    else
    {
        PRINTF("Failed to publish to the topic \"%s\": %d.\r\n", topic, err);
    }
}
/* 2. Callback que LwIP invoca en tcpip_thread */
static void publish_message_cb(void *arg) {
    publish_args_t *p = (publish_args_t *)arg;


    mqtt_publish(
        mqtt_client,
        p->topic,
        p->message,
        strlen(p->message),
        1,                      /* QoS */
        0,                      /* retain */
        mqtt_message_published_cb,
        (void *)p->topic        /* user-arg */
    );
    /* liberar la memoria */
    free(p);
}
/*!
 * @brief Publishes a message. To be called on tcpip_thread.
 */
static void publish_message(void *ctx, const char *topic, const char *message)
{
    LWIP_UNUSED_ARG(ctx);

    PRINTF("Going to publish to the topic \"%s\"...\r\n", topic);

    mqtt_publish(
        mqtt_client,
        topic,
        message,
        strlen(message),
        1,                      // QoS 1
        0,                      // retain = false
        mqtt_message_published_cb,
        (void *)topic           // callback arg
    );
}


void mqtt_send_message(const char *topic, const char *message)
{
    publish_args_t *args = malloc(sizeof(*args));
    if (!args) {
        //PRINTF("mqtt_send_message: malloc failed\r\n");
        return;
    }

    args->topic   = topic;
    args->message = message;

    err_t err = tcpip_callback(publish_message_cb, args);
    if (err != ERR_OK) {
        PRINTF("mqtt_send_message: tcpip_callback error %d\r\n", err);
        free(args);
    }
}

/*!
 * @brief Application thread.
 */
static void app_thread(void *arg)
{
    struct netif *netif = (struct netif *)arg;
    err_t err;
    int i;

    PRINTF("\r\nIPv4 Address     : %s\r\n", ipaddr_ntoa(&netif->ip_addr));
    PRINTF("IPv4 Subnet mask : %s\r\n", ipaddr_ntoa(&netif->netmask));
    PRINTF("IPv4 Gateway     : %s\r\n\r\n", ipaddr_ntoa(&netif->gw));

    /*
     * Check if we have an IP address or host name string configured.
     * Could just call netconn_gethostbyname() on both IP address or host name,
     * but we want to print some info if goint to resolve it.
     */
    if (ipaddr_aton(EXAMPLE_MQTT_SERVER_HOST, &mqtt_addr) && IP_IS_V4(&mqtt_addr))
    {
        /* Already an IP address */
        err = ERR_OK;
    }
    else
    {
        /* Resolve MQTT broker's host name to an IP address */
        PRINTF("Resolving \"%s\"...\r\n", EXAMPLE_MQTT_SERVER_HOST);
        err = netconn_gethostbyname(EXAMPLE_MQTT_SERVER_HOST, &mqtt_addr);
    }

    if (err == ERR_OK)
    {
        /* Start connecting to MQTT broker from tcpip_thread */
        err = tcpip_callback(connect_to_mqtt, NULL);
        if (err != ERR_OK)
        {
            PRINTF("Failed to invoke broker connection on the tcpip_thread: %d.\r\n", err);
        }
    }
    else
    {
        PRINTF("Failed to obtain IP address: %d.\r\n", err);
    }

    /* Publish some messages */
    /*for (i = 0; i < 5;)
    {
        if (connected)
        {
            err = tcpip_callback(publish_message_cb, NULL);
            if (err != ERR_OK)
            {
                PRINTF("Failed to invoke publishing of a message on the tcpip_thread: %d.\r\n", err);
            }
            i++;
        }

        sys_msleep(1000U);
    }*/

    /* Disconnect from MQTT broker from tcpip_thread */
    /*err = tcpip_callback(disconnect_from_mqtt, NULL);
    if (err != ERR_OK)
    {
        PRINTF("Failed to invoke disconnect from broker on the tcpip_thread: %d.\r\n", err);
    }*/

    vTaskDelete(NULL);
}

static void generate_client_id(void)
{
    uint8_t silicon_id[SILICONID_MAX_LENGTH];
    const char *hex = "0123456789abcdef";
    status_t status;
    uint32_t id_len = sizeof(silicon_id);
    int idx         = 0;
    int i;
    bool id_is_zero = true;

    /* Get unique ID of SoC */
    status = SILICONID_GetID(&silicon_id[0], &id_len);
    assert(status == kStatus_Success);
    assert(id_len > 0U);
    (void)status;

    /* Covert unique ID to client ID string in form: nxp_hex-unique-id */

    /* Check if client_id can accomodate prefix, id and terminator */
    assert(sizeof(client_id) >= (5U + (2U * id_len)));

    /* Fill in prefix */
    client_id[idx++] = 'n';
    client_id[idx++] = 'x';
    client_id[idx++] = 'p';
    client_id[idx++] = '_';

    /* Append unique ID */
    for (i = (int)id_len - 1; i >= 0; i--)
    {
        uint8_t value    = silicon_id[i];
        client_id[idx++] = hex[value >> 4];
        client_id[idx++] = hex[value & 0xFU];

        if (value != 0)
        {
            id_is_zero = false;
        }
    }

    /* Terminate string */
    client_id[idx] = '\0';

    if (id_is_zero)
    {
        PRINTF(
            "WARNING: MQTT client id is zero. (%s)"
#ifdef OCOTP
            " This might be caused by blank OTP memory."
#endif
            "\r\n",
            client_id);
    }
}

/*!
 * @brief Create and run example thread
 *
 * @param netif  netif which example should use
 */
void mqtt_freertos_run_thread(struct netif *netif)
{
    LOCK_TCPIP_CORE();
    mqtt_client = mqtt_client_new();
    UNLOCK_TCPIP_CORE();
    if (mqtt_client == NULL)
    {
        PRINTF("mqtt_client_new() failed.\r\n");
        while (1);

    }

    generate_client_id();

    if (sys_thread_new("app_task", app_thread, netif, APP_THREAD_STACKSIZE, APP_THREAD_PRIO) == NULL)
    {
        LWIP_ASSERT("mqtt_freertos_start_thread(): Task creation failed.", 0);
    }
}
