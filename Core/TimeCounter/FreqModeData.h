/*
 * FreqModeData.h
 *
 *  Created on: 15 paź 2021
 *      Author: Kacper
 */

#ifndef TIMECOUNTER_FREQMODEDATA_H_
#define TIMECOUNTER_FREQMODEDATA_H_

#include "Session.h"

typedef struct
{
    bool hfInputState;
    uint16_t gate;
} FreqMesSetup_t;

typedef struct
{
	uint8_t numberChanel;
    bool channelState;
    Slope_t slope;
    uint32_t threshold;
} FreqChannel_t;

typedef struct
{
    FreqChannel_t Channel1;
    FreqChannel_t Channel2;
    FreqChannel_t Channel3;
    FreqChannel_t Channel4;
    FreqChannel_t Channel5;
    FreqChannel_t Channel6;
    FreqChannel_t Channel7;
    FreqChannel_t Channel8;
    FreqMesSetup_t MessSetup;
    SessionSetup_t FreqSession;
} FrequencyMode_t;

typedef struct
{
	CalcConstParam_t parameters1;
	CalcConstParam_t parameters2;
	CalcConstParam_t parameters3;
	CalcConstParam_t parameters4;
	CalcConstParam_t parameters5;
	CalcConstParam_t parameters6;
	CalcConstParam_t parameters7;
	CalcConstParam_t parameters8;
	uint16_t iteration;
} ResultConstCalcFreq_t;

typedef struct
{
	CalcStampParam_t parameters1;
	CalcStampParam_t parameters2;
	CalcStampParam_t parameters3;
	CalcStampParam_t parameters4;
	CalcStampParam_t parameters5;
	CalcStampParam_t parameters6;
	CalcStampParam_t parameters7;
	CalcStampParam_t parameters8;
} ResultStampsCalcFreq_t;

typedef struct
{
	MeasValues_t measure1;
	MeasValues_t measure2;
	MeasValues_t measure3;
	MeasValues_t measure4;
	MeasValues_t measure5;
	MeasValues_t measure6;
	MeasValues_t measure7;
	MeasValues_t measure8;
} ResultFreq_t;

/**
 * @brief Funckja inicjalizujaca struktue FrequencyMode_t.
 * 
 * @param pTimeMode Struktura.
 */
void FrequencyModeInit(FrequencyMode_t *pFrequencyMode);

/**
 * @brief Funkcja inicjalizujaca struktur ResultConstCalcFreq_t.
 * 
 * @param pResultCalc Struktura.
 */
void ResultFreqParameterConstInit(ResultConstCalcFreq_t *pResultConstCalcFreq);

/**
 * @brief Funkcja inicjalizujaca struktur ResultStampsCalcFreq_t.
 * 
 * @param pResultCalc Struktura.
 */
void ResultFreqStampsInit(ResultStampsCalcFreq_t *pResultStampsCalcFreq);

/**
 * @brief Funkcja inicjalizujaca struktur ResultFreq_t.
 * 
 * @param pResultTime Struktura.
 */
void ResultFrequencyInit(ResultFreq_t *pResultFreq);

/**
 * @brief Funkcja symulatora odpowiedzialna za pojedynczy pomiar czestotliwosci.
 * 
 * @param pFrequencyMode Wskaznik na strukture z konfiguracja trybu pomiaru czestotliwosci.
 * @param pResultFreq Wskaznik na strukture z rezultatami pomiaru czestotliwosci.
 */
void SingleFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq);

/**
 * @brief Funkcja symulatora odpowiedzialna za ciagly pomiar czestotliwosci.
 * 
 * @param pFrequencyMode Wskaznik na strukture z konfiguracja trybu pomiaru czestotliwosci.
 * @param pResultFreq Wskaznik na strukture z rezultatami pomiaru czestotliwosci.
 * @param pResultCalc Wskaznik na strukture z rezultatami kalkulacji.
 */
void ContinuousFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq, ResultConstCalcFreq_t *pResultCalc);

/**
 * @brief Funkcja symulatora odpowiedzialna za pomiar serii z okreslona liczba pomiarow czestotliwosci.
 * 
 * @param pFrequencyMode Wskaznik na strukture z konfiguracja trybu pomiaru czestotliwosci.
 * @param pResultFreq Wskaznik na strukture z rezultatami pomiaru czestotliwosci.
 * @param pResultCalc Wskaznik na strukture z rezultatami kalkulacji.
 */
void StampsFreqMeas(FrequencyMode_t *pFrequencyMode, ResultFreq_t *pResultFreq, ResultStampsCalcFreq_t *pResultCalc);

/**
 * @brief Funkcja obliczajaca zakresy pomiarowe czestotliwosci w symulatorze.
 * 
 * @param numberCh Numer wejscia pomiarowego dla ktorego obliczana jest czestotlwiosc.
 * @param min Najmniejsza wartosc pomiarowa.
 * @param max Najwieksza wartosc pomiarowa.
 */
void calculateRange(uint8_t numberCh, int *min, int *max);

/**
 * @brief Funkcja ustawiajaca jednoski pomiarowe w symulowanych pomiarach.
 * 
 * @param numberCh Numer wejscia pomiarowego dla ktorego obliczana jest czestotlwiosc.
 * @return Unit_t Zwracana jest ustalona jednostka.
 */
Unit_t setUnitMeanFreq(uint8_t numberCh);

/**
 * @brief Funkcja ustawiajaca obliczone wartosci pomiarowe z pojedynczego pomiaru w strukturze wymiany danych.
 * 
 * @param pFreqChannel Wskaznik na strukture z konfiguracja pomiaru czestotliwosci.
 * @param pMeasFreq Wskaznik na strukture z wynikami pomiaru czestotliwosci.
 */
void setCalculatedParamSingleFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq);

/**
 * @brief Funkcja ustawiajaca obliczone wartosci pomiarowe z ciaglego pomiaru w strukturze wymiany danych.
 * 
 * @param pFreqChannel Wskaznik na strukture z konfiguracja pomiaru czestotliwosci.
 * @param pMeasFreq Wskaznik na strukture z wynikami pomiaru czestotliwosci.
 * @param pCalcParam Wskaznik na strukture z parametrami pomocniczymi w obliczeniach wartosci koncowych.
 */
void setCalculatedParamConstFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq, CalcConstParam_t *pCalcParam);

/**
 * @brief Funkcja ustawiajaca obliczone wartosci pomiarowe z pomiaru serii pomiarowej w strukturze wymiany danych.
 * 
 * @param pFreqChannel Wskaznik na strukture z konfiguracja pomiaru czestotliwosci.
 * @param pMeasFreq Wskaznik na strukture z wynikami pomiaru czestotliwosci.
 * @param pSessionSetup Wskaznik na strukture z parametrami konfiguracyjnymi sesji pomiarowej.
 * @param pCalcParam Wskaznik na strukture z parametrami pomocniczymi w obliczeniach wartosci koncowych.
 */
void setCalculatedParamStampsFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq, SessionSetup_t *pSessionSetup, CalcStampParam_t *pCalcParam);

/**
 * @brief Funckja odpowiedzialna za inicjalizacje poczatkowych watrosci w strukturach pomiarowych pomiaru czestotliwosci.
 * 
 * @param pFreqChannel Wskaznik na strukture z konfiguracja pomiaru czestotliwosci.
 * @param pMeasFreq Wskaznik na strukture z wynikami pomiaru czestotliwosci.
 */
void resetParamSingleFreq(FreqChannel_t *pFreqChannel, MeasValues_t *pMeasFreq);

#endif /* TIMECOUNTER_FREQMODEDATA_H_ */
