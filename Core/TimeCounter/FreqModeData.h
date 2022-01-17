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
	CalcConstParam_t parameters1;
	CalcConstParam_t parameters2;
	CalcConstParam_t parameters3;
	CalcConstParam_t parameters4;
	CalcConstParam_t parameters5;
	CalcConstParam_t parameters6;
	CalcConstParam_t parameters7;
	CalcConstParam_t parameters8;
	uint16_t iteration;
} ResultConstCalcFreq_t;

typedef struct
{
	CalcStampParam_t parameters1;
	CalcStampParam_t parameters2;
	CalcStampParam_t parameters3;
	CalcStampParam_t parameters4;
	CalcStampParam_t parameters5;
	CalcStampParam_t parameters6;
	CalcStampParam_t parameters7;
	CalcStampParam_t parameters8;
} ResultStampsCalcFreq_t;

typedef struct
{
	MeasValues_t measure1;
	MeasValues_t measure2;
	MeasValues_t measure3;
	MeasValues_t measure4;
	MeasValues_t measure5;
	MeasValues_t measure6;
	MeasValues_t measure7;
	MeasValues_t measure8;
} ResultFreq_t;

void FrequencyModeInit(FrequencyMode_t *pFrequencyMode);

void ResultFreqParameterConstInit(ResultConstCalcFreq_t *pResultConstCalcFreq);

void ResultFreqStampsInit(ResultStampsCalcFreq_t *pResultStampsCalcFreq);

void ResultFrequencyInit(ResultFreq_t *pResultFreq);

void SingleFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq);

void ContinuousFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq, ResultConstCalcFreq_t *pResultCalc);

void StampsFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq, ResultStampsCalcFreq_t *pResultCalc);

void calculateRange(uint8_t numberCh, int *min, int *max);

Unit_t setUnitMeanFreq(uint8_t numberCh);

void setCalculatedParamSingleFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq);

void setCalculatedParamConstFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq, CalcConstParam_t *pCalcParam);

void setCalculatedParamStampsFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq, SessionSetup_t *pSessionSetup, CalcStampParam_t *pCalcParam);

void resetParamSingleFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq);

#endif /* TIMECOUNTER_FREQMODEDATA_H_ */
