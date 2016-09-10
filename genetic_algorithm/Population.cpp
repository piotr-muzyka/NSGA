#include "Population.h"
#include <CustomAssertion.h>

Population::Population(unsigned firstGenerationSize, Functions& newGoalFunctions,
                       Functions &newConstraints, double newLowerBound, double newUpperBound)
    : goalFunctions(&newGoalFunctions)
    , constraints(&newConstraints)
    , lowerBound(newLowerBound)
    , upperBound(newUpperBound)
    , generations(1, Generation(firstGenerationSize, *goalFunctions, *constraints, lowerBound,
                                upperBound))
{
}

std::vector<std::vector<double>> Population::generateGenerations(unsigned generationsCount)
{
    assert(generations.size() >= 1);
    generations.resize(1,
            Generation(sizeOfGeneration(1), *goalFunctions, *constraints, lowerBound, upperBound)
        );
    for (unsigned i = 0; i < generationsCount - 1; ++i)
        generations.push_back(generations[i].produceNextGeneration());
    generations.shrink_to_fit();

    return generations[generations.size() - 1].getFirstFront();
}

unsigned Population::generationsCount()
{
    return generations.size();
}

unsigned Population::sizeOfGeneration(unsigned generationNumber)
{
    assert(generationNumber <= generations.size());
    return generations[generationNumber - 1].size();
}
