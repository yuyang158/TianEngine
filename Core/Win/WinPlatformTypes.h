#pragma once

#include "GenericPlatformTypes.h"

struct WinPlatformTypes : public GenericPlatformTypes {
	typedef unsigned __int64 SIZE_T;
};

typedef WinPlatformTypes PlatformTypes;