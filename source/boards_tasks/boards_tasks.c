/*
 * board_2.c
 *
 *  Created on: 2 jul. 2025
 *      Author: miguelvladimirvargassanchez
 */
#include "fsl_debug_console.h"
#include "mqtt_freertos/mqtt_freertos.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "fsl_power.h"
#include "fsl_adc.h"
#include "app.h"
#include "timers.h"
#include "bits.h"
#include "adc_wrapper/adc_wrapper.h"
#include "message_queue/message_queue.h"

Board_number_t selected_board = BOARD_2;
/* RTOS objects */
extern SemaphoreHandle_t xADCSem;
extern TimerHandle_t xADCTimer;
volatile bool g_conversionDataReady = false;
extern QueueHandle_t xMqttMsgQueue;

//Board 1
static int  prev_level            = -1;
static char prev_level_state[16]  = "";
static const char *default_topics_t1[] = {
	"tank/oxygen_request",
	"tank/alarm"
};
#define DEFAULT_TOPICS_COUNT_T1  (sizeof(default_topics_t1) / sizeof(default_topics_t1[0]))

// Board 2
uint8_t requestedOxigen = 0;
uint8_t request_oxigen_active = 0;
uint8_t currentOxigen = 0;
static const char *default_topics_t2[] = {
    "incubator/desired_oxigen_lvl"
};
#define DEFAULT_TOPICS_COUNT_T2  (sizeof(default_topics_t2) / sizeof(default_topics_t2[0]))

// Board 3
static const char *default_topics_t3[] = {
    "incubator/desired_oxigen_lvl"
};
#define DEFAULT_TOPICS_COUNT_T3  (sizeof(default_topics_t3) / sizeof(default_topics_t3[0]))

