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
void ContinuousTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime)
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
    //:TODO Wpisywanie numeru iteracji
    pTimeMode->TimeSession.stampsNumber = 1;

    osSemaphoreRelease(myBinarySemUpdateTimeDispHandle);
}

void StampsTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime)
{
    if (pTimeMode->TiSetup1.tiState == true)
    {

    }

    if (pTimeMode->TiSetup2.tiState == true)
    {

    }

    if (pTimeMode->TiSetup3.tiState == true)
    {

    }

    if (pTimeMode->TiSetup4.tiState == true)
    {

    }

    if (pTimeMode->TiSetup5.tiState == true)
    {

    }

    if (pTimeMode->TiSetup6.tiState == true)
    {

    }

    if (pTimeMode->TiSetup7.tiState == true)
    {

    }
}

void RepeatTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime)
{
    if (pTimeMode->TiSetup1.tiState == true)
    {

    }

    if (pTimeMode->TiSetup2.tiState == true)
    {

    }

    if (pTimeMode->TiSetup3.tiState == true)
    {

    }

    if (pTimeMode->TiSetup4.tiState == true)
    {

    }

    if (pTimeMode->TiSetup5.tiState == true)
    {

    }

    if (pTimeMode->TiSetup6.tiState == true)
    {

    }

    if (pTimeMode->TiSetup7.tiState == true)
    {

    }
}

float calculateSingleMeas(int min, int max)
{
    if (min == 0 && max == 0)
    {
    	return 0.0f;
    }
    else
    {
    	return ((float)rand()/(float)RAND_MAX) * ((float)(max - min) + (float)min);
    }
}

void calculateMinMax(uint8_t start, uint8_t stop, int *min, int *max)
{
    int8_t distance = stop - start;
    switch (distance)
    {
    case 1:
        *min = (rand() % (45 + 1 - 43)) + 43;
        *max = (rand() % (53 + 1 - 50)) + 50;
        break;
    case 2:
        *min = (rand() % (4 + 1 - 3)) + 3;
        *max = (rand() % (8 + 1 - 6)) + 6;
        break;
    case 3:
        *min = (rand() % (20 + 1 - 15)) + 15;
        *max = (rand() % (26 + 1 - 22)) + 22;
        break;
    case 4:
        *min = (rand() % (96 + 1 - 93)) + 93;
        *max = (rand() % (103 + 1 - 100)) + 100;
        break;
    case 5:
        *min = (rand() % (2 + 1 - 1)) + 1;
        *max = (rand() % (6 + 1 - 4)) + 4;
        break;
    case 6:
        *min = (rand() % (9 + 1 - 7)) + 7;
        *max = (rand() % (13 + 1 - 11)) + 11;
        break;
    case 7:
        *min = (rand() % (98 + 1 - 95)) + 95;
        *max = (rand() % (103 + 1 - 100)) + 100;
        break;
    default:
    	*min = 0;
    	*max = 0;
    	break;
    }
}

Unit_t setUnitMeanTime(uint8_t start, uint8_t stop)
{
    int8_t distance = stop - start;
    Unit_t result;

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
    return result;
}

void setCalculatedParamSingleTime(TimeTi_t *Ti, MeasTime_t *meas)
{
    uint8_t start = Ti->startIn;
    uint8_t stop = Ti->stopIn;
    int min = 0, max = 0;
    calculateMinMax(start, stop, &min, &max);
    meas->mean = calculateSingleMeas(min, max);
    meas->meanUnit = setUnitMeanTime(start, stop);
}

void resetParamSingleTime(TimeTi_t *Ti, MeasTime_t *meas)
{
	Ti->startIn = 0;
	Ti->stopIn = 0;
	meas->mean = 0.0f;
	meas->stdDev = 0.0f;
	meas->meanUnit = NANO;
	meas->stdDevUnit = PICO;
}
