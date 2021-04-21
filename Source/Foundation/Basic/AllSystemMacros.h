#pragma once

// Platform
#define TIAN_PLATFORM_WINDOWS 0
#define TIAN_PLATFORM_OSX 0
#define TIAN_PLATFORM_LINUX 0
#define TIAN_PLATFORM_IOS 0
#define TIAN_PLATFORM_ANDROID 0

// OS Bit
#define TIAN_PLATFORM_32BIT 0
#define TIAN_PLATFORM_64BIT 0

// Compiler
#define TIAN_COMPILER_MSVC 0
#define TIAN_COMPILER_GCC 0
#define TIAN_COMPILER_CLANG 0

// CPU Family
#define TIAN_CPU_X86 0
#define TIAN_CPU_ARM 0

// Allocator
#define TIAN_USE_ALLOCATION_TRACKING 0
#define TIAN_USE_ALLOCATION_STACK_TRACING 0
#define TIAN_USE_GUARDED_ALLOCATIONS 0

// Other
#define TIAN_PROFILING_ENABLED 0
#define TIAN_DEBUG_BUILD 0
#define TIAN_RELEASE_BUILD 0

#if defined(_WINDOWS) || defined(_WIN32)
#	include <Basic/Win/PlatformWin.h>
#else
#error "Unsupport OS"
#endif

#if defined(_MSC_VER)
#	include <Basic/Compiler/MSVC.h>
#endif

#if defined(_DEBUG)
#undef TIAN_DEBUG_BUILD
#define TIAN_DEBUG_BUILD 1
#else
#undef TIAN_RELEASE_BUILD
#define TIAN_RELEASE_BUILD 1
#endif

#ifndef __INTELLISENSE__
#define TIAN_STATIC_CHECK(exp)
#else
#define TIAN_STATIC_CHECK(exp) static_assert(exp, TIAN_STRING(exp))
#endif