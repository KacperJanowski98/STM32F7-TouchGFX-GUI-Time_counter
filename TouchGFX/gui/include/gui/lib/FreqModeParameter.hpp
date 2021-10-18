/**
 * @file FreqModeParameter.hpp
 * @author Kacper Janowski
 * @brief
 * @version 0.1
 * @date 2021-09-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef GUI_INCLUDE_GUI_LIB_FREQMODEPARAMETER_HPP_
#define GUI_INCLUDE_GUI_LIB_FREQMODEPARAMETER_HPP_

#pragma once

#include <iostream>
#include <cstdint>
#include <gui/lib/TimeModeParameter.hpp>

/**
 * @brief Klasa do utworzenia kanalow w Frequency measurement.
 * 
 */
class FreqModeParameter
{
public:
	/**
	 * @brief Konstruktor.
	 * 
	 * @param numberChannel Numer kanalu.
	 * @param stateChannel Stan kanalu.
	 * @param slopeChannel Rodzaj zbocza kanalu.
	 * @param setThreshold Sposob definicji progu wyzwalania.
	 * @param thresholdVal Wartosc progu wyzwalania kanalu.
	 * @param hfInput Stan HfINPUT.
	 * @param gate Wartosc bramki.
	 */
	explicit FreqModeParameter(uint8_t numberChannel,
							bool stateChannel,
							SlopeName slopeChannel,
							uint32_t thresholdVal);

	/**
	 * @brief Konstruktor kopiujacy.
	 * 
	 * @param other Obiekt klasy FreqModeParameter.
	 */
	FreqModeParameter(const FreqModeParameter& other);

	/**
	 * @brief Konstruktor przenoszacy.
	 * 
	 * @param other Obiekt klasy FreqModeParameter.
	 */
	FreqModeParameter(FreqModeParameter&& other) noexcept;

	/**
	 * @brief Operator kopiujacy.
	 * 
	 * @param other Obiekt klasy FreqModeParameter.
	 * @return Obiekt klasy FreqModeParameter.
	 */
	FreqModeParameter& operator=(const FreqModeParameter& other);

	/**
	 * @brief Operator przenoszacy.
	 * 
	 * @param other Obiekt klasy FreqModeParameter.
	 * @return Obiekt klasy FreqModeParameter.
	 */
	FreqModeParameter& operator=(FreqModeParameter&& other) noexcept;

	/**
	 * @brief Destruktor.
	 * 
	 */
	~FreqModeParameter();

	/**
	 * @brief Ustawienie numeru kanalu.
	 *
	 * @param channel Kanal.
	 */
	void setNumberChannel(uint8_t channel);

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
	 * @brief Ustawienie progu wyzwalania dla obiektu kanalu.
	 * 
	 * @param value Wartosc progu wyzwolenia.
	 */
	void setThreshold(uint32_t value);

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
	 * @brief Funkcja zwracajaca wartosc progu wyzwolenia kanalu.
	 * 
	 * @return uint32_t Wartosc progu wyzwolenia.
	 */
	uint32_t getThreshold();

private:
	uint8_t m_numberChannel;
	bool m_stateChannel;
	SlopeName m_slope;
	uint32_t m_threshold;
};

#endif /* GUI_INCLUDE_GUI_LIB_FREQMODEPARAMETER_HPP_ */
