/**
 * @file SessionSetup.cpp
 * @author Kacper Janowski
 * @brief 
 * @version 0.1
 * @date 2021-09-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gui/lib/SessionSetup.hpp>

SessionSetup::SessionSetup(bool maxRange,
							bool measRate,
							uint16_t range,
							uint16_t stamps,
							uint16_t repeat,
							uint16_t rate)
	: m_maxRange(maxRange)
	, m_measRate(measRate)
	, m_range(range)
	, m_stamps(stamps)
	, m_repeat(repeat)
	, m_rate(rate)
{}

SessionSetup::SessionSetup(const SessionSetup& other)
	: m_maxRange(other.m_maxRange)
	, m_measRate(other.m_measRate)
	, m_range(other.m_range)
	, m_stamps(other.m_stamps)
	, m_repeat(other.m_repeat)
	, m_rate(other.m_rate)
{}

SessionSetup::SessionSetup(SessionSetup&& other) noexcept
	: m_maxRange(std::move(other.m_maxRange))
	, m_measRate(std::move(other.m_measRate))
	, m_range(std::move(other.m_range))
	, m_stamps(std::move(other.m_stamps))
	, m_repeat(std::move(other.m_repeat))
	, m_rate(std::move(other.m_rate))
{}

SessionSetup &SessionSetup::operator=(const SessionSetup& other)
{
	if (this != &other)
	{
		return *this = SessionSetup(other);
	}
	return *this;
}

SessionSetup &SessionSetup::operator=(SessionSetup&& other) noexcept
{
	if (this != &other)
	{
		std::swap(SessionSetup::m_maxRange, other.m_maxRange);
		std::swap(SessionSetup::m_measRate, other.m_measRate);
		std::swap(SessionSetup::m_range, other.m_range);
		std::swap(SessionSetup::m_stamps, other.m_stamps);
		std::swap(SessionSetup::m_repeat, other.m_repeat);
		std::swap(SessionSetup::m_rate, other.m_rate);
	}
	return *this;
}

SessionSetup::~SessionSetup()= default;

void SessionSetup::setMaxRange(bool state)
{
	SessionSetup::m_maxRange = state;
}

void SessionSetup::setMeasRate(bool state)
{
	SessionSetup::m_measRate = state;
}

void SessionSetup::setRange(uint16_t value)
{
	SessionSetup::m_range = value;
}

void SessionSetup::setStampsNumber(uint16_t value)
{
	SessionSetup::m_stamps = value;
}

void SessionSetup::setRepeat(uint16_t value)
{
	SessionSetup::m_repeat = value;
}

void SessionSetup::setRate(uint16_t value)
{
	SessionSetup::m_rate = value;
}

bool SessionSetup::getMaxRange()
{
	return SessionSetup::m_maxRange;
}

bool SessionSetup::getMeasRate()
{
	return SessionSetup::m_measRate;
}

uint16_t SessionSetup::getRange()
{
	return SessionSetup::m_range;
}

uint16_t SessionSetup::getStampsNumber()
{
	return SessionSetup::m_stamps;
}

uint16_t SessionSetup::getRepeat()
{
	return SessionSetup::m_repeat;
}

uint16_t SessionSetup::getRate()
{
	return SessionSetup::m_rate;
}
