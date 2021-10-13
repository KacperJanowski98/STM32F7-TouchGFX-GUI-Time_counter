/*
 * TimeModeData.c
 *
 *  Created on: 28 wrz 2021
 *      Author: kacpe
 */

#include "TimeModeData.h"

void TimeChannelInit(TimeChannel_t *pTimeChannel)
{
    pTimeChannel->channelState = false;
    pTimeChannel->slope = UP;
    pTimeChannel->threshold = 0;
}

void TimeTiInit(TimeTi_t *pTimeTiParam)
{
    pTimeTiParam->tiState = false;
    pTimeTiParam->startIn = 0;
    pTimeTiParam->stopIn = 0;
}

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
    pTimeMode->TiSetup1.stopIn = 0;
    pTimeMode->TiSetup1.stopIn = 0;

    pTimeMode->TiSetup2.tiState = false;
    pTimeMode->TiSetup2.stopIn = 0;
    pTimeMode->TiSetup2.stopIn = 0;

    pTimeMode->TiSetup3.tiState = false;
    pTimeMode->TiSetup3.stopIn = 0;
    pTimeMode->TiSetup3.stopIn = 0;

    pTimeMode->TiSetup4.tiState = false;
    pTimeMode->TiSetup4.stopIn = 0;
    pTimeMode->TiSetup4.stopIn = 0;

    pTimeMode->TiSetup5.tiState = false;
    pTimeMode->TiSetup5.stopIn = 0;
    pTimeMode->TiSetup5.stopIn = 0;

    pTimeMode->TiSetup6.tiState = false;
    pTimeMode->TiSetup6.stopIn = 0;
    pTimeMode->TiSetup6.stopIn = 0;

    pTimeMode->TiSetup7.tiState = false;
    pTimeMode->TiSetup7.stopIn = 0;
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

    pResultTime->measure2.mean = 0.0f;
    pResultTime->measure2.stdDev = 0.0f;
    pResultTime->measure2.meanUnit = NANO;

    pResultTime->measure3.mean = 0.0f;
    pResultTime->measure3.stdDev = 0.0f;
    pResultTime->measure3.meanUnit = NANO;

    pResultTime->measure4.mean = 0.0f;
    pResultTime->measure4.stdDev = 0.0f;
    pResultTime->measure4.meanUnit = NANO;

    pResultTime->measure5.mean = 0.0f;
    pResultTime->measure5.stdDev = 0.0f;
    pResultTime->measure5.meanUnit = NANO;

    pResultTime->measure6.mean = 0.0f;
    pResultTime->measure6.stdDev = 0.0f;
    pResultTime->measure6.meanUnit = NANO;

    pResultTime->measure7.mean = 0.0f;
    pResultTime->measure7.stdDev = 0.0f;
    pResultTime->measure7.meanUnit = NANO;
}

void SingleTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime)
{
    int min = 0, max = 0;
    uint8_t start = 0, stop = 0;

    if (pTimeMode->TiSetup1.tiState == true)
    {
        start = pTimeMode->TiSetup1.startIn;
        stop = pTimeMode->TiSetup1.stopIn;
        calculateMinMax(start, stop, &min, &max);
        pResultTime->measure1.mean = calculateSingleMeas(min, max);
        pResultTime->measure1.meanUnit = setUnitMeanTime(start, stop);
    }

    if (pTimeMode->TiSetup2.tiState == true)
    {
        start = pTimeMode->TiSetup2.startIn;
        stop = pTimeMode->TiSetup2.stopIn;
        calculateMinMax(start, stop, &min, &max);
        pResultTime->measure2.mean = calculateSingleMeas(min, max);
        pResultTime->measure2.meanUnit = setUnitMeanTime(start, stop);
    }

    if (pTimeMode->TiSetup3.tiState == true)
    {
        start = pTimeMode->TiSetup3.startIn;
        stop = pTimeMode->TiSetup3.stopIn;
        calculateMinMax(start, stop, &min, &max);
        pResultTime->measure3.mean = calculateSingleMeas(min, max);
        pResultTime->measure3.meanUnit = setUnitMeanTime(start, stop);
    }

    if (pTimeMode->TiSetup4.tiState == true)
    {
        start = pTimeMode->TiSetup4.startIn;
        stop = pTimeMode->TiSetup4.stopIn;
        calculateMinMax(start, stop, &min, &max);
        pResultTime->measure4.mean = calculateSingleMeas(min, max);
        pResultTime->measure4.meanUnit = setUnitMeanTime(start, stop);
    }

    if (pTimeMode->TiSetup5.tiState == true)
    {
        start = pTimeMode->TiSetup5.startIn;
        stop = pTimeMode->TiSetup5.stopIn;
        calculateMinMax(start, stop, &min, &max);
        pResultTime->measure5.mean = calculateSingleMeas(min, max);
        pResultTime->measure5.meanUnit = setUnitMeanTime(start, stop);
    }

    if (pTimeMode->TiSetup6.tiState == true)
    {
        start = pTimeMode->TiSetup6.startIn;
        stop = pTimeMode->TiSetup6.stopIn;
        calculateMinMax(start, stop, &min, &max);
        pResultTime->measure6.mean = calculateSingleMeas(min, max);
        pResultTime->measure6.meanUnit = setUnitMeanTime(start, stop);
    }

    if (pTimeMode->TiSetup7.tiState == true)
    {
        start = pTimeMode->TiSetup7.startIn;
        stop = pTimeMode->TiSetup7.stopIn;
        calculateMinMax(start, stop, &min, &max);
        pResultTime->measure7.mean = calculateSingleMeas(min, max);
        pResultTime->measure7.meanUnit = setUnitMeanTime(start, stop);
    }
}

void ContinuousTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime)
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

float calculateSingleMeas(int min, int max)
{
    srand(time(0));
    return ((float)rand()/RAND_MAX) * (float)(max - min) + (float)min;
}

void calculateMinMax(uint8_t start, uint8_t stop, int *min, int *max)
{
    uint8_t distance = stop - start;

    if (distance > 0)
    {
        switch (distance)
        {
        case 1:
            *min = rand() % (45 + 1 - 43) + 43;
            *max = rand() % (53 + 1 - 50) + 50;
            break;
        case 2:
            *min = rand() % (4 + 1 - 3) + 3;
            *max = rand() % (7 + 1 - 5) + 5;
            break;
        case 3:
            *min = rand() % (20 + 1 - 15) + 15;
            *max = rand() % (26 + 1 - 21) + 21;
            break;
        case 4:
            *min = rand() % (96 + 1 - 94) + 94;
            *max = rand() % (102 + 1 - 100) + 100;
            break;
        case 5:
            *min = rand() % (2 + 1 - 1) + 1;
            *max = rand() % (4 + 1 - 3) + 3;
            break;
        case 6:
            *min = rand() % (9 + 1 - 7) + 7;
            *max = rand() % (12 + 1 - 10) + 10;
            break;
        case 7:
            *min = rand() % (98 + 1 - 96) + 96;
            *max = rand() % (102 + 1 - 100) + 100;
            break;
        }
    }
    else
    {
    	*min = 1;
    	*max = 2;
    }
}

Unit_t setUnitMeanTime(uint8_t start, uint8_t stop)
{
    uint8_t distance = stop - start;
    Unit_t result;

    if (distance > 0)
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
        }
    }
    else
    {
    	result = PICO;
    }

    return result;
}
