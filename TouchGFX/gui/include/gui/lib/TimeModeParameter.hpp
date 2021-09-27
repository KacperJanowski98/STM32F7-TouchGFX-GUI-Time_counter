/**
 * @file TimeModeParameter.hpp
 * @author Kacper Janowski
 * @brief 
 * @version 0.1
 * @date 2021-09-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GUI_INCLUDE_GUI_LIB_TIMEMODEPARAMETER_HPP_
#define GUI_INCLUDE_GUI_LIB_TIMEMODEPARAMETER_HPP_

#pragma once

#include <iostream>
#include <cstdint>

/**
 * @brief Klasa typu enum zawierajaca nazwy dostepnych zboczy w konfiguracji.
 * 
 */
enum class SlopeName
{
	UP,
	DOWN
};

/**
 * @brief Klasa typu enum zawierajaca nazwy dostep trybow ustawienia progu wyzwalania.
 * 
 */
enum class ThresholdName
{
	Manula,
	Defined
};

/**
 * @brief Klasa do utworzenia kanalow w trybie Time Interval Independent.
 * 
 */
class TimeModeParameter
{
public:
	/**
	 * Konstruktor.
	 */
	explicit TimeModeParameter(uint8_t numberChannel,
						bool stateChannel,
						SlopeName slopeChannel,
						ThresholdName setThreshold,
						uint32_t thresholdVal,
						uint8_t startChannel,
						uint8_t stopChannel);

	/**
	 * Konstruktor kopiujacy.
	 */
	TimeModeParameter(const TimeModeParameter& other);

	/**
	 * Konstruktor przenoszacy.
	 */
	TimeModeParameter(TimeModeParameter&& other) noexcept;

	/**
	 * Operator kopiujacy.
	 */
	TimeModeParameter& operator=(const TimeModeParameter& other);

	/**
	 * Operator przenoszacy.
	 */
	TimeModeParameter& operator=(TimeModeParameter&& other) noexcept;

	/**
	 * Destruktor.
	 */
	~TimeModeParameter();

	/**
	 * @brief Ustawienie stanu dla obiektu kanalu.
	 * 
	 * @param state True oznacza stan ON, false oznacza stan OFF.
	 */
	void setStateChannel(bool state);

	/**
	 * @brief Ustawinie zobacza dla obiektu kanalu.
	 * 
	 * @param slope UP oznacza zbocze narastajace, DOWN zbocze opadajace.
	 */
	void setSlope(SlopeName slope);

	/**
	 * @brief Ustawienie sposobu wyzwalania dla obiektu kanalu.
	 * 
	 * @param mode Manual oznacza reczne wybranie wartosci wyzwalania, defined ustawienie okreslonej wartosci.
	 */
	void setThresholdMode(ThresholdName mode);

	/**
	 * @brief Ustawienie progu wyzwalania dla obiektu kanalu.
	 * 
	 * @param value Wartosc progu wyzwolenia.
	 */
	void setThreshold(uint32_t value);

	/**
	 * @brief Ustawienie kanalu rozpoczynajacego pomiar.
	 * 
	 * @param channel Numer kanalu.
	 */
	void setStartChannel(uint8_t channel);

	/**
	 * @brief Ustawienie kanalu zakanczajacego pomiar.
	 * 
	 * @param channel Numer kanalu.
	 */
	void setStopChannel(uint8_t channel);

	/**
	 * @brief Funckja zwracajaca numer kanalu.
	 * 
	 * @return uint8_t Numer kanalu.
	 */
	uint8_t getNumberChannel();

	/**
	 * @brief Funkcja zwracajaza stan w jakim jest kanal.
	 * 
	 * @return true Kanal jest w stanie ON.
	 * @return false Kanal jest w stanie OFF.
	 */
	bool getStateChannel();

	/**
	 * @brief Funkcja zwracajaca rodzaj zbocza kanalu.
	 * 
	 * @return SlopeName Zbocze.
	 */
	SlopeName getSlope();

	/**
	 * @brief Funkcja zwracajaca tryb ustawiania progu wyzwalnia kanalu.
	 * 
	 * @return ThresholdName Tryb progu wyzwalania.
	 */
	ThresholdName getThresholdMode();

	/**
	 * @brief Funkcja zwracajaca wartosc progu wyzwolenia kanalu.
	 * 
	 * @return uint32_t Wartosc progu wyzwolenia.
	 */
	uint32_t getThreshold();

	/**
	 * @brief Funkcja zwracajaca kanal poczatkowy.
	 * 
	 * @return uint8_t Numer kanalu.
	 */
	uint8_t getStartChannel();

	/**
	 * @brief Funkcja zwracajaca kanal koncowy.
	 * 
	 * @return uint8_t Numer kanalu.
	 */
	uint8_t getStopChannel();

private:
	uint8_t m_numberChannel;
	bool m_stateChannel;
	SlopeName m_slope;
	ThresholdName m_thresholdMode;
	uint32_t m_threshold;
	uint8_t m_startChannel;
	uint8_t m_stopChannel;
};

#endif /* GUI_INCLUDE_GUI_LIB_TIMEMODEPARAMETER_HPP_ */
