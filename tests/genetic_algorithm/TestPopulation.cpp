#include <unittest++/UnitTest++.h>
#include <Population.h>
#include <CustomAssertion.h>
#include <memory>

class PopulationTest
{
    ExpressionPtr f1, f2;
public:
    AssertSpy assertion;
    std::unique_ptr<Population> population;
    const unsigned subjectsCount = 50;

    PopulationTest() : f1(new Expression(5)), f2(new Expression(5))
    {
        assertion.reset();
        population.reset(new Population(subjectsCount, f1, f2));
    }
};

TEST_FIXTURE(PopulationTest, populationCreation)
{
    CHECK_EQUAL(1, population->generationsCount());
    CHECK_EQUAL(subjectsCount, population->sizeOfGeneration(1));
}

TEST_FIXTURE(PopulationTest, generateGenerations)
{
    const unsigned endGenerationsNumber = 5;
    CHECK_EQUAL(0, assertion.fails());
    for (int i = 0; i < 10; ++i)
    {
        population->generateGenerations(endGenerationsNumber);
        CHECK_EQUAL(endGenerationsNumber, population->generationsCount());
    }
    CHECK_EQUAL(0, assertion.fails());
}
