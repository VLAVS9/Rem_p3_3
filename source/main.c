/*
 * main.c
 *
 *  Created on: 1 jul. 2025
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
#include "mqtt_freertos/mqtt_freertos.h"
#include "bits.h"
#include "adc_wrapper/adc_wrapper.h"
#include "boards_tasks/boards_tasks.h"
#include "message_queue/message_queue.h"
#include "webconfig.h"


/* RTOS objects */
SemaphoreHandle_t xADCSem;
TimerHandle_t xADCTimer;
volatile bool gConvReady = false;

QueueHandle_t xMqttMsgQueue;

/* Callback del software timer: libera semáforo */
static void ADCTimerCallback(TimerHandle_t xTimer) {
	xSemaphoreGiveFromISR(xADCSem, NULL);
}
void start_adc_timer(void) {
	if (xTimerStart(xADCTimer, 0) != pdPASS) {
		PRINTF("Error al iniciar timer del adc \r\n");
	}
}
int main(void) {
	adc_config_t adcConfig;

	suscribe_to_board_topics();

	//wifi_mqtt_init();
	web_config_init();
	adc0_init();
	adc0_enable_interrupts();

	/* Crea semáforo y SW timer de 50 ms */
	xADCSem = xSemaphoreCreateBinary();
	xADCTimer = xTimerCreate("ADCTmr", pdMS_TO_TICKS(300), pdTRUE, NULL, ADCTimerCallback);

	//queues
	xMqttMsgQueue = xQueueCreate(MSG_QUEUE_LENGTH, sizeof(MqttMsg_t));
	//aqui se crean tareas
	tasks_create();

	/* Arranca scheduler */
	vTaskStartScheduler();

}
