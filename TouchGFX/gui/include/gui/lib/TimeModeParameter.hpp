/*
 * TimeModeParameter.hpp
 *
 *  Created on: 24 wrz 2021
 *      Author: Kacper Janowski
 */

#ifndef GUI_INCLUDE_GUI_LIB_TIMEMODEPARAMETER_HPP_
#define GUI_INCLUDE_GUI_LIB_TIMEMODEPARAMETER_HPP_

#pragma once

#include <iostream>
#include <cstdint>

enum class SlopeName
{
	UP,
	DOWN
};

enum class ThresholdName
{
	Manula,
	Defined
};

class TimeModeParameter
{
public:
	/**
	 * Constructor.
	 */
	explicit TimeModeParameter(uint8_t numberChannel,
						bool stateChannel,
						SlopeName slopeChannel,
						ThresholdName setThreshold,
						uint32_t thresholdVal,
						uint8_t startChannel,
						uint8_t stopChannel);

	/**
	 * Copy constructor.
	 */
	TimeModeParameter(const TimeModeParameter& other);

	/**
	 * Move constructor.
	 */
	TimeModeParameter(TimeModeParameter&& other) noexcept;

	/**
	 * Copy assignment operator.
	 */
	TimeModeParameter& operator=(const TimeModeParameter& other);

	/**
	 * Move assignment operator.
	 */
	TimeModeParameter& operator=(TimeModeParameter&& other) noexcept;

	/**
	 * Destructor.
	 */
	~TimeModeParameter();

	void setStateChannel(bool state);

	void setSlope(SlopeName slope);

	void setThresholdMode(ThresholdName mode);

	void setThreshold(uint32_t value);

	void setStartChannel(uint8_t channel);

	void setStopChannel(uint8_t channel);

	uint8_t getNumberChannel();

	bool getStateChannel();

	SlopeName getSlope();

	ThresholdName getThresholdMode();

	uint32_t getThreshold();

	uint8_t getStartChannel();

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
