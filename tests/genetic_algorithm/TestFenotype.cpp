#include <unittest++/UnitTest++.h>
#include <FenotypeMock.h>

class FenotypeTest
{
public:
    std::vector<double> x;
    Functions f;
    Functions g;
    std::unique_ptr<FenotypeMock> gen;

    FenotypeTest()
        : x{1,2,3,4,5}
        , f(2,5)
        , g(5,5)
    {
        f[0].parse("x1+x2+x3+x4+x5");
        f[1].parse("x1-x2-x3-x4-x5");
        gen.reset(new FenotypeMock(x, f, g));
    }
};

TEST_FIXTURE(FenotypeTest, getGenotype)
{
    std::vector<double> genotype = gen->getGenotype();

    CHECK_EQUAL(1, genotype[0]);
    CHECK_EQUAL(2, genotype[1]);
    CHECK_EQUAL(3, genotype[2]);
    CHECK_EQUAL(4, genotype[3]);
    CHECK_EQUAL(5, genotype[4]);
}

TEST_FIXTURE(FenotypeTest, fenotypeCanCopy)
{
    Fenotype copy(*gen);
}

TEST_FIXTURE(FenotypeTest, childFenotypeCreation)
{
    Fenotype parentA(f,g,-5,5), parentB(f,g,-5,5);
    Fenotype child(parentA, parentB);

    CHECK(!isnan(child.rateByF(0)));
    CHECK(!isnan(child.rateByF(1)));

    CHECK(!isinf(child.rateByF(0)));
    CHECK(!isinf(child.rateByF(1)));

}

class FenotypeWithFValuesTest : public FenotypeTest
{
public:
    const double f1Value;
    const double f2Value;
    FenotypeWithFValuesTest()
     : f1Value(x[0]+x[1]+x[2]+x[3]+x[4])
     , f2Value(x[0]-x[1]-x[2]-x[3]-x[4])
    {}
};

TEST_FIXTURE(FenotypeWithFValuesTest, initialExpressionsCorectness)
{
    CHECK_EQUAL(f1Value, gen->rateByF(0));
    CHECK_EQUAL(f2Value, gen->rateByF(1));
}

TEST_FIXTURE(FenotypeWithFValuesTest, fenotypeIsConstantAfterReparse)
{
    f[0].parse("x1^2+x2^2+x3^2+x4^2+x5^2");
    f[1].parse("sqrt(x1-x2-x3-x4-x5)");
    CHECK_EQUAL(f1Value, gen->rateByF(0));
    CHECK_EQUAL(f2Value, gen->rateByF(1));
}

TEST_FIXTURE(FenotypeWithFValuesTest, fenotypeIsConstantAfterChangingX)
{
    f[0].at("x1") = f[1].at("x5") = 20;
    CHECK_EQUAL(f1Value, gen->rateByF(0));
    CHECK_EQUAL(f2Value, gen->rateByF(1));
}

TEST_FIXTURE(FenotypeWithFValuesTest, violatedConstraintsCount)
{
    CHECK_EQUAL(0, gen->violatedConstraintsCount());
}

class FenotypeWithConstraints : public FenotypeWithFValuesTest
{
public:
    FenotypeWithConstraints()
    {
        g[0].parse("x1+x2+x3 < x4+x5");
        g[1].parse("x3-x4-x5 > x1-x2");
        g[2].parse("x1+x2    == x3");
        g[3].parse("x2+x3    <= x5");
        g[4].parse("x4-x1    >= x5");
        gen.reset(new FenotypeMock(x, f, g));
    }
};

TEST_FIXTURE(FenotypeWithConstraints, violatedConstraintsCount)
{
    CHECK_EQUAL(2, gen->violatedConstraintsCount());
}
