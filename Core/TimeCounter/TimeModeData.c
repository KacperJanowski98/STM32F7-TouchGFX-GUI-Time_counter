/*
 * TimeModeData.c
 *
 *  Created on: 28 wrz 2021
 *      Author: Kacper
 */

#include "TimeModeData.h"

extern osSemaphoreId_t myBinarySemUpdateTimeDispHandle;

void TimeModeInit(TimeMode_t *pTimeMode)
{
    pTimeMode->Channel1.channelState = false;
    pTimeMode->Channel1.slope = UP;
    pTimeMode->Channel1.threshold = 0;

    pTimeMode->Channel2.channelState = false;
    pTimeMode->Channel2.slope = UP;
    pTimeMode->Channel2.threshold = 0;

    pTimeMode->Channel3.channelState = false;
    pTimeMode->Channel3.slope = UP;
    pTimeMode->Channel3.threshold = 0;

    pTimeMode->Channel4.channelState = false;
    pTimeMode->Channel4.slope = UP;
    pTimeMode->Channel4.threshold = 0;

    pTimeMode->Channel5.channelState = false;
    pTimeMode->Channel5.slope = UP;
    pTimeMode->Channel5.threshold = 0;

    pTimeMode->Channel6.channelState = false;
    pTimeMode->Channel6.slope = UP;
    pTimeMode->Channel6.threshold = 0;

    pTimeMode->Channel7.channelState = false;
    pTimeMode->Channel7.slope = UP;
    pTimeMode->Channel7.threshold = 0;

    pTimeMode->Channel8.channelState = false;
    pTimeMode->Channel8.slope = UP;
    pTimeMode->Channel8.threshold = 0;

    pTimeMode->TiSetup1.tiState = false;
    pTimeMode->TiSetup1.startIn = 0;
    pTimeMode->TiSetup1.stopIn = 0;

    pTimeMode->TiSetup2.tiState = false;
    pTimeMode->TiSetup2.startIn = 0;
    pTimeMode->TiSetup2.stopIn = 0;

    pTimeMode->TiSetup3.tiState = false;
    pTimeMode->TiSetup3.startIn = 0;
    pTimeMode->TiSetup3.stopIn = 0;

    pTimeMode->TiSetup4.tiState = false;
    pTimeMode->TiSetup4.startIn = 0;
    pTimeMode->TiSetup4.stopIn = 0;

    pTimeMode->TiSetup5.tiState = false;
    pTimeMode->TiSetup5.startIn = 0;
    pTimeMode->TiSetup5.stopIn = 0;

    pTimeMode->TiSetup6.tiState = false;
    pTimeMode->TiSetup6.startIn = 0;
    pTimeMode->TiSetup6.stopIn = 0;

    pTimeMode->TiSetup7.tiState = false;
    pTimeMode->TiSetup7.startIn = 0;
    pTimeMode->TiSetup7.stopIn = 0;

    pTimeMode->TimeSession.maxRange = false;
    pTimeMode->TimeSession.clock = INTERNAL_QUARTZ;
    pTimeMode->TimeSession.repeat = 0;
    pTimeMode->TimeSession.stampsNumber = 0;
    pTimeMode->TimeSession.tiRange = 0;
}

