#pragma once
#include <AllSystemMacros.h>

namespace Foundation {
	struct Time {
	public:
		
	public:
		static Time Now();

		TIAN_FORCE_INLINE Time()
			: m_fTime(0.0) {}

		TIAN_FORCE_INLINE constexpr static Time FromNanoseconds(double fNanoseconds) { return Time(fNanoseconds * 0.000000001); }
		TIAN_FORCE_INLINE constexpr static Time FromMicroseconds(double fMicroseconds) { return Time(fMicroseconds * 0.000001); }
		TIAN_FORCE_INLINE constexpr static Time FromMilliseconds(double fMilliseconds) { return Time(fMilliseconds * 0.001); }
		TIAN_FORCE_INLINE constexpr static Time FromSeconds(double fSecond) { return Time(fSecond); }

		[[nodiscard]] constexpr double GetTotalNanoseconds() const;
		[[nodiscard]] constexpr double GetTotalMicroseconds() const;
		[[nodiscard]] constexpr double GetTotalMilliseconds() const;
		[[nodiscard]] constexpr double GetTotalSeconds() const;

		constexpr void operator-=(const Time& other);
		constexpr void operator+=(const Time& other);

		constexpr Time operator-();
		constexpr Time operator-(const Time& other);
		constexpr Time operator+(const Time& other);

	private:
		constexpr explicit Time(double fTime)
			: m_fTime(fTime) {}

		double m_fTime;
	};
#include <Time/Time.inl>
}
