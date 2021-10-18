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
									uint32_t thresholdVal)
	: m_numberChannel(numberChannel)
	, m_stateChannel(stateChannel)
	, m_slope(slopeChannel)
	, m_threshold(thresholdVal)
{}

FreqModeParameter::FreqModeParameter(const FreqModeParameter& other)
	: m_numberChannel(other.m_numberChannel)
	, m_stateChannel(other.m_stateChannel)
	, m_slope(other.m_slope)
	, m_threshold(other.m_threshold)
{}

FreqModeParameter::FreqModeParameter(FreqModeParameter&& other) noexcept
	: m_numberChannel(std::move(other.m_numberChannel))
	, m_stateChannel(std::move(other.m_stateChannel))
	, m_slope(std::move(other.m_slope))
	, m_threshold(std::move(other.m_threshold))
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
		std::swap(FreqModeParameter::m_threshold, other.m_threshold);
	}
	return *this;
}

FreqModeParameter::~FreqModeParameter() = default;

void FreqModeParameter::setNumberChannel(uint8_t channel)
{
	FreqModeParameter::m_numberChannel = channel;
}

void FreqModeParameter::setStateChannel(bool state)
{
	FreqModeParameter::m_stateChannel = state;
}

void FreqModeParameter::setSlope(SlopeName slope)
{
	FreqModeParameter::m_slope = slope;
}

void FreqModeParameter::setThreshold(uint32_t value)
{
	FreqModeParameter::m_threshold = value;
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

uint32_t FreqModeParameter::getThreshold()
{
	return FreqModeParameter::m_threshold;
}
