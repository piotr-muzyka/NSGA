#include <unittest++/UnitTest++.h>
#include <Subject.h>

class SubjectTest
{
public:
    std::vector<double> x;
    ExpressionPtr f1, f2;

    SubjectTest()
        : x{1,2,3,4,5}
        , f1(new Expression(5))
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
