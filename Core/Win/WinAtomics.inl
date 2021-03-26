#include <process.h>
#include <OS.h>
#include <intrin.h>

namespace TianCore {
	FORCEINLINE int8 InterlockedIncrement(volatile int8* value) {
		return (int8)_InterlockedExchangeAdd8((char*)value, 1) + 1;
	}

	FORCEINLINE int16 InterlockedIncrement(volatile int16* value) {
		return (int16)_InterlockedIncrement16((short*)value);
	}

	FORCEINLINE int32 InterlockedIncrement(volatile int32* value) {
		return (int32)_InterlockedIncrement((long*)value);
	}

	FORCEINLINE int64 InterlockedIncrement(volatile int64* value) {
		return (int64)_InterlockedIncrement64((long long*)value);
	}

	FORCEINLINE int8 InterlockedDecrement(volatile int8* value) {
		return (int8)_InterlockedExchangeAdd8((char*)value, -1) - 1;
	}

	FORCEINLINE int16 InterlockedDecrement(volatile int16* value) {
		return (int16)_InterlockedDecrement16((short*)value);
	}

	FORCEINLINE int32 InterlockedDecrement(volatile int32* value) {
		return (int32)_InterlockedDecrement((long*)value);
	}

	FORCEINLINE int64 InterlockedDecrement(volatile int64* value) {
		return (int64)_InterlockedDecrement64((long long*)value);
	}

	FORCEINLINE int8 InterlockedAdd(volatile int8* value, int8 amount) {
		return (int8)::_InterlockedExchangeAdd8((char*)value, (char)amount);
	}

	FORCEINLINE int16 InterlockedAdd(volatile int16* value, int16 amount) {
		return (int16)::_InterlockedExchangeAdd16((short*)value, (short)amount);
	}

	FORCEINLINE int32 InterlockedAdd(volatile int32* value, int32 amount) {
		return (int32)::_InterlockedExchangeAdd((long*)value, (long)amount);
	}

	FORCEINLINE int64 InterlockedAdd(volatile int64* value, int64 amount) {
		return (int64)::_InterlockedExchangeAdd64((long long*)value, (long long)amount);
	}
}