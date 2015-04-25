#include "RandomGenerator.h"
#include <random>

RandomGenerator::RandomGenerator()
{
   //void fillWithRandomVariables(std::vector<double>& randomX, double lowerBound, double upperBound);
   //::random_device randdev();
   //std::mt19937 randomNumberGenerator();
   double LB = -5;
   double UB = 5;
   fillWithRandomVariables(x, LB, UB);

}


//RandomGenerator::~RandomGenerator()
//{

//}


double RandomGenerator::generateRandom(double lowerBound, double upperBound)
{
    std::uniform_real_distribution<double> dist(lowerBound, upperBound);
    std::random_device seed;
    std::mt19937 randomNumberGenerator(seed());
    return dist(randomNumberGenerator);
}


double RandomGenerator::generateRandomN(double center, double sigma)
{
    std::normal_distribution<double> dist(center, sigma);
    std::random_device seed;
    std::mt19937 randomNumberGenerator(seed());
    return dist(randomNumberGenerator);
}

void RandomGenerator::fillWithRandomVariables(std::vector<double>& randomX, double lowerBound, double upperBound)
{
    for(auto& x : randomX)
        x = generateRandom(lowerBound, upperBound);
}





