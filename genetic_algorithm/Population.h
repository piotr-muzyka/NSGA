#ifndef POPULATION_H
#define POPULATION_H

#include <Generation.h>
#include <vector>

class Population
{
public:
    Population();

    void generateGenerations(int generationNumber);
private:
    std::vector<Generation> generations;
};

#endif // POPULATION_H