void ResultTimeParameterConstInit(ResultConstCalc_t *pResultCalc)
{
	pResultCalc->parameters1.calculateMean = 0.0f;
	pResultCalc->parameters1.calculateStdDev = 0.0f;
	pResultCalc->parameters1.sizeBuffer = 0;
	memset(pResultCalc->parameters1.measureBuffer, 0, 2000 * sizeof(pResultCalc->parameters1.measureBuffer[0]));

	pResultCalc->parameters2.calculateMean = 0.0f;
	pResultCalc->parameters2.calculateStdDev = 0.0f;
	pResultCalc->parameters2.sizeBuffer = 0;
	memset(pResultCalc->parameters2.measureBuffer, 0, 2000 * sizeof(pResultCalc->parameters2.measureBuffer[0]));

	pResultCalc->parameters3.calculateMean = 0.0f;
	pResultCalc->parameters3.calculateStdDev = 0.0f;
	pResultCalc->parameters3.sizeBuffer = 0;
	memset(pResultCalc->parameters3.measureBuffer, 0, 2000 * sizeof(pResultCalc->parameters3.measureBuffer[0]));

	pResultCalc->parameters4.calculateMean = 0.0f;
	pResultCalc->parameters4.calculateStdDev = 0.0f;
	pResultCalc->parameters4.sizeBuffer = 0;
	memset(pResultCalc->parameters4.measureBuffer, 0, 2000 * sizeof(pResultCalc->parameters4.measureBuffer[0]));

	pResultCalc->parameters5.calculateMean = 0.0f;
	pResultCalc->parameters5.calculateStdDev = 0.0f;
	pResultCalc->parameters5.sizeBuffer = 0;
	memset(pResultCalc->parameters5.measureBuffer, 0, 2000 * sizeof(pResultCalc->parameters5.measureBuffer[0]));

	pResultCalc->parameters6.calculateMean = 0.0f;
	pResultCalc->parameters6.calculateStdDev = 0.0f;
	pResultCalc->parameters6.sizeBuffer = 0;
	memset(pResultCalc->parameters6.measureBuffer, 0, 2000 * sizeof(pResultCalc->parameters6.measureBuffer[0]));

	pResultCalc->parameters7.calculateMean = 0.0f;
	pResultCalc->parameters7.calculateStdDev = 0.0f;
	pResultCalc->parameters7.sizeBuffer = 0;
	memset(pResultCalc->parameters7.measureBuffer, 0, 2000 * sizeof(pResultCalc->parameters7.measureBuffer[0]));

	pResultCalc->iteration = 0;
}

void ResultTimeParameterStampsInit(ResultStampsCalc_t *pResultCalc)
{
	pResultCalc->parameters1.calculateMean = 0.0f;
	pResultCalc->parameters1.calculateStdDev = 0.0;
	pResultCalc->parameters1.sizeBuffer = 0;
	memset(pResultCalc->parameters1.measureBuffer, 0, 285 * sizeof(pResultCalc->parameters1.measureBuffer[0]));

	pResultCalc->parameters2.calculateMean = 0.0f;
	pResultCalc->parameters2.calculateStdDev = 0.0;
	pResultCalc->parameters2.sizeBuffer = 0;
	memset(pResultCalc->parameters2.measureBuffer, 0, 285 * sizeof(pResultCalc->parameters2.measureBuffer[0]));

	pResultCalc->parameters3.calculateMean = 0.0f;
	pResultCalc->parameters3.calculateStdDev = 0.0;
	pResultCalc->parameters3.sizeBuffer = 0;
	memset(pResultCalc->parameters3.measureBuffer, 0, 285 * sizeof(pResultCalc->parameters3.measureBuffer[0]));

	pResultCalc->parameters4.calculateMean = 0.0f;
	pResultCalc->parameters4.calculateStdDev = 0.0;
	pResultCalc->parameters4.sizeBuffer = 0;
	memset(pResultCalc->parameters4.measureBuffer, 0, 285 * sizeof(pResultCalc->parameters4.measureBuffer[0]));

	pResultCalc->parameters5.calculateMean = 0.0f;
	pResultCalc->parameters5.calculateStdDev = 0.0;
	pResultCalc->parameters5.sizeBuffer = 0;
	memset(pResultCalc->parameters5.measureBuffer, 0, 285 * sizeof(pResultCalc->parameters5.measureBuffer[0]));

	pResultCalc->parameters6.calculateMean = 0.0f;
	pResultCalc->parameters6.calculateStdDev = 0.0;
	pResultCalc->parameters6.sizeBuffer = 0;
	memset(pResultCalc->parameters6.measureBuffer, 0, 285 * sizeof(pResultCalc->parameters6.measureBuffer[0]));

	pResultCalc->parameters7.calculateMean = 0.0f;
	pResultCalc->parameters7.calculateStdDev = 0.0;
	pResultCalc->parameters7.sizeBuffer = 0;
	memset(pResultCalc->parameters7.measureBuffer, 0, 285 * sizeof(pResultCalc->parameters7.measureBuffer[0]));
}

