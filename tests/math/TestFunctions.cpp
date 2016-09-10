#include <unittest++/UnitTest++.h>
#include <Functions.h>

TEST(goalFunctionsInitialization)
{
    Functions f(2,5);
    CHECK_EQUAL(2, f.size());
    CHECK_EQUAL(5, f[0].variablesCount());
    CHECK_EQUAL(5, f[1].variablesCount());
}


TEST(goalFunctionsInitializationList)
{
    Expression f1(3), f2(3), f3(3), f4(3);
    Functions f{f1,f2,f3,f4};
    CHECK_EQUAL(4, f.size());
    CHECK_EQUAL(3, f[0].variablesCount());
    CHECK_EQUAL(3, f[1].variablesCount());
    CHECK_EQUAL(3, f[2].variablesCount());
    CHECK_EQUAL(3, f[3].variablesCount());
}

TEST(passGoalFunctions)
{
    Expression f1(1);
    Expression& f1ref = f1;

    Functions f{f1ref};
    CHECK_EQUAL(1, f.size());
    CHECK_EQUAL(1, f[0].variablesCount());

    Functions& fRef(f);
    CHECK_EQUAL(1, fRef.size());
    CHECK_EQUAL(1, fRef[0].variablesCount());
}
