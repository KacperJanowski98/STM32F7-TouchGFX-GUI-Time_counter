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
	UP = 1,
	DOWN = 2
};

/**
 * @brief Klasa typu enum zawierajaca nazwy dostepnych zrodel zegarowych.
 *
 */
enum class ClockName
{
	INTERNAL_QUARTZ = 1,
	INTERNAL_RUBID = 2,
	EXTERNAL = 3
};

/**
 * @brief Klasa do utworzenia kanalow w trybie Time Interval Independent.
 * 
 */
class TimeModeParameter
{
public:
	/**
	 * @brief Konstrukto.
	 * 
	 * @param numberChannel	Numer wejscia pomiarowego.
	 * @param stateChannel	Stan wejscia pomiarowego.
	 * @param tiState		Stan odcinka czasowego
	 * @param slopeChannel	Rodzaj zbocza wejscia pomiarowego.
	 * @param thresholdVal	Wartosc progu wyzwalania wejscia.
	 * @param startChannel	Numer wejœcia poczatkowego.
	 * @param stopChannel	Numer wejœcia koncowego.
	 */
	explicit TimeModeParameter(uint8_t numberChannel,
						bool stateChannel,
						bool tiState,
						SlopeName slopeChannel,
						uint32_t thresholdVal,
						uint8_t startChannel,
						uint8_t stopChannel);

	/**
	 * @brief Konstruktor kopiujacy.
	 * 
	 * @param other Obiekt klasy TimeModeParameter.
	 */
	TimeModeParameter(const TimeModeParameter& other);

	/**
	 * @brief Konstruktor przenoszacy.
	 * 
	 * @param other Obiekt klasy TimeModeParameter.
	 */
	TimeModeParameter(TimeModeParameter&& other) noexcept;

	/**
	 * @brief Operator kopiujacy.
	 * 
	 * @param other Obiekt klasy TimeModeParameter.
	 * @return Obiekt klasy TimeModeParameter.
	 */
	TimeModeParameter& operator=(const TimeModeParameter& other);

	/**
	 * @brief Operator przenoszacy.
	 * 
	 * @param other Obiekt klasy TimeModeParameter.
	 * @return Obiekt klasy TimeModeParameter.
	 */
	TimeModeParameter& operator=(TimeModeParameter&& other) noexcept;

	/**
	 * @brief Destruktor.
	 * 
	 */
	~TimeModeParameter();

	/**
	 * @brief Ustawienie stanu dla obiektu kanalu.
	 * 
	 * @param state True oznacza stan ON, false oznacza stan OFF.
	 */
	void setStateChannel(bool state);

	/**
	 * @brief Ustawienie stanu odcinka czasowego.
	 *
	 * @param state True oznacza stan ON, false oznacza stan OFF.
	 */
	void setTiState(bool state);

	/**
	 * @brief Ustawinie zobacza dla obiektu kanalu.
	 * 
	 * @param slope UP oznacza zbocze narastajace, DOWN zbocze opadajace.
	 */
	void setSlope(SlopeName slope);

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
	 * @brief Funkcja zwracajaza stan w jakim jest dany odcinek czasowy.
	 *
	 * @return true Odcinek jest w stanie ON.
	 * @return false Odcinek jest w stanie OFF.
	 */
	bool getTiState();

	/**
	 * @brief Funkcja zwracajaca rodzaj zbocza kanalu.
	 * 
	 * @return SlopeName Zbocze.
	 */
	SlopeName getSlope();

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
	bool m_tiState;
	SlopeName m_slope;
	uint32_t m_threshold;
	uint8_t m_startChannel;
	uint8_t m_stopChannel;
};

#endif /* GUI_INCLUDE_GUI_LIB_TIMEMODEPARAMETER_HPP_ */
