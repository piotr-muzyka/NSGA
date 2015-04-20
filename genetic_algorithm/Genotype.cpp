#include "Genotype.h"
#include <CustomAssertion.h>
#include <random>


Genotype::Genotype(ExpressionPtr f1, ExpressionPtr f2) : f1Value(0), f2Value(0)
{
    assert(f1->variablesCount() == f2->variablesCount());

    std::vector<double> x(f1->variablesCount());
    fillWithRandomVariables(x);
    getFValues(f1, f2, x);
}

Genotype::Genotype(const Genotype &genA, const Genotype &genB)
{
}

void Genotype::mutate(unsigned mutationProbabilityInPercent)
{
}

double Genotype::rateByF1() const
{
    return f1Value;
}

double Genotype::rateByF2() const
{
    return f2Value;
}

void Genotype::fillWithRandomVariables(std::vector<double>& randomX)
{
    std::cauchy_distribution<double> dist(-10, 10);
    std::random_device seed;
    std::mt19937 randomNumberGenerator(seed());

    for(auto& x : randomX)
        x = dist(randomNumberGenerator);
}

void Genotype::getFValues(ExpressionPtr f1, ExpressionPtr f2, std::vector<double>& x)
{
    int i = -1;
    for(auto& key : f1->getAllVariableKeys())
        f1->at(key) = f2->at(key) = x[++i];
    f1Value = f1->value();
    f2Value = f2->value();
}
