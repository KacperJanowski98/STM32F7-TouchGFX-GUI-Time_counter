/**
 * @file TimeModeParameter.cpp
 * @author Kacper Janowski
 * @brief 
 * @version 0.1
 * @date 2021-09-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gui/lib/TimeModeParameter.hpp>

TimeModeParameter::TimeModeParameter(uint8_t numberChannel,
									bool stateChannel,
									bool tiState,
									SlopeName slope,
									uint32_t threshold,
									uint8_t startChannel,
									uint8_t stopChannel)
	: m_numberChannel(numberChannel)
	, m_stateChannel(stateChannel)
	, m_tiState(tiState)
	, m_slope(slope)
	, m_threshold(threshold)
	, m_startChannel(startChannel)
	, m_stopChannel(stopChannel)
{}

TimeModeParameter::TimeModeParameter(const TimeModeParameter& other)
	: m_numberChannel(other.m_numberChannel)
	, m_stateChannel(other.m_stateChannel)
	, m_tiState(other.m_tiState)
	, m_slope(other.m_slope)
	, m_threshold(other.m_threshold)
	, m_startChannel(other.m_startChannel)
	, m_stopChannel(other.m_stopChannel)
{}

TimeModeParameter::TimeModeParameter(TimeModeParameter&& other) noexcept
	: m_numberChannel(std::move(other.m_numberChannel))
	, m_stateChannel(std::move(other.m_stateChannel))
	, m_tiState(std::move(other.m_tiState))
	, m_slope(std::move(other.m_slope))
	, m_threshold(std::move(other.m_threshold))
	, m_startChannel(std::move(other.m_startChannel))
	, m_stopChannel(std::move(other.m_stopChannel))
{}

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
		std::swap(TimeModeParameter::m_tiState, other.m_tiState);
		std::swap(TimeModeParameter::m_slope, other.m_slope);
		std::swap(TimeModeParameter::m_threshold, other.m_threshold);
		std::swap(TimeModeParameter::m_startChannel, other.m_startChannel);
		std::swap(TimeModeParameter::m_stopChannel, other.m_stopChannel);
	}
	return *this;
}

TimeModeParameter::~TimeModeParameter() = default;


void TimeModeParameter::setStateChannel(bool state)
{
	TimeModeParameter::m_stateChannel = state;
}

void TimeModeParameter::setTiState(bool state)
{
	TimeModeParameter::m_tiState = state;
}

void TimeModeParameter::setSlope(SlopeName slope)
{
	TimeModeParameter::m_slope = slope;
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

bool TimeModeParameter::getTiState()
{
	return TimeModeParameter::m_tiState;
}

SlopeName TimeModeParameter::getSlope()
{
	return TimeModeParameter::m_slope;
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
