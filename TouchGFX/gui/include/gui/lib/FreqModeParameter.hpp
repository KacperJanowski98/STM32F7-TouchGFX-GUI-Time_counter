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

class FreqModeParameter
{
public:
	explicit FreqModeParameter(uint8_t numberChannel,
							bool stateChannel,
							SlopeName slopeChannel,
							ThresholdName setThreshold,
							uint32_t thresholdVal,
							bool hfInput,
							uint16_t gate);

	FreqModeParameter(const FreqModeParameter& other);

	FreqModeParameter(FreqModeParameter&& other) noexcept;

	FreqModeParameter& operator=(const FreqModeParameter& other);

	FreqModeParameter& operator=(FreqModeParameter&& other) noexcept;

	~FreqModeParameter();

	void setStateChannel(bool state);

	void setSlope(SlopeName slope);

	void setThresholdMode(ThresholdName mode);

	void setThreshold(uint32_t value);

	void setHfInput(bool state);

	void setGate(uint16_t value);

	uint8_t getNumberChannel();

	bool getStateChannel();

	SlopeName getSlope();

	ThresholdName getThresholdMode();

	uint32_t getThreshold();

	bool getHfInput();

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
