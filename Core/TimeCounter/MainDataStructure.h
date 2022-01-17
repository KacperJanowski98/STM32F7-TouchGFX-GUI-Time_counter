/*
 * MainDataStructure.h
 *
 *  Created on: 17 sty 2022
 *      Author: Kacper
 */

#ifndef TIMECOUNTER_MAINDATASTRUCTURE_H_
#define TIMECOUNTER_MAINDATASTRUCTURE_H_

#include "TimeModeData.h"
#include "FreqModeData.h"


typedef struct
{
	uint8_t version;
	uint32_t detectedThreshold;
	TimeMode_t TimeData;
	ResultTime_t ResultTimeData;
	FrequencyMode_t FrequencyData;
	ResultFreq_t ResultFrequencyData;
} DataExchange_t;

void DataExchangeInit(DataExchange_t *pDataExchange);


#endif /* TIMECOUNTER_MAINDATASTRUCTURE_H_ */
