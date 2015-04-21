#include "Genotype.h"
#include <CustomAssertion.h>
#include <random>
#include <iostream>

using std::cout;

Genotype::Genotype(ExpressionPtr f1, ExpressionPtr f2) : f1Value(0), f2Value(0)
{
    assert(f1->variablesCount() == f2->variablesCount());

    x.resize(f1->variablesCount());
    double LB = -5;
    double UB = 5;
    fillWithRandomVariables(x, LB, UB);
    getFValues(f1, f2, x);

}

Genotype::Genotype(const Genotype &genA, const Genotype &genB)
{
    std::vector<double> fenotypeA = genA.getFenotype();
    std::vector<double> fenotypeB = genB.getFenotype();

    assert(fenotypeA.size() == fenotypeB.size());
    x.resize(fenotypeA.size());
    for(unsigned i = 0; i < fenotypeA.size(); ++i)
    {
        if(fenotypeA[i] < fenotypeB[i])
            x[i] = Genotype::generateRandom(fenotypeA[i], fenotypeB[i]);
        else
            x[i] = Genotype::generateRandom(fenotypeB[i], fenotypeA[i]);

        cout << "x" << i << "=" << x[i] << std::endl;
    }
    mutate();
}

void Genotype::mutate()
{   for(auto& xElem : x)
    {   unsigned i=0;
        xElem += generateRandomN(0,1);
        cout << "xel" << i++ << "=" << xElem << std::endl;
    }
}

double Genotype::rateByF1() const
{
    return f1Value;
}

double Genotype::rateByF2() const
{
    return f2Value;
}

std::vector<double> Genotype::getFenotype() const
{
    return x;
}

double Genotype::generateRandom(double lowerBound, double upperBound)
{
    std::uniform_real_distribution<double> dist(lowerBound, upperBound);
    static std::random_device seed;
    static std::mt19937 randomNumberGenerator(seed());
    return dist(randomNumberGenerator);
}

double Genotype::generateRandomN(double center, double sigma)
{
    std::normal_distribution<double> dist(center, sigma);
    static std::random_device seed;
    static std::mt19937 randomNumberGenerator(seed());
    return dist(randomNumberGenerator);
}

void Genotype::fillWithRandomVariables(std::vector<double>& randomX, double lowerBound, double upperBound)
{
    for(auto& x : randomX)
        x = generateRandom(lowerBound, upperBound);
}

void Genotype::getFValues(ExpressionPtr f1, ExpressionPtr f2, std::vector<double>& variables)
{
    x = variables;
    int i = -1;
    for(auto& key : f1->getAllVariableKeys())
        f1->at(key) = f2->at(key) = x[++i];
    f1Value = f1->value();
    f2Value = f2->value();
}
