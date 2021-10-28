/*
 * FreqModeData.c
 *
 *  Created on: 15 paź 2021
 *      Author: Kacper
 */

#include "FreqModeData.h"

void FrequencyModeInit(FrequencyMode_t *pFrequencyMode)
{
	pFrequencyMode->Channel1.numberChanel = 0;
    pFrequencyMode->Channel1.channelState = false;
    pFrequencyMode->Channel1.slope = UP;
    pFrequencyMode->Channel1.threshold = 0;

    pFrequencyMode->Channel2.numberChanel = 0;
    pFrequencyMode->Channel2.channelState = false;
    pFrequencyMode->Channel2.slope = UP;
    pFrequencyMode->Channel2.threshold = 0;

    pFrequencyMode->Channel3.numberChanel = 0;
    pFrequencyMode->Channel3.channelState = false;
    pFrequencyMode->Channel3.slope = UP;
    pFrequencyMode->Channel3.threshold = 0;

    pFrequencyMode->Channel4.numberChanel = 0;
    pFrequencyMode->Channel4.channelState = false;
    pFrequencyMode->Channel4.slope = UP;
    pFrequencyMode->Channel4.threshold = 0;

    pFrequencyMode->Channel5.numberChanel = 0;
    pFrequencyMode->Channel5.channelState = false;
    pFrequencyMode->Channel5.slope = UP;
    pFrequencyMode->Channel5.threshold = 0;

    pFrequencyMode->Channel6.numberChanel = 0;
    pFrequencyMode->Channel6.channelState = false;
    pFrequencyMode->Channel6.slope = UP;
    pFrequencyMode->Channel6.threshold = 0;

    pFrequencyMode->Channel7.numberChanel = 0;
    pFrequencyMode->Channel7.channelState = false;
    pFrequencyMode->Channel7.slope = UP;
    pFrequencyMode->Channel7.threshold = 0;

    pFrequencyMode->Channel8.numberChanel = 0;
    pFrequencyMode->Channel8.channelState = false;
    pFrequencyMode->Channel8.slope = UP;
    pFrequencyMode->Channel8.threshold = 0;

    pFrequencyMode->MessSetup.hfInputState = false;
    pFrequencyMode->MessSetup.gate = 0;

    pFrequencyMode->FreqSession.maxRange = false;
    pFrequencyMode->FreqSession.clock = INTERNAL_QUARTZ;
    pFrequencyMode->FreqSession.repeat = 0;
    pFrequencyMode->FreqSession.stampsNumber = 0;
    pFrequencyMode->FreqSession.tiRange = 0;
}

void ResultFrequencyInit(ResultFreq_t *pResultFreq)
{
	pResultFreq->measure1.mean = 0.0f;
	pResultFreq->measure1.stdDev = 0.0f;
	pResultFreq->measure1.meanUnit = KILO;
	pResultFreq->measure1.stdDevUnit = MICRO;

	pResultFreq->measure2.mean = 0.0f;
	pResultFreq->measure2.stdDev = 0.0f;
	pResultFreq->measure2.meanUnit = KILO;
	pResultFreq->measure2.stdDevUnit = MICRO;

	pResultFreq->measure3.mean = 0.0f;
	pResultFreq->measure3.stdDev = 0.0f;
	pResultFreq->measure3.meanUnit = KILO;
	pResultFreq->measure3.stdDevUnit = MICRO;

	pResultFreq->measure4.mean = 0.0f;
	pResultFreq->measure4.stdDev = 0.0f;
	pResultFreq->measure4.meanUnit = KILO;
	pResultFreq->measure4.stdDevUnit = MICRO;

	pResultFreq->measure5.mean = 0.0f;
	pResultFreq->measure5.stdDev = 0.0f;
	pResultFreq->measure5.meanUnit = KILO;
	pResultFreq->measure5.stdDevUnit = MICRO;

	pResultFreq->measure6.mean = 0.0f;
	pResultFreq->measure6.stdDev = 0.0f;
	pResultFreq->measure6.meanUnit = KILO;
	pResultFreq->measure6.stdDevUnit = MICRO;

	pResultFreq->measure7.mean = 0.0f;
	pResultFreq->measure7.stdDev = 0.0f;
	pResultFreq->measure7.meanUnit = KILO;
	pResultFreq->measure7.stdDevUnit = MICRO;

	pResultFreq->measure8.mean = 0.0f;
	pResultFreq->measure8.stdDev = 0.0f;
	pResultFreq->measure8.meanUnit = KILO;
	pResultFreq->measure8.stdDevUnit = MICRO;
}

void SingleFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq)
{
	if (pFrequencyMode->Channel1.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel1, &pResultFreq->measure1);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel1, &pResultFreq->measure1);
	}
	if (pFrequencyMode->Channel2.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel2, &pResultFreq->measure2);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel2, &pResultFreq->measure2);
	}
	if (pFrequencyMode->Channel3.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel3, &pResultFreq->measure3);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel3, &pResultFreq->measure3);
	}
	if (pFrequencyMode->Channel4.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel4, &pResultFreq->measure4);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel4, &pResultFreq->measure4);
	}
	if (pFrequencyMode->Channel5.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel5, &pResultFreq->measure5);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel5, &pResultFreq->measure5);
	}
	if (pFrequencyMode->Channel6.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel6, &pResultFreq->measure6);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel6, &pResultFreq->measure6);
	}
	if (pFrequencyMode->Channel7.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel7, &pResultFreq->measure7);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel7, &pResultFreq->measure7);
	}
	if (pFrequencyMode->Channel8.channelState == true)
	{
		setCalculatedParamSingleFreq(&pFrequencyMode->Channel8, &pResultFreq->measure8);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel8, &pResultFreq->measure8);
	}

	pFrequencyMode->FreqSession.stampsNumber = 1;
}

void ContinuousFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq)
{

}

void StampsFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq)
{

}

// pozostale funkcje

void calculateRange(uint8_t numberCh, int *min, int *max)
{
	switch (numberCh)
	{
	case 1:
        *min = (rand() % (3 + 1 - 1)) + 1;
        *max = (rand() % (7 + 1 - 4)) + 4;
		break;
	case 2:
        *min = (rand() % (10 + 1 - 4)) + 4;
        *max = (rand() % (14 + 1 - 11)) + 11;
		break;
	case 3:
        *min = (rand() % (45 + 1 - 43)) + 43;
        *max = (rand() % (53 + 1 - 50)) + 50;
		break;
	case 4:
        *min = (rand() % (25 + 1 - 23)) + 23;
        *max = (rand() % (33 + 1 - 30)) + 30;
		break;
	case 5:
        *min = (rand() % (47 + 1 - 43)) + 43;
        *max = (rand() % (51 + 1 - 49)) + 49;
		break;
	case 6:
        *min = (rand() % (21 + 1 - 17)) + 17;
        *max = (rand() % (28 + 1 - 24)) + 24;
		break;
	case 7:
        *min = (rand() % (40 + 1 - 30)) + 30;
        *max = (rand() % (51 + 1 - 35)) + 45;
		break;
	case 8:
        *min = (rand() % (3 + 1 - 1)) + 1;
        *max = (rand() % (9 + 1 - 5)) + 5;
		break;
	default:
        *min = 0;
        *max = 0;
		break;
	}
}


Unit_t setUnitMeanFreq(uint8_t numberCh)
{
	Unit_t result;

	switch (numberCh)
	{
	case 1:
		result = MEGA;
		break;
	case 2:
		result = MEGA;
		break;
	case 3:
		result = KILO;
		break;
	case 4:
		result = KILO;
		break;
	case 5:
		result = MEGA;
		break;
	case 6:
		result = KILO;
		break;
	case 7:
		result = KILO;
		break;
	case 8:
		result = MEGA;
		break;
	default:
		result = KILO;
		break;
	}
	return result;
}

void setCalculatedParamSingleFreq(FreqChannel_t *pFreqChannel, MeasFreq_t *pMeasFreq)
{
	int min = 0, max = 0;
	calculateRange(pFreqChannel->numberChanel, &min, &max);
	pMeasFreq->mean = calculateSingleMeas(min, max);
	pMeasFreq->meanUnit = setUnitMeanFreq(pFreqChannel->numberChanel);
}

void resetParamSingleFreq(FreqChannel_t *pFreqChannel, MeasFreq_t *pMeasFreq)
{
	pFreqChannel->numberChanel = 0;
	pMeasFreq->mean = 0.0f;
	pMeasFreq->stdDev = 0.0f;
	pMeasFreq->meanUnit = KILO;
	pMeasFreq->stdDevUnit = MICRO;
}

