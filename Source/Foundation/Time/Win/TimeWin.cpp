#include <Time/Time.h>
#include <Windows.h>

using namespace Foundation;
static double g_fInvQpcFrequency;

void Time::Initialize() {
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	g_fInvQpcFrequency = 1.0 / double(frequency.QuadPart);
}

Time Time::Now() {
	LARGE_INTEGER temp;
	QueryPerformanceCounter(&temp);
	return Time::FromSeconds(double(temp.QuadPart) * g_fInvQpcFrequency);
}