void ResultTimeInit(ResultTime_t *pResultTime)
{
    pResultTime->measure1.mean = 0.0f;
    pResultTime->measure1.stdDev = 0.0f;
    pResultTime->measure1.meanUnit = NANO;
    pResultTime->measure1.stdDevUnit = PICO;

    pResultTime->measure2.mean = 0.0f;
    pResultTime->measure2.stdDev = 0.0f;
    pResultTime->measure2.meanUnit = NANO;
    pResultTime->measure2.stdDevUnit = PICO;

    pResultTime->measure3.mean = 0.0f;
    pResultTime->measure3.stdDev = 0.0f;
    pResultTime->measure3.meanUnit = NANO;
    pResultTime->measure3.stdDevUnit = PICO;

    pResultTime->measure4.mean = 0.0f;
    pResultTime->measure4.stdDev = 0.0f;
    pResultTime->measure4.meanUnit = NANO;
    pResultTime->measure4.stdDevUnit = PICO;

    pResultTime->measure5.mean = 0.0f;
    pResultTime->measure5.stdDev = 0.0f;
    pResultTime->measure5.meanUnit = NANO;
    pResultTime->measure5.stdDevUnit = PICO;

    pResultTime->measure6.mean = 0.0f;
    pResultTime->measure6.stdDev = 0.0f;
    pResultTime->measure6.meanUnit = NANO;
    pResultTime->measure6.stdDevUnit = PICO;

    pResultTime->measure7.mean = 0.0f;
    pResultTime->measure7.stdDev = 0.0f;
    pResultTime->measure7.meanUnit = NANO;
    pResultTime->measure7.stdDevUnit = PICO;
}

void SingleTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime)
{
    if (pTimeMode->TiSetup1.tiState == true)
    {
        setCalculatedParamSingleTime(&pTimeMode->TiSetup1, &pResultTime->measure1);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup1, &pResultTime->measure1);
    }

    if (pTimeMode->TiSetup2.tiState == true)
    {
        setCalculatedParamSingleTime(&pTimeMode->TiSetup2, &pResultTime->measure2);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup2, &pResultTime->measure2);
    }

    if (pTimeMode->TiSetup3.tiState == true)
    {
        setCalculatedParamSingleTime(&pTimeMode->TiSetup3, &pResultTime->measure3);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup3, &pResultTime->measure3);
    }

    if (pTimeMode->TiSetup4.tiState == true)
    {
        setCalculatedParamSingleTime(&pTimeMode->TiSetup4, &pResultTime->measure4);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup4, &pResultTime->measure4);
    }

    if (pTimeMode->TiSetup5.tiState == true)
    {
        setCalculatedParamSingleTime(&pTimeMode->TiSetup5, &pResultTime->measure5);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup5, &pResultTime->measure5);
    }

    if (pTimeMode->TiSetup6.tiState == true)
    {
        setCalculatedParamSingleTime(&pTimeMode->TiSetup6, &pResultTime->measure6);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup6, &pResultTime->measure6);
    }

    if (pTimeMode->TiSetup7.tiState == true)
    {
        setCalculatedParamSingleTime(&pTimeMode->TiSetup7, &pResultTime->measure7);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup7, &pResultTime->measure7);
    }
    pTimeMode->TimeSession.stampsNumber = 1;
}

//:TODO dorobic obliczanie odchylenia standardowego.
void ContinuousTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime, ResultConstCalc_t *pResultCalc)
{
    if (pTimeMode->TiSetup1.tiState == true)
    {
    	setCalculatedParamConstTime(&pTimeMode->TiSetup1, &pResultTime->measure1, &pResultCalc->parameters1);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup1, &pResultTime->measure1);
    }

    if (pTimeMode->TiSetup2.tiState == true)
    {
    	setCalculatedParamConstTime(&pTimeMode->TiSetup2, &pResultTime->measure2, &pResultCalc->parameters2);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup2, &pResultTime->measure2);
    }

    if (pTimeMode->TiSetup3.tiState == true)
    {
    	setCalculatedParamConstTime(&pTimeMode->TiSetup3, &pResultTime->measure3, &pResultCalc->parameters3);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup3, &pResultTime->measure3);
    }

    if (pTimeMode->TiSetup4.tiState == true)
    {
    	setCalculatedParamConstTime(&pTimeMode->TiSetup4, &pResultTime->measure4, &pResultCalc->parameters4);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup4, &pResultTime->measure4);
    }

    if (pTimeMode->TiSetup5.tiState == true)
    {
    	setCalculatedParamConstTime(&pTimeMode->TiSetup5, &pResultTime->measure5, &pResultCalc->parameters5);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup5, &pResultTime->measure5);
    }

    if (pTimeMode->TiSetup6.tiState == true)
    {
    	setCalculatedParamConstTime(&pTimeMode->TiSetup6, &pResultTime->measure6, &pResultCalc->parameters6);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup6, &pResultTime->measure6);
    }

    if (pTimeMode->TiSetup7.tiState == true)
    {
    	setCalculatedParamConstTime(&pTimeMode->TiSetup7, &pResultTime->measure7, &pResultCalc->parameters7);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup7, &pResultTime->measure7);
    }
    pResultCalc->iteration++;
    pTimeMode->TimeSession.stampsNumber = pResultCalc->iteration;

    osSemaphoreRelease(myBinarySemUpdateTimeDispHandle);
}

void StampsTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime, ResultStampsCalc_t *pResultCalc)
{
    if (pTimeMode->TiSetup1.tiState == true && pTimeMode->TimeSession.stampsNumber != 0)
    {
    	setCalculatedParamStampsTime(&pTimeMode->TiSetup1, &pResultTime->measure1, &pTimeMode->TimeSession, &pResultCalc->parameters1);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup1, &pResultTime->measure1);
    }

    if (pTimeMode->TiSetup2.tiState == true && pTimeMode->TimeSession.stampsNumber != 0)
    {
    	setCalculatedParamStampsTime(&pTimeMode->TiSetup2, &pResultTime->measure2, &pTimeMode->TimeSession, &pResultCalc->parameters2);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup2, &pResultTime->measure2);
    }

    if (pTimeMode->TiSetup3.tiState == true && pTimeMode->TimeSession.stampsNumber != 0)
    {
    	setCalculatedParamStampsTime(&pTimeMode->TiSetup3, &pResultTime->measure3, &pTimeMode->TimeSession, &pResultCalc->parameters3);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup3, &pResultTime->measure3);
    }

    if (pTimeMode->TiSetup4.tiState == true && pTimeMode->TimeSession.stampsNumber != 0)
    {
    	setCalculatedParamStampsTime(&pTimeMode->TiSetup4, &pResultTime->measure4, &pTimeMode->TimeSession, &pResultCalc->parameters4);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup4, &pResultTime->measure4);
    }

    if (pTimeMode->TiSetup5.tiState == true && pTimeMode->TimeSession.stampsNumber != 0)
    {
    	setCalculatedParamStampsTime(&pTimeMode->TiSetup5, &pResultTime->measure5, &pTimeMode->TimeSession, &pResultCalc->parameters5);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup5, &pResultTime->measure5);
    }

    if (pTimeMode->TiSetup6.tiState == true && pTimeMode->TimeSession.stampsNumber != 0)
    {
    	setCalculatedParamStampsTime(&pTimeMode->TiSetup6, &pResultTime->measure6, &pTimeMode->TimeSession, &pResultCalc->parameters6);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup6, &pResultTime->measure6);
    }

    if (pTimeMode->TiSetup7.tiState == true && pTimeMode->TimeSession.stampsNumber != 0)
    {
    	setCalculatedParamStampsTime(&pTimeMode->TiSetup7, &pResultTime->measure7, &pTimeMode->TimeSession, &pResultCalc->parameters7);
    }
    else
    {
    	resetParamSingleTime(&pTimeMode->TiSetup7, &pResultTime->measure7);
    }

    osSemaphoreRelease(myBinarySemUpdateTimeDispHandle);
}

