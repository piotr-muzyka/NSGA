#ifndef FENOTYPE_H
#define FENOTYPE_H

#include <Functions.h>
#include <RandomGenerator.h>
#include <memory>
#include <vector>

class Fenotype
{
public:
    Fenotype(Functions& newGoalFunctions, Functions& newConstraints, double genLowerBound,
             double genUpperBound);
    Fenotype(const Fenotype& fenotypeA, const Fenotype& fenotypeB);
    virtual ~Fenotype() {}

    const double& rateByF(const unsigned& function) const;
    std::vector<double> getGenotype() const;
    unsigned violatedConstraintsCount() const;
protected:
    RandomGenerator generator;
    Functions* goalFunctions;
    Functions* constraints;
    std::vector<double> fValue;
    std::vector<double> gValue;
    unsigned violatedConstraints;
    std::vector<double> gen;
    double bounds[2];

    void crossover(const std::vector<double> &genotypeA, const std::vector<double> &genotypeB);
    void mutate();
    void fillWithRandomVariables(std::vector<double>& randomX, double lowerBound,
                                 double upperBound);
    void calculateFunctionsValues();
    void calculateViolatedConstraints();
};

#endif // FENOTYPE_H
