/*
 * Session.h
 *
 *  Created on: 12 paź 2021
 *      Author: Kacper
 */

#ifndef TIMECOUNTER_SESSION_H_
#define TIMECOUNTER_SESSION_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "cmsis_os.h"
#include "cmsis_os2.h"

typedef enum
{
    INTERNAL_QUARTZ = 1,
    INTERNAL_RUBID = 2,
    EXTERNAL = 3
} Clock_t;

typedef enum
{
    UP = 1,
    DOWN = 2
} Slope_t;

typedef enum
{
    PICO = 1,
    NANO = 2,
    MICRO = 3,
    MILLI = 4,
	KILO = 5,
	MEGA = 6,
	GIGA = 7,
	SEC = 8,
	HZ = 9
} Unit_t;

typedef struct
{
	bool maxRange;
    Clock_t clock;
    uint16_t tiRange;
    uint16_t stampsNumber;
    uint16_t repeat;
} SessionSetup_t;

typedef struct
{
    float mean;
    float stdDev;
    Unit_t meanUnit;
    Unit_t stdDevUnit;
} MeasValues_t;

typedef struct
{
    uint16_t sizeBuffer;
    float measureBuffer[2000];
    float calculateMean;
    float calculateStdDev;
} CalcConstParam_t;

typedef struct
{
	uint16_t sizeBuffer;
    float measureBuffer[285];
    float calculateMean;
    float calculateStdDev;
} CalcStampParam_t;

/**
 * @brief Funckja inicjalizujaca strukture SessionSetup_t.
 * 
 * @param pSessionSetup Struktura do inicjalizacja.
 */
void SessionInit(SessionSetup_t *pSessionSetup);

/**
 * @brief Funkcja inicjalizujaca strukture CalcConstParam_t.
 * 
 * @param pCalcParam Struktura do inicjalizacja.
 */
void CalcParamConstInit(CalcConstParam_t *pCalcParam);

/**
 * @brief Funkcja inicjalizujaca strukture CalcStampParam_t.
 * 
 * @param pCalcParam Struktura do inicjalizacja.
 */
void CalcParamStampsInit(CalcStampParam_t * pCalcParam);

/**
 * @brief Funkcja inicjalizujaca strukture CalcConstParam_t.
 * 
 * @param pCalcParam Struktura do inicjalizacja.
 */
void calculateMeanStdDevConst(CalcConstParam_t *pCalcParam);

/**
 * @brief Funkcja inicjalizujaca strukture CalcStampParam_t.
 * 
 * @param pCalcParam Struktura do inicjalizacja.
 */
void calculateMeanStdDevStamps(CalcStampParam_t *pCalcParam);

/**
 * @brief Funkcja do pojedynczego pomiaru (funkcja losujaca).
 * 
 * @param min Minimalny zakres losowanej wartosci.
 * @param max Maksymalny zakres losowanej wartosci.
 * @return float Wartosc losowa w podanym zakresie.
 */
float calculateSingleMeas(int min, int max);

#endif /* TIMECOUNTER_SESSION_H_ */
