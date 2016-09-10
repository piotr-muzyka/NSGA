#ifndef NSGA_H
#define NSGA_H

#include <Core.h>
#include <Population.h>
#include <memory>

typedef std::vector<std::vector<double>> ResultType;

struct CoreSettings
{
    CoreSettings(unsigned firstGenerationSize = 50, unsigned newGenerationsCount = 5,
                 unsigned fSize = 2, unsigned gSize = 6, unsigned newVariableCount = 5)
        : f(fSize)
        , g(gSize)
        , individualsCount(firstGenerationSize)
        , generationsCount(newGenerationsCount)
        , variablesCount(newVariableCount)
        , lowerBound(-5)
        , upperBound(5)
    {
    }

    std::vector<std::string> f;
    std::vector<std::string> g;
    unsigned individualsCount;
    unsigned generationsCount;
    unsigned variablesCount;
    double lowerBound;
    double upperBound;
};



class Nsga : public Core<ResultType>
{
public:
    void execute(const CoreSettings& settings);
    const ResultType& result();
private:
    ResultType results;
    std::unique_ptr<Population> population;
};

#endif // NSGA_H
