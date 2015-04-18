#ifndef POPULATION_H
#define POPULATION_H

#include <Generation.h>

class Population
{
public:
    Population(unsigned firstGenerationSize, ExpressionPtr newf1, ExpressionPtr newf2);

    void generateGenerations(unsigned generationsCount);
    unsigned generationsCount();
    unsigned sizeOfGeneration(unsigned generationNumber);
private:
    ExpressionPtr f1;
    ExpressionPtr f2;
    std::vector<Generation> generations;
};

#endif // POPULATION_H
