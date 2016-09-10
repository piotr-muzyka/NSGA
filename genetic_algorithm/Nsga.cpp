#include "Nsga.h"
#include <iostream>

void Nsga::execute(const CoreSettings &settings)
{
    std::cout << "CoreSettings:" << std::endl;
    for(unsigned i = 0; i < settings.f.size(); ++i)
        std::cout << "f"+std::to_string(i)+": " << settings.f[i] << std::endl;
    std::cout << "----------------------" << std::endl;
    for(unsigned i = 0; i < settings.g.size(); ++i)
        std::cout << "g"+std::to_string(i)+": " << settings.g[i] << std::endl;
    std::cout << "----------------------" << std::endl
              << "variables: " << settings.variablesCount << std::endl
              << "individuals: " << settings.individualsCount << std::endl
              << "generations: " << settings.generationsCount << std::endl
              << "lower bound: " << settings.lowerBound << std::endl
              << "upper bound: " << settings.upperBound << std::endl
              << std::endl;

    if(results.size() != settings.f.size())
        results.resize(settings.f.size());

    Functions f(settings.f.size(), settings.variablesCount);
    for(unsigned i = 0; i < settings.f.size(); ++i)
        f[i].parse(settings.f[i]);

    Functions g(settings.g.size(), settings.variablesCount);
    for(unsigned i = 0; i < settings.g.size(); ++i)
        g[i].parse(settings.g[i]);

    population.reset(new Population(settings.individualsCount, f, g, settings.lowerBound,
                        settings.upperBound));
    results = population->generateGenerations(settings.generationsCount);
}

const ResultType& Nsga::result()
{
    return results;
}
