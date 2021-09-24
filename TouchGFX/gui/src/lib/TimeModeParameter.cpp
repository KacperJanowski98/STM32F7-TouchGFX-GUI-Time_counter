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
	, m_thresholdMode(setThreshold)
	, m_threshold(threshold)
	, m_startChannel(startChannel)
	, m_stopChannel(stopChannel)
{}

TimeModeParameter::TimeModeParameter(const TimeModeParameter& other)
	: m_numberChannel(other.m_numberChannel)
	, m_stateChannel(other.m_stateChannel)
	, m_slope(other.m_slope)
	, m_thresholdMode(other.m_thresholdMode)
	, m_threshold(other.m_threshold)
	, m_startChannel(other.m_startChannel)
	, m_stopChannel(other.m_stopChannel)
{}

TimeModeParameter::TimeModeParameter(TimeModeParameter&& other) noexcept
	: m_numberChannel(0)
	, m_stateChannel(false)
	, m_slope(Slope::UP)
	, m_thresholdMode(Threshold::Manula)
	, m_threshold(100)
	, m_startChannel(0)
	, m_stopChannel(0)
{
	TimeModeParameter::m_numberChannel = other.m_numberChannel;
	TimeModeParameter::m_stateChannel = other.m_stateChannel;
	TimeModeParameter::m_slope = other.m_slope;
	TimeModeParameter::m_thresholdMode = other.m_thresholdMode;
	TimeModeParameter::m_threshold = other.m_threshold;
	TimeModeParameter::m_startChannel = other.m_startChannel;
	TimeModeParameter::m_stopChannel = other.m_stopChannel;

	other.m_numberChannel = 0;
	other.m_stateChannel = false;
	other.m_slope = Slope::UP;
	other.m_thresholdMode = Threshold::Manula;
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
		std::swap(TimeModeParameter::m_thresholdMode, other.m_thresholdMode);
		std::swap(TimeModeParameter::m_threshold, other.m_threshold);
		std::swap(TimeModeParameter::m_startChannel, other.m_startChannel);
		std::swap(TimeModeParameter::m_stopChannel, other.m_stopChannel);
	}
	return *this;
}

TimeModeParameter::~TimeModeParameter()
{}

void TimeModeParameter::setStateChannel(bool state)
{
	TimeModeParameter::m_stateChannel = state;
}

void TimeModeParameter::setSlope(Slope slope)
{
	TimeModeParameter::m_slope = slope;
}

void TimeModeParameter::setThresholdMode(Threshold mode)
{
	TimeModeParameter::m_thresholdMode = mode;
}

void TimeModeParameter::setThreshold(uint32_t value)
{
	TimeModeParameter::m_threshold = value;
}

void TimeModeParameter::setStartChannel(uint8_t channel)
{
	TimeModeParameter::m_startChannel = channel;
}

void TimeModeParameter::setStopChannel(uint8_t channel)
{
	TimeModeParameter::m_stopChannel = channel;
}

uint8_t TimeModeParameter::getNumberChannel()
{
	return TimeModeParameter::m_numberChannel;
}

bool TimeModeParameter::getStateChannel()
{
	return TimeModeParameter::m_stateChannel;
}

Slope TimeModeParameter::getSlope()
{
	return TimeModeParameter::m_slope;
}

Threshold TimeModeParameter::getThresholdMode()
{
	return TimeModeParameter::m_thresholdMode;
}

uint32_t TimeModeParameter::getThreshold()
{
	return TimeModeParameter::m_threshold;
}

uint8_t TimeModeParameter::getStartChannel()
{
	return TimeModeParameter::m_startChannel;
}

uint8_t TimeModeParameter::getStopChannel()
{
	return TimeModeParameter::m_stopChannel;
}
