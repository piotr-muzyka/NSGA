#include <unittest++/UnitTest++.h>
#include <Population.h>
#include <CustomAssertion.h>

class PopulationTest
{
    ExpressionPtr f1, f2;
public:
    const unsigned subjectsCount;
    AssertSpy assertion;
    Population population;

    PopulationTest()
        : f1(new Expression())
        , f2(new Expression())
        , subjectsCount(50)
        , population(subjectsCount, f1, f2)
    {
        assertion.reset();
    }
};

TEST_FIXTURE(PopulationTest, populationCreation)
{
    CHECK_EQUAL(1, population.generationsCount());
    CHECK_EQUAL(0, assertion.fails());
    CHECK_EQUAL(subjectsCount, population.sizeOfGeneration(1));
    CHECK_EQUAL(0, assertion.fails());
}

TEST_FIXTURE(PopulationTest, generateGenerations)
{
    const unsigned endGenerationsNumber = 5;
    CHECK_EQUAL(0, assertion.fails());
    for (int i = 0; i < 10; ++i)
    {
        population.generateGenerations(endGenerationsNumber);
        CHECK_EQUAL(endGenerationsNumber, population.generationsCount());
    }
    CHECK_EQUAL(0, assertion.fails());
}
