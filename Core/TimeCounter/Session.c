/*
 * Session.c
 *
 *  Created on: 12 paź 2021
 *      Author: Kacper
 */

#include "Session.h"

void SessionInit(SessionSetup_t *pSessionSetup)
{
	pSessionSetup->maxRange = false;
    pSessionSetup->clock = INTERNAL_QUARTZ;
    pSessionSetup->repeat = 0;
    pSessionSetup->stampsNumber = 0;
    pSessionSetup->tiRange = 0;
}

void CalcParamInit(CalcConstParam_t *pCalcParam)
{
    pCalcParam->calculateMean = 0.0f;
    pCalcParam->calculateStdDev = 0.0f;
    pCalcParam->sizeBuffer = 0;
    memset(pCalcParam->measureBuffer, 0, 2000 * sizeof(pCalcParam->measureBuffer[0]));
}

void CalcParamStampsInit(CalcStampParam_t * pCalcParam)
{
	pCalcParam->calculateMean = 0.0f;
	pCalcParam->calculateStdDev = 0.0f;
	pCalcParam->sizeBuffer = 0;
	memset(pCalcParam->measureBuffer, 0, 300 * sizeof(pCalcParam->measureBuffer[0]));
}

void calculateMeanStdDevConst(CalcConstParam_t *pCalcParam) {
    float sum = 0.0, StdDev = 0.0;
    int i;
    if (pCalcParam->sizeBuffer == 1999)
    {
        pCalcParam->sizeBuffer = 0;
    }
    else
    {
        pCalcParam->sizeBuffer++;
    }
    for(i = 0; i < pCalcParam->sizeBuffer; ++i)
    {
        sum += pCalcParam->measureBuffer[i];
    }
    pCalcParam->calculateMean = sum / pCalcParam->sizeBuffer;
    for(i = 0; i < pCalcParam->sizeBuffer; ++i)
    {
        StdDev += pow(pCalcParam->measureBuffer[i] - pCalcParam->calculateMean, 2);
    }
    pCalcParam->calculateStdDev = sqrt(StdDev / pCalcParam->sizeBuffer);
}

void calculateMeanStdDevStamps(CalcStampParam_t *pCalcParam)
{
    float sum = 0.0, StdDev = 0.0;
    int i;
    for(i = 0; i < pCalcParam->sizeBuffer; ++i)
    {
        sum += pCalcParam->measureBuffer[i];
    }
    pCalcParam->calculateMean = sum / pCalcParam->sizeBuffer;
    for(i = 0; i < pCalcParam->sizeBuffer; ++i)
    {
        StdDev += pow(pCalcParam->measureBuffer[i] - pCalcParam->calculateMean, 2);
    }
    pCalcParam->calculateStdDev = sqrt(StdDev / pCalcParam->sizeBuffer);
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
