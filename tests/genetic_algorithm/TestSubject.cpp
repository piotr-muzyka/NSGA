#include <unittest++/UnitTest++.h>
#include <Subject.h>

class SubjectTest
{
public:
    ExpressionPtr f1, f2;

    SubjectTest()
        : f1(new Expression(5))
        , f2(new Expression(5))
    {
    }
};

TEST_FIXTURE(SubjectTest, subjectCanCopy)
{
    Subject original(f1, f2);
    Subject copy(original);
}

TEST_FIXTURE(SubjectTest, childSubjectCreation)
{
    Subject parentA(f1, f2), parentB(f1, f2);
    Subject child(parentA, parentB);
}
