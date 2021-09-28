/**
 * @file FreqModeParameter.cpp
 * @author Kacper Janowski
 * @brief
 * @version 0.1
 * @date 2021-09-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <gui/lib/FreqModeParameter.hpp>

FreqModeParameter::FreqModeParameter(uint8_t numberChannel,
									bool stateChannel,
									SlopeName slopeChannel,
									ThresholdName setThreshold,
									uint32_t thresholdVal,
									bool hfInput,
									uint16_t gate)
	: m_numberChannel(numberChannel)
	, m_stateChannel(stateChannel)
	, m_slope(slopeChannel)
	, m_thresholdMode(setThreshold)
	, m_threshold(thresholdVal)
	, m_hfInput(hfInput)
	, m_gate(gate)
{}

FreqModeParameter::FreqModeParameter(const FreqModeParameter& other)
	: m_numberChannel(other.m_numberChannel)
	, m_stateChannel(other.m_stateChannel)
	, m_slope(other.m_slope)
	, m_thresholdMode(other.m_thresholdMode)
	, m_threshold(other.m_threshold)
	, m_hfInput(other.m_hfInput)
	, m_gate(other.m_gate)
{}

FreqModeParameter::FreqModeParameter(FreqModeParameter&& other) noexcept
	: m_numberChannel(std::move(other.m_numberChannel))
	, m_stateChannel(std::move(other.m_stateChannel))
	, m_slope(std::move(other.m_slope))
	, m_thresholdMode(std::move(other.m_thresholdMode))
	, m_threshold(std::move(other.m_threshold))
	, m_hfInput(std::move(other.m_hfInput))
	, m_gate(std::move(other.m_gate))
{}

FreqModeParameter &FreqModeParameter::operator=(const FreqModeParameter& other)
{
	if (this != &other)
	{
		return *this = FreqModeParameter(other);
	}
	return *this;
}

FreqModeParameter &FreqModeParameter::operator=(FreqModeParameter&& other) noexcept
{
	if (this != &other)
	{
		std::swap(FreqModeParameter::m_numberChannel, other.m_numberChannel);
		std::swap(FreqModeParameter::m_stateChannel, other.m_stateChannel);
		std::swap(FreqModeParameter::m_slope, other.m_slope);
		std::swap(FreqModeParameter::m_thresholdMode, other.m_thresholdMode);
		std::swap(FreqModeParameter::m_threshold, other.m_threshold);
		std::swap(FreqModeParameter::m_hfInput, other.m_hfInput);
		std::swap(FreqModeParameter::m_gate, other.m_gate);
	}
	return *this;
}

FreqModeParameter::~FreqModeParameter()
{}

void FreqModeParameter::setStateChannel(bool state)
{
	FreqModeParameter::m_stateChannel = state;
}

void FreqModeParameter::setSlope(SlopeName slope)
{
	FreqModeParameter::m_slope = slope;
}

void FreqModeParameter::setThresholdMode(ThresholdName mode)
{
	FreqModeParameter::m_thresholdMode = mode;
}

void FreqModeParameter::setThreshold(uint32_t value)
{
	FreqModeParameter::m_threshold = value;
}

void FreqModeParameter::setHfInput(bool state)
{
	FreqModeParameter::m_hfInput = state;
}

void FreqModeParameter::setGate(uint16_t value)
{
	FreqModeParameter::m_gate = value;
}

uint8_t FreqModeParameter::getNumberChannel()
{
	return FreqModeParameter::m_numberChannel;
}

bool FreqModeParameter::getStateChannel()
{
	return FreqModeParameter::m_stateChannel;
}

SlopeName FreqModeParameter::getSlope()
{
	return FreqModeParameter::m_slope;
}

ThresholdName FreqModeParameter::getThresholdMode()
{
	return FreqModeParameter::m_thresholdMode;
}

uint32_t FreqModeParameter::getThreshold()
{
	return FreqModeParameter::m_threshold;
}

bool FreqModeParameter::getHfInput()
{
	return FreqModeParameter::m_hfInput;
}

uint16_t FreqModeParameter::getGate()
{
	return FreqModeParameter::m_gate;
}
