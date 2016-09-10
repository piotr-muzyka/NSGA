#include "Fenotype.h"
#include <CustomAssertion.h>
#include <random>

Fenotype::Fenotype(Functions& newGoalFunctions, Functions& newConstraints, double genLowerBound,
                   double genUpperBound)
    : goalFunctions(&newGoalFunctions)
    , constraints(&newConstraints)
    , fValue(goalFunctions->size(),0)
    , gValue(constraints->size(),0)
    , bounds{genLowerBound, genUpperBound}
{
    assert(goalFunctions->variablesCount() == constraints->variablesCount());

    gen.resize(goalFunctions->at(0).variablesCount());
    fillWithRandomVariables(gen, bounds[0], bounds[1]);
    calculateFunctionsValues();
    calculateViolatedConstraints();
}

Fenotype::Fenotype(const Fenotype &fenotypeA, const Fenotype &fenotypeB)
    : goalFunctions(fenotypeA.goalFunctions)
    , constraints(fenotypeA.constraints)
    , fValue(goalFunctions->size(),0)
    , gValue(constraints->size(),0)
    , bounds{fenotypeA.bounds[0], fenotypeA.bounds[1]}
{
    crossover(fenotypeA.getGenotype(), fenotypeB.getGenotype());
    mutate();
    calculateFunctionsValues();
    calculateViolatedConstraints();
}

void Fenotype::crossover(const std::vector<double>& genotypeA, const std::vector<double>& genotypeB)
{
    assert(genotypeA.size() == genotypeB.size());
    gen.resize(genotypeA.size());

    for(unsigned i = 0; i < genotypeA.size(); ++i)
    {
        if(genotypeA[i] < genotypeB[i])
            gen[i] = generator.rand(genotypeA[i], genotypeB[i]);
        else
            gen[i] = generator.rand(genotypeB[i], genotypeA[i]);
    }
}

void Fenotype::mutate()
{
    double mutation;
    for(auto& xElem : gen)
    {
        mutation = generator.randn(0,1);
        if(xElem + mutation >= bounds[0] && xElem + mutation <= bounds[1])
            xElem += mutation;
    }
}

const double& Fenotype::rateByF(const unsigned& function) const
{
    assert(function < fValue.size());
    return fValue[function];
}

std::vector<double> Fenotype::getGenotype() const
{
    return gen;
}

unsigned Fenotype::violatedConstraintsCount() const
{
    return violatedConstraints;
}

void Fenotype::fillWithRandomVariables(std::vector<double>& randomX, double lowerBound,
                                       double upperBound)
{
    for(auto& x : randomX)
        x = generator.rand(lowerBound, upperBound);
}

void Fenotype::calculateFunctionsValues()
{
    int i = -1;
    for(unsigned m = 0; m < goalFunctions->size(); ++m)
    {
        i = -1;
        for(auto& key : goalFunctions->at(m).getAllVariableKeys())
            goalFunctions->at(m)(key) = gen[++i];
        fValue[m] = goalFunctions->at(m).value();
    }

    for(unsigned m = 0; m < constraints->size(); ++m)
    {
        i = -1;
        for(auto& key : constraints->at(m).getAllVariableKeys())
            constraints->at(m)(key) = gen[++i];
        gValue[m] = constraints->at(m).value();
    }
}

void Fenotype::calculateViolatedConstraints()
{
    violatedConstraints = 0;
    for(auto& constraint : *constraints)
        if(!constraint.isFeasible())
            ++violatedConstraints;
}
