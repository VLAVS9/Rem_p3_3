/*
 * adc_wrapper.h
 *
 *  Created on: 1 jul. 2025
 *      Author: miguelvladimirvargassanchez
 */

#ifndef ADC_WRAPPER_ADC_WRAPPER_H_
#define ADC_WRAPPER_ADC_WRAPPER_H_

/* ADC defines */
#define DEMO_ADC_BASE           GAU_GPADC0
#define DEMO_ADC_CHANNEL_SOURCE kADC_CH4
#define DEMO_ADC_IRQHANDLER     GAU_GPADC0_INT_FUNC11_IRQHandler
#define DEMO_ADC_IRQn           GAU_GPADC0_INT_FUNC11_IRQn

/* Prioridad y stack */
#define ADC_TASK_PRIORITY       (configMAX_PRIORITIES - 1)
#define ADC_TASK_STACK          (configMINIMAL_STACK_SIZE + 100)

void adc0_init(void);
void adc0_enable_interrupts(void);

#endif /* ADC_WRAPPER_ADC_WRAPPER_H_ */
