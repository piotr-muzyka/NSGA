#ifndef CUSTOMASSERTION_H
#define CUSTOMASSERTION_H

#ifndef UT
    #include <assert.h>
#else
    void assert(bool expression);

    class AssertSpy
    {
    public:
        static unsigned failedCount;
        void reset() { failedCount = 0; }
        unsigned fails() { return failedCount; }
    };
#endif

#endif // CUSTOMASSERTION_H
