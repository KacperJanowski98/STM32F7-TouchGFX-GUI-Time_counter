/*
 * lps25hb.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Kacper Janowski
 */

#include "lps25hb.h"

extern osSemaphoreId_t binarySemLPS25Handle;

int msgRdyFlag = 0;

void lps25hbInit(LPS25HB_measurement_t *hMeasure, LPS25HB_Result_t *hResult, LPS25_ODR_TypeDef odrReg, LPS25_SPIMode_TypeDef SPIMode)
{
	hResult->result1P = 0;
	hResult->result2P = 0;
	hResult->result1T = 0;
	hResult->result2T = 0;

	hMeasure->temperature = 0;
	hMeasure->pressure = 0;

	LPS25_SPI_Init(odrReg, SPIMode);
}

void lps25hb(LPS25HB_measurement_t *hMeasure, LPS25HB_Result_t *hResult)
{
	LPS25_SPI_GetTemp(&hMeasure->temperature);
	LPS25_SPI_GetPress(&hMeasure->pressure);

	hResult->result1T = abs((20400+(int32_t)hMeasure->temperature)/480);
	hResult->result2T = abs((((20400+(int32_t)hMeasure->temperature)*10)/480)%10);

	hResult->result1P = abs((hMeasure->pressure)/4096);
	hResult->result2P = abs(((hMeasure->pressure*10)/4096)%10);

	msgRdyFlag = 1;

	if (msgRdyFlag)
	{
		osSemaphoreRelease(binarySemLPS25Handle);
		msgRdyFlag = 0;
	}
}
