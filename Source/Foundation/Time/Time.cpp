#include "Time.h"
#include <Subsystem/SubSystem.h>

using namespace Foundation;

TIAN_BEGIN_SUBSYSTEM_DECLARATION(Foundation, Time)

ON_BASESYSTEMS_STARTUP {
	Foundation::Time::Initialize();
}

TIAN_END_SUBSYSTEM_DECLARATION;