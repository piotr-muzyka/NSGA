#include <unittest++/UnitTest++.h>
#include <Subject.h>

class SubjectTest
{
public:
    std::vector<double> x;
    ExpressionPtr f1, f2;
    std::unique_ptr<Subject> subject;

    SubjectTest()
        : x{1,2,3,4,5}
        , f1(new Expression(5))
        , f2(new Expression(5))
    {
        f1->parse("x1+x2+x3+x4+x5");
        f2->parse("x1-x2-x3-x4-x5");
        subject.reset(new Subject(x,f1,f2));
    }
};

TEST_FIXTURE(SubjectTest, subjectCanCopy)
{
    Subject original(x, f1, f2);
    Subject copy(original);
}

TEST_FIXTURE(SubjectTest, childSubjectCreation)
{
    Subject parentA(x, f1, f2), parentB(x, f1, f2);
    Subject child(parentA, parentB);
}

class SubjectWithFValuesTest : public SubjectTest
{
public:
    const double f1Value;
    const double f2Value;
    SubjectWithFValuesTest()
     : f1Value(x[0]+x[1]+x[2]+x[3]+x[4])
     , f2Value(x[0]-x[1]-x[2]-x[3]-x[4])
    {}
};

TEST_FIXTURE(SubjectWithFValuesTest, initialExpressionsCorectness)
{
    CHECK_EQUAL(f1Value, subject->rateByF1());
    CHECK_EQUAL(f2Value, subject->rateByF2());
}

TEST_FIXTURE(SubjectWithFValuesTest, subjectIsConstantAfterReparse)
{
    f1->parse("x1^2+x2^2+x3^2+x4^2+x5^2");
    f2->parse("sqrt(x1-x2-x3-x4-x5)");
    CHECK_EQUAL(f1Value, subject->rateByF1());
    CHECK_EQUAL(f2Value, subject->rateByF2());
}

TEST_FIXTURE(SubjectWithFValuesTest, subjectIsConstantAfterChangingX)
{
    f1->at("x1") = f2->at("x5") = 20;
    CHECK_EQUAL(f1Value, subject->rateByF1());
    CHECK_EQUAL(f2Value, subject->rateByF2());
}
