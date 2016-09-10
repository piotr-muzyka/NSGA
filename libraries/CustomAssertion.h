#ifndef CUSTOMASSERTION_H
#define CUSTOMASSERTION_H

#ifndef UT
    #include <assert.h>
#else
    #include <unittest++/UnitTest++.h>

    # define assert(EX) (void)((EX) || (_assert(#EX, __FILE__, __LINE__),0))
    inline void _assert(const char *msg, const char *file, int line)
    {
        throw UnitTest::AssertException(msg,file,line);
    }
#endif

#endif // CUSTOMASSERTION_H
