#include "Time.h"

TIAN_FORCE_INLINE constexpr double Time::GetTotalNanoseconds() const {
	return m_fTime * 0.000000001;
}

TIAN_FORCE_INLINE constexpr double Time::GetTotalMicroseconds() const {
	return m_fTime * 0.000001;
}

TIAN_FORCE_INLINE constexpr double Time::GetTotalMilliseconds() const {
	return m_fTime * 0.001;
}

TIAN_FORCE_INLINE constexpr double Time::GetTotalSeconds() const {
	return m_fTime;
}

TIAN_FORCE_INLINE constexpr void Time::operator-=(const Time& other) {
	m_fTime -= other.m_fTime;
}

TIAN_FORCE_INLINE constexpr void Time::operator+=(const Time& other) {
	m_fTime += other.m_fTime;
}

TIAN_FORCE_INLINE constexpr Time Time::operator-() {
	return Time(-m_fTime);
}

TIAN_FORCE_INLINE constexpr Time Time::operator-(const Time& other) {
	return Time(m_fTime - other.m_fTime);
}
TIAN_FORCE_INLINE constexpr Time Time::operator+(const Time& other) {
	return Time(m_fTime + other.m_fTime);
}
