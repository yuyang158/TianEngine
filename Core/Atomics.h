#pragma once

#include <OS.h>

namespace TianCore {
	static FORCEINLINE int8 InterlockedIncrement(volatile int8* value);
	static FORCEINLINE int16 InterlockedIncrement(volatile int16* value);
	static FORCEINLINE int32 InterlockedIncrement(volatile int32* value);
	static FORCEINLINE int64 InterlockedIncrement(volatile int64* value);

	static FORCEINLINE int8 InterlockedDecrement(volatile int8* value);
	static FORCEINLINE int16 InterlockedDecrement(volatile int16* value);
	static FORCEINLINE int32 InterlockedDecrement(volatile int32* value);
	static FORCEINLINE int64 InterlockedDecrement(volatile int64* value);

	static FORCEINLINE int8 InterlockedAdd(volatile int8* value, int8 amount);
	static FORCEINLINE int16 InterlockedAdd(volatile int16* value, int16 amount);
	static FORCEINLINE int32 InterlockedAdd(volatile int32* value, int32 amount);
	static FORCEINLINE int64 InterlockedAdd(volatile int64* value, int64 amount);
}

#include PLATFORM_INCLUDE_PATH(Atomics.inl)