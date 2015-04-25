#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <vector>
using namespace std;

class RandomGenerator
{
public:
    RandomGenerator();
double generateRandom(double lowerBound, double upperBound);
double generateRandomN(double center, double sigma);
std::vector<double> x;
void fillWithRandomVariables(std::vector<double>& randomX, double lowerBound, double upperBound);

private:
    //std::mt19937 &randomNumberGenerator()
//    {
//        thread_local static std::random_device rd;
//        thread_local static std::mt19937 smt(rd());
//        return smt;
//    }

};

#endif // RANDOMGENERATOR_H
