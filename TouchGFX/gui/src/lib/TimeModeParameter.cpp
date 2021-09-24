/*
 * TimeModeParameter.cpp
 *
 *  Created on: 24 wrz 2021
 *      Author: Kacper Janowski
 */

#include <gui/lib/TimeModeParameter.hpp>

TimeModeParameter::TimeModeParameter(uint8_t numberChannel,
									bool stateChannel,
									Slope slope,
									Threshold setThreshold,
									uint32_t threshold,
									uint8_t startChannel,
									uint8_t stopChannel)
	: m_numberChannel(numberChannel)
	, m_stateChannel(stateChannel)
	, m_slope(slope)
	, m_setThreshold(setThreshold)
	, m_threshold(threshold)
	, m_startChannel(startChannel)
	, m_stopChannel(stopChannel)
{}

TimeModeParameter::TimeModeParameter(const TimeModeParameter& other)
	: m_numberChannel(other.m_numberChannel)
	, m_stateChannel(other.m_stateChannel)
	, m_slope(other.m_slope)
	, m_setThreshold(other.m_setThreshold)
	, m_threshold(other.m_threshold)
	, m_startChannel(other.m_startChannel)
	, m_stopChannel(other.m_stopChannel)
{}

TimeModeParameter::TimeModeParameter(TimeModeParameter&& other) noexcept
	: m_numberChannel(0)
	, m_stateChannel(false)
	, m_slope(Slope::UP)
	, m_setThreshold(Threshold::Manula)
	, m_threshold(100)
	, m_startChannel(0)
	, m_stopChannel(0)
{
	TimeModeParameter::m_numberChannel = other.m_numberChannel;
	TimeModeParameter::m_stateChannel = other.m_stateChannel;
	TimeModeParameter::m_slope = other.m_slope;
	TimeModeParameter::m_setThreshold = other.m_setThreshold;
	TimeModeParameter::m_threshold = other.m_threshold;
	TimeModeParameter::m_startChannel = other.m_startChannel;
	TimeModeParameter::m_stopChannel = other.m_stopChannel;

	other.m_numberChannel = 0;
	other.m_stateChannel = false;
	other.m_slope = Slope::UP;
	other.m_setThreshold = Threshold::Manula;
	other.m_threshold = 100;
	other.m_startChannel = 0;
	other.m_stopChannel = 0;
}

TimeModeParameter &TimeModeParameter::operator=(const TimeModeParameter& other)
{
	if (this != &other)
	{
		return *this = TimeModeParameter(other);
	}
	return *this;
}

TimeModeParameter &TimeModeParameter::operator=(TimeModeParameter&& other) noexcept
{
	if (this != &other)
	{
		std::swap(TimeModeParameter::m_numberChannel, other.m_numberChannel);
		std::swap(TimeModeParameter::m_stateChannel, other.m_stateChannel);
		std::swap(TimeModeParameter::m_slope, other.m_slope);
		std::swap(TimeModeParameter::m_setThreshold, other.m_setThreshold);
		std::swap(TimeModeParameter::m_threshold, other.m_threshold);
		std::swap(TimeModeParameter::m_startChannel, other.m_startChannel);
		std::swap(TimeModeParameter::m_stopChannel, other.m_stopChannel);
	}
	return *this;
}

TimeModeParameter::~TimeModeParameter()
{}














