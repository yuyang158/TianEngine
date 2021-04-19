#pragma once

using int8 = char;
using int16 = short;
using int32 = int;
using int64 = long long;

using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;

TIAN_STATIC_CHECK(sizeof(bool) == 1);
TIAN_STATIC_CHECK(sizeof(char) == 1);
TIAN_STATIC_CHECK(sizeof(int8) == 1);
TIAN_STATIC_CHECK(sizeof(int16) == 2);
TIAN_STATIC_CHECK(sizeof(int32) == 4);
TIAN_STATIC_CHECK(sizeof(int64) == 8);

TIAN_STATIC_CHECK(sizeof(uint8) == 1);
TIAN_STATIC_CHECK(sizeof(uint16) == 2);
TIAN_STATIC_CHECK(sizeof(uint32) == 4);
TIAN_STATIC_CHECK(sizeof(uint64) == 8);

#if TIAN_PLATFORM_64BIT
#define TIAN_ALIGNMENT_MINIMUM 8
#else
#define TIAN_ALIGNMENT_MINIMUM 4
#endif