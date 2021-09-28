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
							ThresholdName setThreshold,
							uint32_t thresholdVal,
							bool hfInput,
							uint16_t gate);

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
	 * @brief Ustawienie stanu HF INPUT.
	 * 
	 * @param state True oznacza stan ON, false oznacza stan OFF.
	 */
	void setHfInput(bool state);

	/**
	 * @brief Ustawienie wartosci bramki.
	 * 
	 * @param value Wartosc bramki.
	 */
	void setGate(uint16_t value);

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
	 * @brief Funkcja zwraca stan HF INPUT.
	 * 
	 * @return true HF INPUT jest w stanie ON.
	 * @return false HF INPUT jest w stanie OFF.
	 */
	bool getHfInput();

	/**
	 * @brief Funkcja zwraca wartosc bramki.
	 * 
	 * @return uint16_t Wartosc bramki.
	 */
	uint16_t getGate();

private:
	uint8_t m_numberChannel;
	bool m_stateChannel;
	SlopeName m_slope;
	ThresholdName m_thresholdMode;
	uint32_t m_threshold;
	bool m_hfInput;
	uint16_t m_gate;
};

#endif /* GUI_INCLUDE_GUI_LIB_FREQMODEPARAMETER_HPP_ */
