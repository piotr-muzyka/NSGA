#include <unittest++/UnitTest++.h>
#include <Population.h>
#include <CustomAssertion.h>

class PopulationTest
{
    Functions f;
    Functions g;
public:
    const unsigned subjectsCount = 50;
    std::unique_ptr<Population> population;

    PopulationTest()
        : f(2,5)
        , g(5,5)
    {
        f[0].parse("x1+x2");
        f[1].parse("x1-x2");
        population.reset(new Population(subjectsCount, f, g));
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
    for (int i = 0; i < 10; ++i)
    {
        population->generateGenerations(endGenerationsNumber);
        CHECK_EQUAL(endGenerationsNumber, population->generationsCount());
    }
}

