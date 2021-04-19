#pragma once

#define TIAN_FORCE_INLINE __forceinline

#ifdef __INTELLISENSE__
#define TIAN_INLINE inline
#else
#define TIAN_INLINE __forceinline
#endif

#ifdef __INTELLISENSE__
#define TIAN_ALIGN(decl, alignment) decl
#define TIAN_ALIGN_VARIABLE(decl, alignment) decl
#else
#define TIAN_ALIGN(decl, alignment) __declspec(align(alignment)) decl
#define TIAN_ALIGN_VARIABLE(decl, alignment) __declspec(align(alignment)) decl
#endif