void calculateMinMax(uint8_t start, uint8_t stop, int *min, int *max)
{
    int8_t distance = stop - start;
    if (stop != 0 && start != 0)
    {
        switch (abs(distance))
        {
        case 1:
            *min = (rand() % (45 + 1 - 44)) + 44;
            *max = (rand() % (46 + 1 - 45)) + 45;
            break;
        case 2:
            *min = (rand() % (4 + 1 - 3)) + 3;
            *max = (rand() % (6 + 1 - 5)) + 5;
            break;
        case 3:
            *min = (rand() % (20 + 1 - 19)) + 19;
            *max = (rand() % (21 + 1 - 20)) + 20;
            break;
        case 4:
            *min = (rand() % (99 + 1 - 98)) + 98;
            *max = (rand() % (101 + 1 - 99)) + 99;
            break;
        case 5:
            *min = (rand() % (4 + 1 - 3)) + 3;
            *max = (rand() % (6 + 1 - 5)) + 5;
            break;
        case 6:
            *min = (rand() % (9 + 1 - 8)) + 8;
            *max = (rand() % (11 + 1 - 10)) + 10;
            break;
        case 7:
            *min = (rand() % (100 + 1 - 99)) + 99;
            *max = (rand() % (102 + 1 - 101)) + 101;
            break;
        default:
        	*min = 0;
        	*max = 0;
        	break;
        }
    }
    else
    {
    	*min = 0;
    	*max = 0;
    }
}

Unit_t setUnitMeanTime(uint8_t start, uint8_t stop)
{
    int8_t distance = stop - start;
    Unit_t result;

    if (stop != 0 && start != 0)
    {
        switch (distance)
        {
        case 1:
            result = NANO;
            break;
        case 2:
            result = MICRO;
            break;
        case 3:
            result = MICRO;
            break;
        case 4:
            result = MICRO;
            break;
        case 5:
            result = MILLI;
            break;
        case 6:
            result = MILLI;
            break;
        case 7:
            result = MILLI;
            break;
        default:
        	result = NANO;
        }
    }
    else
    {
    	result = NANO;
    }

    return result;
}

void setCalculatedParamSingleTime(TimeTi_t *Ti, MeasValues_t *meas)
{
    uint8_t start = Ti->startIn;
    uint8_t stop = Ti->stopIn;
    int min = 0, max = 0;
    calculateMinMax(start, stop, &min, &max);
    meas->mean = calculateSingleMeas(min, max);
    meas->meanUnit = setUnitMeanTime(start, stop);
}

void setCalculatedParamConstTime(TimeTi_t *Ti, MeasValues_t *meas, CalcConstParam_t *pCalcParam)
{
    uint8_t start = Ti->startIn;
    uint8_t stop = Ti->stopIn;
    int min = 0, max = 0;
    calculateMinMax(start, stop, &min, &max);
    if (min != 0 && max != 0)
    {
        pCalcParam->measureBuffer[pCalcParam->sizeBuffer] = calculateSingleMeas(min, max);
        calculateMeanStdDevConst(pCalcParam);
        meas->mean = pCalcParam->calculateMean;
        meas->stdDev = pCalcParam->calculateStdDev;
    }
    else
    {
        meas->mean = 0.0f;
        meas->stdDev = 0.0f;
    }
    meas->meanUnit = setUnitMeanTime(start, stop);
    meas->stdDevUnit = PICO;
}

void setCalculatedParamStampsTime(TimeTi_t *Ti, MeasValues_t *meas, SessionSetup_t *pSessionSetup, CalcStampParam_t *pCalcParam)
{
    uint8_t start = Ti->startIn;
    uint8_t stop = Ti->stopIn;
    int min = 0, max = 0;
    calculateMinMax(start, stop, &min, &max);
    if (min != 0 && max != 0)
    {
    	for(int i = 0; i < pSessionSetup->stampsNumber; i++)
    	{
    		pCalcParam->measureBuffer[i] = calculateSingleMeas(min, max);
    	}
    	pCalcParam->sizeBuffer = pSessionSetup->stampsNumber;
    	calculateMeanStdDevStamps(pCalcParam);
    	meas->mean = pCalcParam->calculateMean;
    	meas->stdDev = pCalcParam->calculateStdDev;
    }
    else
    {
        meas->mean = 0.0f;
        meas->stdDev = 0.0f;
    }
    meas->meanUnit = setUnitMeanTime(start, stop);
    meas->stdDevUnit = PICO;
}

void resetParamSingleTime(TimeTi_t *Ti, MeasValues_t *meas)
{
	Ti->startIn = 0;
	Ti->stopIn = 0;
	meas->mean = 0.0f;
	meas->stdDev = 0.0f;
	meas->meanUnit = NANO;
	meas->stdDevUnit = PICO;
}
