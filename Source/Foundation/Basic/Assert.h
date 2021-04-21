#pragma once

#if TIAN_PLATFORM_WINDOWS
#define TIAN_DEBUG_BREAK() __debugbreak()
#endif

#if TIAN_DEBUG_BUILD
#define TIAN_ASSERT(expr) assert(expr)
#else
#define TIAN_ASSERT(expr) ((void)0)
#endif

namespace Foundation {
	struct AssertHelper {
		static int32 DoAssert(const char* pExpression,
			const char* pFile,
			int32 line,
			const char* pFunction,
			const char* pMessage = nullptr);
	};
}