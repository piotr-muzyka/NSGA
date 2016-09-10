#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <random>


class RandomGenerator
{
public:
    RandomGenerator();
    double rand(const double &lowerBound, const double &upperBound);
    double randn(const double &center, const double &sigma);
private:
    std::mt19937 randomNumberGenerator;
};

#endif // RANDOMGENERATOR_H
