/*
 * MainDataStructure.c
 *
 *  Created on: 17 sty 2022
 *      Author: Kacper
 */

#include "MainDataStructure.h"

void DataExchangeInit(DataExchange_t *pDataExchange)
{
	pDataExchange->detectedThreshold = 0;
	TimeModeInit(&pDataExchange->TimeData);
	ResultTimeInit(&pDataExchange->ResultTimeData);
	ResultTimeParameterConstInit(&pDataExchange->ResultCalcConstTime);
	ResultTimeParameterStampsInit(&pDataExchange->ResultCalcStampsTime);
	FrequencyModeInit(&pDataExchange->FrequencyData);
	ResultFrequencyInit(&pDataExchange->ResultFrequencyData);
	ResultFreqParameterConstInit(&pDataExchange->ResultCalcConstFreq);
	ResultFreqStampsInit(&pDataExchange->ResultCalcStampsFreq);
}
