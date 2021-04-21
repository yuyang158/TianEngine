#include <Basic/Assert.h>
#include <windows.h>

using namespace Foundation;

int32 AssertHelper::DoAssert(const char* pExpression,
	const char* pFile,
	int line,
	const char* pFunction,
	const char* pMessage) {
	MessageBox(NULL);
}
