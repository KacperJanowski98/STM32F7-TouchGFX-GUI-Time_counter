/*
 * MainDataStructure.c
 *
 *  Created on: 17 sty 2022
 *      Author: Kacper
 */

#include "MainDataStructure.h"

void DataExchangeInit(DataExchange_t *pDataExchange)
{
	TimeModeInit(&pDataExchange->TimeData);
	ResultTimeInit(&pDataExchange->ResultTimeData);
	FrequencyModeInit(&pDataExchange->FrequencyData);
	ResultFrequencyInit(&pDataExchange->ResultFrequencyData);
}