void DEMO_ADC_IRQHANDLER(void) {
	if ((ADC_GetStatusFlags(DEMO_ADC_BASE) & kADC_DataReadyInterruptFlag) != 0UL) {
		g_conversionDataReady = true;
		ADC_ClearStatusFlags(DEMO_ADC_BASE, kADC_DataReadyInterruptFlag);
	}
}
//	BOARD 1 Tasks
static void ADCTask_B1(void *pvParameters) {
	uint32_t raw;
	uint8_t pct;
	char msg[MAX_PAYLOAD_LEN];
	const char *adc_topic = "tank/oxygen_level";
	const char *tank_state = "tank/fill_state";
	while (1) {
		if (xSemaphoreTake(xADCSem, portMAX_DELAY) == pdTRUE) {
			ADC_DoSoftwareTrigger(DEMO_ADC_BASE);
			while (!g_conversionDataReady) {
			}
			raw = ADC_GetConversionResult(DEMO_ADC_BASE);
			g_conversionDataReady = false;
			ADC_StopConversion(DEMO_ADC_BASE);

			pct = (uint8_t) ((raw * 100U) / 36000U);
			currentOxigen = pct;
			snprintf(msg, sizeof(msg), "%u", pct);
			mqtt_send_message(adc_topic, msg);


		    /* Determine and publish fill_state on transition */
		    char state[16];
		    if (prev_level < 0) {
		        strcpy(state, "STABLE");
		    } else if (currentOxigen > prev_level) {
		        strcpy(state, "INCREASE");
		    } else if (currentOxigen < prev_level) {
		        strcpy(state, "DECREASE");
		    } else {
		        strcpy(state, "STABLE");
		    }
		    if (strcmp(state, prev_level_state) != 0) {

		    	mqtt_send_message(tank_state, state);

		    }
		    prev_level = currentOxigen;
		}
	}
}
static void mqtt_message_recevie_task_B1(void *pvParameters) {
	MqttMsg_t msg;

	while (1) {
		if (xQueueReceive(xMqttMsgQueue, &msg, portMAX_DELAY) == pdTRUE) {
			if (strcmp(msg.topic, "tank/oxygen_request") == 0) {
				//indicador led para prender bonba y suministrar oxigeno


			}
			if(strcmp(msg.topic, "tank/alarm") == 0){
				// led de cuando se enciende alarma
			}
		}
	}
}
// BOARD 2 Tasks
static void ADCTask_B2(void *pvParameters) {
	uint32_t raw;
	uint8_t pct;
	char msg[MAX_PAYLOAD_LEN];
	const char *adc_topic = "incubator/oxigen_lvl";
	while (1) {
		if (xSemaphoreTake(xADCSem, portMAX_DELAY) == pdTRUE) {
			ADC_DoSoftwareTrigger(DEMO_ADC_BASE);
			while (!g_conversionDataReady) {
			}
			raw = ADC_GetConversionResult(DEMO_ADC_BASE);
			g_conversionDataReady = false;
			ADC_StopConversion(DEMO_ADC_BASE);

			pct = (uint8_t) ((raw * 100U) / 36000U);
			currentOxigen = pct;
			snprintf(msg, sizeof(msg), "%u", pct);
			mqtt_send_message(adc_topic, msg);

			uint8_t diff =
					(requestedOxigen > currentOxigen) ?
							requestedOxigen - currentOxigen :
							currentOxigen - requestedOxigen;

			if (diff > 10 && requestedOxigen != 0) {
				mqtt_send_message("tank/oxygen_request", "ON");
				request_oxigen_active = 1;
			} else if (diff <= 10) {
				mqtt_send_message("tank/oxygen_request", "OFF");
				request_oxigen_active = 0;
			}
		}
	}
}
static void mqtt_message_recevie_task_B2(void *pvParameters) {
	MqttMsg_t msg;
	while (1) {
		if (xQueueReceive(xMqttMsgQueue, &msg, portMAX_DELAY) == pdTRUE) {
			if (strcmp(msg.topic, "incubator/desired_oxigen_lvl") == 0) {

				requestedOxigen = (uint8_t) atoi(msg.payload);

			}
		}
	}
}
// BOARD 3 Tasks
static void mqtt_message_recevie_task_B3(void *pvParameters) {
	MqttMsg_t msg;
	while (1) {
		if (xQueueReceive(xMqttMsgQueue, &msg, portMAX_DELAY) == pdTRUE) {
			if (strcmp(msg.topic, "incubator/desired_oxigen_lvl") == 0) {

				requestedOxigen = (uint8_t) atoi(msg.payload);

			}
		}
	}
}
Board_number_t get_selected_board(void){
	return selected_board;
}

void suscribe_to_board_topics(void){
	if(BOARD_1 == selected_board){
		mqtt_set_subscribe_topics(default_topics_t1, DEFAULT_TOPICS_COUNT_T1);
	}else if (BOARD_2 == selected_board){
		mqtt_set_subscribe_topics(default_topics_t2, DEFAULT_TOPICS_COUNT_T2);
	}else if(BOARD_3 == selected_board){

	}

}
void tasks_create(void){
	/* Crea la tarea que muestrea el ADC */
	if(BOARD_1 == selected_board){
		xTaskCreate(ADCTask_B1, "ADC", ADC_TASK_STACK, NULL, ADC_TASK_PRIORITY, NULL);
		xTaskCreate(mqtt_message_recevie_task_B1, "mqtt_message_recevie_task", configMINIMAL_STACK_SIZE + 50, NULL, tskIDLE_PRIORITY + 1, NULL);
	}else if(BOARD_2 == selected_board){
		xTaskCreate(ADCTask_B2, "ADC", ADC_TASK_STACK, NULL, ADC_TASK_PRIORITY, NULL);
		xTaskCreate(mqtt_message_recevie_task_B2, "mqtt_message_recevie_task", configMINIMAL_STACK_SIZE + 50, NULL, tskIDLE_PRIORITY + 1, NULL);

	}else if(BOARD_3 == selected_board){

	}
}
