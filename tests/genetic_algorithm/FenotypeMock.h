#ifndef FENOTYPEMOCK_H
#define FENOTYPEMOCK_H

#include <Fenotype.h>

class FenotypeMock : public Fenotype
{
public:
    FenotypeMock(std::vector<double> x, Functions& goalFunctions, Functions& constraints,
                 double lowerBound = -5, double upperBound = 5)
        : Fenotype(goalFunctions, constraints, lowerBound, upperBound)
    {
        gen = x;
        calculateFunctionsValues();
        calculateViolatedConstraints();
    }
    virtual ~FenotypeMock() {}
};

#endif // FENOTYPEMOCK_H
