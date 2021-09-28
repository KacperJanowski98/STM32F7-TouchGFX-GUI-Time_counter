/**
 * @file SessionSetup.hpp
 * @author Kacper Janowski
 * @brief 
 * @version 0.1
 * @date 2021-09-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GUI_INCLUDE_GUI_LIB_SESSIONSETUP_HPP_
#define GUI_INCLUDE_GUI_LIB_SESSIONSETUP_HPP_

#pragma once

#include <iostream>
#include <cstdint>

class SessionSetup
{
public:
	/**
	 * Konstruktor.
	 */
	explicit SessionSetup(bool maxRange,
							bool measRate,
							uint16_t range,
							uint16_t stamps,
							uint16_t repeat,
							uint16_t rate);

	/**
	 * Konstruktor kopiujacy.
	 */
	SessionSetup(const SessionSetup& other);

	/**
	 * Konstruktor przenoszacy.
	 */
	SessionSetup(SessionSetup&& other) noexcept;

	/**
	 * Operator kopiujacy.
	 */
	SessionSetup& operator=(const SessionSetup& other);

	/**
	 * Operator przenoszaych.
	 */
	SessionSetup& operator=(SessionSetup&& other) noexcept;

	/**
	 * Destruktor.
	 */
	~SessionSetup();

	/**
	 * @brief Ustawienie maksymalnego zakresu.
	 * 
	 * @param state True ustawienie maksymalnego zakresu, false ustawienie manualne.
	 */
	void setMaxRange(bool state);

	/**
	 * @brief Ustawienie tempa pomiaru.
	 * 
	 * @param state True zezwolenie na ustawinie, false brak zezwolenia.
	 */
	void setMeasRate(bool state);

	/**
	 * @brief Ustawienie zakresu.
	 * 
	 * @param value Wartosc zakresu.
	 */
	void setRange(uint16_t value);

	/**
	 * @brief Ustawienie liczby znacznikow.
	 * 
	 * @param value Liczba znacznikow.
	 */
	void setStampsNumber(uint16_t value);

	/**
	 * @brief Ustawienie liczby powtorzen pomiarow.
	 * 
	 * @param value Liczba powtorzen.
	 */
	void setRepeat(uint16_t value);

	/**
	 * @brief Ustawienie tempa.
	 * 
	 * @param value Wartosc tempa.
	 */
	void setRate(uint16_t value);

	/**
	 * @brief Funkcja zwracajaca czy ustawiony jest maksymalny zakre.
	 * 
	 * @return true Ustawiony maksymalny zakres.
	 * @return false Zdefiniowany manualnie zakres.
	 */
	bool getMaxRange();

	/**
	 * @brief Funkcja zwaracajaca czy ustawione jest tempo wykonywania pomiarow.
	 * 
	 * @return true Ustawione tempo.
	 * @return false Nieustawione tempo.
	 */
	bool getMeasRate();

	/**
	 * @brief Funkcja zwracajaca wartosc zakresu.
	 * 
	 * @return uint16_t Zakres.
	 */
	uint16_t getRange();

	/**
	 * @brief Funkcja zwracajaca liczbe znacznikow.
	 * 
	 * @return uint16_t Liczba znacznikow.
	 */
	uint16_t getStampsNumber();

	/**
	 * @brief Funkcja zwracajaca liczbe powtorzen pomiarow.
	 * 
	 * @return uint16_t Liczba powtorzen.
	 */
	uint16_t getRepeat();

	/**
	 * @brief Funkcja zwracajaca ustawione tempo.
	 * 
	 * @return uint16_t Tempo.
	 */
	uint16_t getRate();

private:
	bool m_maxRange;
	bool m_measRate;
	uint16_t m_range;
	uint16_t m_stamps;
	uint16_t m_repeat;
	uint16_t m_rate;
};

#endif /* GUI_INCLUDE_GUI_LIB_SESSIONSETUP_HPP_ */
