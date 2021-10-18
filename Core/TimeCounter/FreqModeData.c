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

