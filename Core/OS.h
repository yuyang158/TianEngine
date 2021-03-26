#pragma once

#if defined(_MSC_VER)
    #define TIAN_MSVC_COMPILER
#elif defined(__GNUC__)
    #define TIAN_GCC_COMPILER
#elif defined(__clang__)
    #define TIAN_CLANG_COMPILER
#endif

#ifndef TIAN_CPU_X86_FAMILY
	#if (defined(_M_IX86) || defined(__i386__) || defined(_M_X64) || defined(__amd64) || defined(__x86_64__))
		#define TIAN_CPU_X86_FAMILY 1
	#else
		#define TIAN_CPU_X86_FAMILY 0
	#endif
#endif

#ifndef TIAN_CPU_ARM_FAMILY
	#if (defined(__arm__) || defined(_M_ARM) || defined(__aarch64__) || defined(_M_ARM64))
		#define TIAN_CPU_ARM_FAMILY 1
	#else
		#define TIAN_CPU_ARM_FAMILY 0
	#endif
#endif

#ifndef TIAN_PLATFORM_HAS_CPUID
	#if defined(_M_IX86) || defined(__i386__) || defined(_M_X64) || defined(__x86_64__) || defined (__amd64__)
		#define TIAN_PLATFORM_HAS_CPUID				1
	#else
		#define TIAN_PLATFORM_HAS_CPUID				0
	#endif
#endif

#ifndef TIAN_BUILD_DEBUG
	#define TIAN_BUILD_DEBUG 0
#endif

#if defined( _WIN64 )
#include "Win/OS_Win.h"
#elif defined(__OSX__)
#include "Win/OS_macosx.h"
#else
	#error Not support platform.
#endif

#ifndef TIAN_PLATFORM_WIN
	#define TIAN_PLATFORM_WIN 0
#endif

#ifndef TIAN_PLATFORM_MACOSX
	#define TIAN_PLATFORM_MACOSX 0
#endif

// Turns an preprocessor token into a real string (see UBT_COMPILED_PLATFORM)
#define PREPROCESSOR_TO_STRING(x) PREPROCESSOR_TO_STRING_INNER(x)
#define PREPROCESSOR_TO_STRING_INNER(x) #x

// Concatenates two preprocessor tokens, performing macro expansion on them first
#define PREPROCESSOR_JOIN(x, y) PREPROCESSOR_JOIN_INNER(x, y)
#define PREPROCESSOR_JOIN_INNER(x, y) x/x##y

#ifndef PLATFORM_INCLUDE_PATH
#define PLATFORM_INCLUDE_PATH(IncludeFile) PREPROCESSOR_TO_STRING(PREPROCESSOR_JOIN(TIAN_PLATFORM_HEADER_NAME, IncludeFile))
#endif // !PLATFORM_INCLUDE

#include PLATFORM_INCLUDE_PATH(PlatformTypes.h)

typedef PlatformTypes::int8 int8;
typedef PlatformTypes::int16 int16;
typedef PlatformTypes::int32 int32;
typedef PlatformTypes::int64 int64;

typedef PlatformTypes::uint8 uint8;
typedef PlatformTypes::uint16 uint16;
typedef PlatformTypes::uint32 uint32;
typedef PlatformTypes::uint64 uint64;

typedef PlatformTypes::SIZE_T SIZE_T;
#undef size_t