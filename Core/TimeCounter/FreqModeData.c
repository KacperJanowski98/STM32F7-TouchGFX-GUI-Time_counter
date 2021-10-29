/*
 * FreqModeData.c
 *
 *  Created on: 15 paź 2021
 *      Author: Kacper
 */

#include "FreqModeData.h"

extern osSemaphoreId_t myBinarySemUpdateFreqDispHandle;

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

void ResultFreqParameterConstInit(ResultConstCalcFreq_t *pResultConstCalcFreq)
{
	pResultConstCalcFreq->parameters1.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters1.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters1.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters1.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters1.measureBuffer[0]));

	pResultConstCalcFreq->parameters2.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters2.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters2.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters2.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters2.measureBuffer[0]));

	pResultConstCalcFreq->parameters3.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters3.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters3.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters3.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters3.measureBuffer[0]));

	pResultConstCalcFreq->parameters4.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters4.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters4.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters4.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters4.measureBuffer[0]));

	pResultConstCalcFreq->parameters5.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters5.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters5.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters5.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters5.measureBuffer[0]));

	pResultConstCalcFreq->parameters6.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters6.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters6.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters6.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters6.measureBuffer[0]));

	pResultConstCalcFreq->parameters7.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters7.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters7.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters7.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters7.measureBuffer[0]));

	pResultConstCalcFreq->parameters8.calculateMean = 0.0f;
	pResultConstCalcFreq->parameters8.calculateStdDev = 0.0f;
	pResultConstCalcFreq->parameters8.sizeBuffer = 0;
	memset(pResultConstCalcFreq->parameters8.measureBuffer, 0, 2000 * sizeof(pResultConstCalcFreq->parameters8.measureBuffer[0]));

	pResultConstCalcFreq->iteration = 0;
}

void ResultFreqStampsInit(ResultStampsCalcFreq_t *pResultStampsCalcFreq)
{
	pResultStampsCalcFreq->parameters1.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters1.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters1.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters1.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters1.measureBuffer[0]));

	pResultStampsCalcFreq->parameters2.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters2.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters2.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters2.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters2.measureBuffer[0]));

	pResultStampsCalcFreq->parameters3.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters3.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters3.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters3.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters3.measureBuffer[0]));

	pResultStampsCalcFreq->parameters4.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters4.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters4.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters4.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters4.measureBuffer[0]));

	pResultStampsCalcFreq->parameters5.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters5.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters5.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters5.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters5.measureBuffer[0]));

	pResultStampsCalcFreq->parameters6.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters6.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters6.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters6.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters6.measureBuffer[0]));

	pResultStampsCalcFreq->parameters7.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters7.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters7.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters7.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters7.measureBuffer[0]));

	pResultStampsCalcFreq->parameters8.calculateMean = 0.0f;
	pResultStampsCalcFreq->parameters8.calculateStdDev = 0.0f;
	pResultStampsCalcFreq->parameters8.sizeBuffer = 0;
	memset(pResultStampsCalcFreq->parameters8.measureBuffer, 0, 1000 * sizeof(pResultStampsCalcFreq->parameters8.measureBuffer[0]));
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

void ContinuousFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq, ResultConstCalcFreq_t *pResultCalc)
{
	if (pFrequencyMode->Channel1.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel1, &pResultFreq->measure1, &pResultCalc->parameters1);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel1, &pResultFreq->measure1);
	}
	if (pFrequencyMode->Channel2.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel2, &pResultFreq->measure2, &pResultCalc->parameters2);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel2, &pResultFreq->measure2);
	}
	if (pFrequencyMode->Channel3.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel3, &pResultFreq->measure3, &pResultCalc->parameters3);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel3, &pResultFreq->measure3);
	}
	if (pFrequencyMode->Channel4.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel4, &pResultFreq->measure4, &pResultCalc->parameters4);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel4, &pResultFreq->measure4);
	}
	if (pFrequencyMode->Channel5.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel5, &pResultFreq->measure5, &pResultCalc->parameters5);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel5, &pResultFreq->measure5);
	}
	if (pFrequencyMode->Channel6.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel6, &pResultFreq->measure6, &pResultCalc->parameters6);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel6, &pResultFreq->measure6);
	}
	if (pFrequencyMode->Channel7.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel7, &pResultFreq->measure7, &pResultCalc->parameters7);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel7, &pResultFreq->measure7);
	}
	if (pFrequencyMode->Channel8.channelState == true)
	{
		setCalculatedParamConstFreq(&pFrequencyMode->Channel8, &pResultFreq->measure8, &pResultCalc->parameters8);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel8, &pResultFreq->measure8);
	}
	pResultCalc->iteration++;
	pFrequencyMode->FreqSession.stampsNumber = pResultCalc->iteration;

	osSemaphoreRelease(myBinarySemUpdateFreqDispHandle);
}

void StampsFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq, ResultStampsCalcFreq_t *pResultCalc)
{
	if (pFrequencyMode->Channel1.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel1, &pResultFreq->measure1, &pFrequencyMode->FreqSession, &pResultCalc->parameters1);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel1, &pResultFreq->measure1);
	}
	if (pFrequencyMode->Channel2.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel2, &pResultFreq->measure2, &pFrequencyMode->FreqSession, &pResultCalc->parameters2);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel2, &pResultFreq->measure2);
	}
	if (pFrequencyMode->Channel3.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel3, &pResultFreq->measure3, &pFrequencyMode->FreqSession, &pResultCalc->parameters3);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel3, &pResultFreq->measure3);
	}
	if (pFrequencyMode->Channel4.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel4, &pResultFreq->measure4, &pFrequencyMode->FreqSession, &pResultCalc->parameters4);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel4, &pResultFreq->measure4);
	}
	if (pFrequencyMode->Channel5.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel5, &pResultFreq->measure5, &pFrequencyMode->FreqSession, &pResultCalc->parameters5);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel5, &pResultFreq->measure5);
	}
	if (pFrequencyMode->Channel6.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel6, &pResultFreq->measure6, &pFrequencyMode->FreqSession, &pResultCalc->parameters6);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel6, &pResultFreq->measure6);
	}
	if (pFrequencyMode->Channel7.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel7, &pResultFreq->measure7, &pFrequencyMode->FreqSession, &pResultCalc->parameters7);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel7, &pResultFreq->measure7);
	}
	if (pFrequencyMode->Channel8.channelState == true && pFrequencyMode->FreqSession.stampsNumber != 0)
	{
		setCalculatedParamStampsFreq(&pFrequencyMode->Channel8, &pResultFreq->measure8, &pFrequencyMode->FreqSession, &pResultCalc->parameters8);
	}
	else
	{
		resetParamSingleFreq(&pFrequencyMode->Channel8, &pResultFreq->measure8);
	}

	osSemaphoreRelease(myBinarySemUpdateFreqDispHandle);
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

void setCalculatedParamConstFreq(FreqChannel_t *pFreqChannel, MeasFreq_t *pMeasFreq, CalcConstParam_t *pCalcParam)
{
	int min = 0, max = 0;
	calculateRange(pFreqChannel->numberChanel, &min, &max);
	if (min != 0 && max != 0)
	{
		pCalcParam->measureBuffer[pCalcParam->sizeBuffer] = calculateSingleMeas(min, max);
		calculateMeanStdDevConst(pCalcParam);
		pMeasFreq->mean = pCalcParam->calculateMean;
		pMeasFreq->stdDev = pCalcParam->calculateStdDev;
	}
	else
	{
		pMeasFreq->mean = 0.0f;
		pMeasFreq->stdDev = 0.0f;
	}
	pMeasFreq->meanUnit = setUnitMeanFreq(pFreqChannel->numberChanel);
	pMeasFreq->stdDevUnit = MILLI;
}

void setCalculatedParamStampsFreq(FreqChannel_t *pFreqChannel, MeasFreq_t *pMeasFreq, SessionSetup_t *pSessionSetup, CalcStampParam_t *pCalcParam)
{
	int min = 0, max = 0;
	calculateRange(pFreqChannel->numberChanel, &min, &max);
	if (min != 0 && max != 0)
	{
		for (int i = 0; i < pSessionSetup->stampsNumber; i++)
		{
			pCalcParam->measureBuffer[i] = calculateSingleMeas(min, max);
		}
		pCalcParam->sizeBuffer = pSessionSetup->stampsNumber;
		calculateMeanStdDevStamps(pCalcParam);
		pMeasFreq->mean = pCalcParam->calculateMean;
		pMeasFreq->stdDev = pCalcParam->calculateStdDev;
	}
	else
	{
		pMeasFreq->mean = 0.0f;
		pMeasFreq->stdDev = 0.0f;
	}
	pMeasFreq->meanUnit = setUnitMeanFreq(pFreqChannel->numberChanel);
	pMeasFreq->stdDevUnit = MILLI;
}

void resetParamSingleFreq(FreqChannel_t *pFreqChannel, MeasFreq_t *pMeasFreq)
{
//	pFreqChannel->numberChanel = 0;
	pMeasFreq->mean = 0.0f;
	pMeasFreq->stdDev = 0.0f;
	pMeasFreq->meanUnit = KILO;
	pMeasFreq->stdDevUnit = MICRO;
}

