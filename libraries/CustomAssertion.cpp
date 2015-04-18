#include <CustomAssertion.h>

#ifdef UT
#pragma message("UT defined")

unsigned AssertSpy::failedCount = 0;

void assert(bool expression)
{
    if(!expression)
        AssertSpy::failedCount++;
}
#endif
