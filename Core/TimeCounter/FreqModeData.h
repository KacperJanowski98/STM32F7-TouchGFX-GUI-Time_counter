/*
 * FreqModeData.h
 *
 *  Created on: 15 paź 2021
 *      Author: Kacper
 */

#ifndef TIMECOUNTER_FREQMODEDATA_H_
#define TIMECOUNTER_FREQMODEDATA_H_

#include "Session.h"

typedef struct
{
    bool hfInputState;
    uint16_t gate;
} FreqMesSetup_t;

typedef struct
{
	uint8_t numberChanel;
    bool channelState;
    Slope_t slope;
    uint32_t threshold;
} FreqChannel_t;

typedef struct
{
    FreqChannel_t Channel1;
    FreqChannel_t Channel2;
    FreqChannel_t Channel3;
    FreqChannel_t Channel4;
    FreqChannel_t Channel5;
    FreqChannel_t Channel6;
    FreqChannel_t Channel7;
    FreqChannel_t Channel8;
    FreqMesSetup_t MessSetup;
    SessionSetup_t FreqSession;
} FrequencyMode_t;

typedef struct
{
    float mean;
    float stdDev;
    Unit_t meanUnit;
    Unit_t stdDevUnit;
} MeasFreq_t;

typedef struct
{
	MeasFreq_t measure1;
	MeasFreq_t measure2;
	MeasFreq_t measure3;
	MeasFreq_t measure4;
	MeasFreq_t measure5;
	MeasFreq_t measure6;
	MeasFreq_t measure7;
	MeasFreq_t measure8;
} ResultFreq_t;

void FrequencyModeInit(FrequencyMode_t *pFrequencyMode);

void ResultFrequencyInit(ResultFreq_t *pResultFreq);

void SingleFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq);

void ContinuousFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq);

void StampsFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq);

float calculateSingleMeas(int min, int max);

void calculateRange(uint8_t number, int *min, int *max);

//:TODO zrobic jakis mechanizm aby ustawal jednostki
Unit_t setUnitMeanFreq();

void setCalculatedParamSingleFreq(FreqChannel_t *pFreqChannel, MeasFreq_t *pMeasFreq);

void resetParamSingleFreq(FreqChannel_t *pFreqChannel, MeasFreq_t *pMeasFreq);

#endif /* TIMECOUNTER_FREQMODEDATA_H_ */
