/*
 * TimeModeData.h
 *
 *  Created on: 28 wrz 2021
 *      Author: Kacper
 */

#ifndef INC_TIMEMODEDATA_H_
#define INC_TIMEMODEDATA_H_

#include "Session.h"

typedef struct
{
    bool tiState;
    uint8_t startIn;
    uint8_t stopIn;
} TimeTi_t;

typedef struct
{
    bool channelState;
    Slope_t slope;
    uint32_t threshold;
} TimeChannel_t;

typedef struct
{
    TimeChannel_t Channel1;
    TimeChannel_t Channel2;
    TimeChannel_t Channel3;
    TimeChannel_t Channel4;
    TimeChannel_t Channel5;
    TimeChannel_t Channel6;
    TimeChannel_t Channel7;
    TimeChannel_t Channel8;
    TimeTi_t TiSetup1;
    TimeTi_t TiSetup2;
    TimeTi_t TiSetup3;
    TimeTi_t TiSetup4;
    TimeTi_t TiSetup5;
    TimeTi_t TiSetup6;
    TimeTi_t TiSetup7;
    SessionSetup_t TimeSession;
} TimeMode_t;

typedef struct
{
    float mean;
    float stdDev;
    Unit_t meanUnit;
    Unit_t stdDevUnit;
} MeasTime_t;

typedef struct
{
    MeasTime_t measure1;
    MeasTime_t measure2;
    MeasTime_t measure3;
    MeasTime_t measure4;
    MeasTime_t measure5;
    MeasTime_t measure6;
    MeasTime_t measure7;
} ResultTime_t;

void TimeModeInit(TimeMode_t *pTimeMode);

void ResultTimeInit(ResultTime_t *pResultTime);

void SingleTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime);

void ContinuousTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime);

void StampsTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime);

void RepeatTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime);

float calculateSingleMeas(int min, int max);

void calculateMinMax(uint8_t start, uint8_t stop, int *min, int *max);

Unit_t setUnitMeanTime(uint8_t start, uint8_t stop);

void setCalculatedParamSingleTime(TimeTi_t *Ti, MeasTime_t *meas);

void resetParamSingleTime(TimeTi_t *Ti, MeasTime_t *meas);

#endif /* INC_TIMEMODEDATA_H_ */
