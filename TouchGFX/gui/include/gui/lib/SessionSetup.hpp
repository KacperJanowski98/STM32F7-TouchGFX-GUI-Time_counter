/*
 * SessionSetup.hpp
 *
 *  Created on: 27 wrz 2021
 *      Author: kacpe
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

	void setMaxRange(bool state);

	void setMeasRate(bool state);

	void setRange(uint16_t value);

	void setStampsNumber(uint16_t value);

	void setRepeat(uint16_t value);

	void setRate(uint16_t value);

	bool getMaxRange();

	bool getMeasRate();

	uint16_t getRange();

	uint16_t getStampsNumber();

	uint16_t getRepeat();

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
