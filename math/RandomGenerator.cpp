#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
    std::random_device seed;
    randomNumberGenerator.seed(seed());
}

double RandomGenerator::rand(const double& lowerBound, const double& upperBound)
{
    std::uniform_real_distribution<double> dist(lowerBound, upperBound);
    return dist(randomNumberGenerator);
}

double RandomGenerator::randn(const double& center, const double& sigma)
{
    std::normal_distribution<double> dist(center,sigma);
    return dist(randomNumberGenerator);
}
