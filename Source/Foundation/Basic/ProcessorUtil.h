#pragma once

#define TIAN_CONCAT(x, y) TIAN_CONCAT_HELPER(x, y)
#define TIAN_CONCAT_HELPER(x, y) TIAN_CONCAT_HELPER2(x, y)
#define TIAN_CONCAT_HELPER2(x, y) x##y

#define EZ_STRING(str) EZ_STRING_HELPER(str)
#define EZ_STRING_HELPER(x) #x

#define EZ_COMPILE_MAX(a, b) ((a) > (b) ? (a) : (b))
#define EZ_COMPILE_MIN(a, b) ((a) < (b) ? (a) : (b))