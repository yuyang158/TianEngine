#pragma once

#define TIAN_CONCAT(x, y) TIAN_CONCAT_HELPER(x, y)
#define TIAN_CONCAT_HELPER(x, y) TIAN_CONCAT_HELPER2(x, y)
#define TIAN_CONCAT_HELPER2(x, y) x##y

#define TIAN_STRING(str) TIAN_STRING_HELPER(str)
#define TIAN_STRING_HELPER(x) #x

#define TIAN_COMPILE_MAX(a, b) ((a) > (b) ? (a) : (b))
#define TIAN_COMPILE_MIN(a, b) ((a) < (b) ? (a) : (b))