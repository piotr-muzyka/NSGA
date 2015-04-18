#include "Genotype.h"

Genotype::Genotype(std::vector<double> functVariables, ExpressionPtr f1, ExpressionPtr f2) : f1Value(0), f2Value(0)
{
    std::string key;
    for(int i = 0; i < functVariables.size(); ++i)
    {
        key = "x"+std::to_string(i+1);
        f1->at(key) = f2->at(key) = functVariables[i];
    }
    f1Value = f1->value();
    f2Value = f2->value();
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
