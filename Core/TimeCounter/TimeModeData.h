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
	CalcConstParam_t parameters1;
	CalcConstParam_t parameters2;
	CalcConstParam_t parameters3;
	CalcConstParam_t parameters4;
	CalcConstParam_t parameters5;
	CalcConstParam_t parameters6;
	CalcConstParam_t parameters7;
	uint16_t iteration;
} ResultConstCalc_t;

typedef struct
{
	CalcStampParam_t parameters1;
	CalcStampParam_t parameters2;
	CalcStampParam_t parameters3;
	CalcStampParam_t parameters4;
	CalcStampParam_t parameters5;
	CalcStampParam_t parameters6;
	CalcStampParam_t parameters7;
} ResultStampsCalc_t;

typedef struct
{
	MeasValues_t measure1;
	MeasValues_t measure2;
	MeasValues_t measure3;
	MeasValues_t measure4;
	MeasValues_t measure5;
	MeasValues_t measure6;
	MeasValues_t measure7;
} ResultTime_t;

/**
 * @brief Funckja inicjalizujaca struktue TimeMode_t.
 * 
 * @param pTimeMode Struktura.
 */
void TimeModeInit(TimeMode_t *pTimeMode);

/**
 * @brief Funkcja inicjalizujaca struktur ResultConstCalc_t.
 * 
 * @param pResultCalc Struktura.
 */
void ResultTimeParameterConstInit(ResultConstCalc_t *pResultCalc);

/**
 * @brief Funkcja inicjalizujaca struktur ResultStampsCalc_t.
 * 
 * @param pResultCalc Struktura.
 */
void ResultTimeParameterStampsInit(ResultStampsCalc_t *pResultCalc);

/**
 * @brief Funkcja inicjalizujaca struktur ResultTime_t.
 * 
 * @param pResultTime Struktura.
 */
void ResultTimeInit(ResultTime_t *pResultTime);

/**
 * @brief Funkcja symulatora odpowiedzialna za pojedynczy pomiar czasu.
 * 
 * @param pTimeMode Wskaznik na strukture z konfiguracja trybu pomiaru relacji czasowych.
 * @param pResultTime Wskaznik na strukture z rezultatami pomiaru czasu.
 */
void SingleTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime);

/**
 * @brief Funkcja symulatora odpowiedzialna za ciagly pomiar czasu.
 * 
 * @param pTimeMode Wskaznik na strukture z konfiguracja trybu pomiaru relacji czasowych.
 * @param pResultTime Wskaznik na strukture z rezultatami pomiaru czasu.
 * @param pResultCalc Wskaznik na strukture z rezultatami kalkulacji.
 */
void ContinuousTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime, ResultConstCalc_t *pResultCalc);

/**
 * @brief Funkcja symulatora odpowiedzialna za pomiar serii z okreslona liczba pomiarow czasu.
 * 
 * @param pTimeMode Wskaznik na strukture z konfiguracja trybu pomiaru relacji czasowych.
 * @param pResultTime Wskaznik na strukture z rezultatami pomiaru czasu.
 * @param pResultCalc Wskaznik na strukture z rezultatami kalkulacji.
 */
void StampsTimeMeas(TimeMode_t *pTimeMode, ResultTime_t *pResultTime, ResultStampsCalc_t *pResultCalc);

/**
 * @brief Funkcja obliczajaca zakresy pomiarowe relacji czsowych w symulatorze.
 * 
 * @param start Numer wejscia pomiarowego rozpoczynajacego pomiar relacji czasowej.
 * @param stop Numer wejscia pomiarowego konczacego pomiar relacji czasowej.
 * @param min Najmniejsza wartosc pomiarowa.
 * @param max Najwieksza wartosc pomiarowa.
 */
void calculateMinMax(uint8_t start, uint8_t stop, int *min, int *max);

/**
 * @brief Funkcja ustawiajaca jednoski pomiarowe w symulowanych pomiarach.
 * 
 * @param start Numer wejscia pomiarowego rozpoczynajacego pomiar relacji czasowej.
 * @param stop Numer wejscia pomiarowego konczacego pomiar relacji czasowej.
 * @return Unit_t Zwracana jest ustalona jednostka.
 */
Unit_t setUnitMeanTime(uint8_t start, uint8_t stop);

/**
 * @brief Funkcja ustawiajaca obliczone wartosci pomiarowe z pojedynczego pomiaru w strukturze wymiany danych.
 * 
 * @param Ti Wskaznik na strukture z dana relacja czasowa.
 * @param meas  Wskaznik na strukture z wyniakami pomiarow.
 */
void setCalculatedParamSingleTime(TimeTi_t *Ti, MeasValues_t *meas);

/**
 * @brief Funkcja ustawiajaca obliczone wartosci pomiarowe z ciaglego pomiaru w strukturze wymiany danych.
 * 
 * @param Ti Struktura z dana relacja czasowa.
 * @param meas Struktura z wyniakami pomiarow.
 * @param pCalcParam Wskaznik na strukture z parametrami pomocniczymi w obliczeniach wartosci koncowych.
 */
void setCalculatedParamConstTime(TimeTi_t *Ti, MeasValues_t *meas, CalcConstParam_t *pCalcParam);

/**
 * @brief Funkcja ustawiajaca obliczone wartosci pomiarowe z pomiaru serii pomiarowej w strukturze wymiany danych.
 * 
 * @param Ti Struktura z dana relacja czasowa.
 * @param meas Struktura z wyniakami pomiarow.
 * @param pSessionSetup Wskaznik na strukture z parametrami konfiguracyjnymi sesji pomiarowej.
 * @param pCalcParam Wskaznik na strukture z parametrami pomocniczymi w obliczeniach wartosci koncowych.
 */
void setCalculatedParamStampsTime(TimeTi_t *Ti, MeasValues_t *meas, SessionSetup_t *pSessionSetup, CalcStampParam_t *pCalcParam);

/**
 * @brief Funckja odpowiedzialna za inicjalizacje poczatkowych watrosci w strukturach pomiarowych relacji czasowych.
 * 
 * @param Ti Struktura z dana relacja czasowa.
 * @param meas  Struktura z wyniakami pomiarow. 
 */
void resetParamSingleTime(TimeTi_t *Ti, MeasValues_t *meas);

#endif /* INC_TIMEMODEDATA_H_ */
