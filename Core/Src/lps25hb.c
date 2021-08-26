/*
 * lps25hb.c
 *
 *  Created on: Aug 26, 2021
 *      Author: Kacper Janowski
 */

#include "lps25hb.h"

extern osSemaphoreId_t binarySemLPS25Handle;

int msgRdyFlag = 0;
int16_t result1T = 0;
int16_t result2T = 0;
int16_t result1P = 0;
int16_t result2P = 0;
int32_t pressure = 0;
int16_t temperature = 0;

void lps25hbInit()
{
	LPS25_SPI_Init(Rate_12Hz5, SPI4w);
}

void lps25hb()
{
	LPS25_SPI_GetTemp(&temperature);
	LPS25_SPI_GetPress(&pressure);

	result1T = abs((20400+(int32_t)temperature)/480);
	result2T = abs((((20400+(int32_t)temperature)*10)/480)%10);

	result1P = abs((pressure)/4096);
	result2P = abs(((pressure*10)/4096)%10);

	msgRdyFlag = 1;

	if (msgRdyFlag)
	{
		osSemaphoreRelease(binarySemLPS25Handle);
		msgRdyFlag = 0;
	}
}
