/*
 * adc_wrapper.c
 *
 *  Created on: 1 jul. 2025
 *      Author: miguelvladimirvargassanchez
 */
#include "fsl_adc.h"
#include "adc_wrapper.h"
#include "fsl_debug_console.h"

void adc0_init(void) {
	adc_config_t adcConfig;

	ADC_GetDefaultConfig(&adcConfig);
	adcConfig.vrefSource = kADC_Vref1P2V;
	adcConfig.inputMode = kADC_InputSingleEnded;
	adcConfig.conversionMode = kADC_ConversionOneShot;
	adcConfig.inputGain = kADC_InputGain1;
	adcConfig.resolution = kADC_Resolution16Bit;
	adcConfig.fifoThreshold = kADC_FifoThresholdData1;
	adcConfig.averageLength = kADC_Average16;
	adcConfig.enableInputGainBuffer = true;
	adcConfig.enableADC = true;
	adcConfig.enableInputBufferChop = false;

	ADC_Init(DEMO_ADC_BASE, &adcConfig);

	//initial calibration }
	if (ADC_DoAutoCalibration(DEMO_ADC_BASE, kADC_CalibrationVrefInternal)
			!= kStatus_Success) {
		PRINTF("\r\nCalibration Failed!\r\n");
		while (1)
			;
	}

	PRINTF("\r\nCalibration Success!\r\n");
}

void adc0_enable_interrupts(void) {
	PRINTF("\r\nCalibration Success!\r\n");
	ADC_ClearStatusFlags(DEMO_ADC_BASE, kADC_DataReadyInterruptFlag);
	ADC_SetScanChannel(DEMO_ADC_BASE, kADC_ScanChannel0, DEMO_ADC_CHANNEL_SOURCE);
	ADC_EnableInterrupts(DEMO_ADC_BASE, kADC_DataReadyInterruptEnable);
	EnableIRQ(DEMO_ADC_IRQn);
}
