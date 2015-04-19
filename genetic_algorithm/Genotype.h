#ifndef GENOTYPE_H
#define GENOTYPE_H

#include <Expression.h>
#include <memory>
#include <vector>

typedef std::shared_ptr<Expression> ExpressionPtr;

class Genotype
{
public:
    Genotype(ExpressionPtr f1, ExpressionPtr f2);
    Genotype(const Genotype& genA, const Genotype& genB);
    virtual ~Genotype() {}

    void mutate(unsigned mutationProbabilityInPercent);
    double rateByF1() const;
    double rateByF2() const;
    std::vector<double> getRandomVariables(const unsigned& varaiblesCount);
protected:
    double f1Value;
    double f2Value;

    void fillWithRandomVariables(std::vector<double>& randomX);
    void getFValues(ExpressionPtr f1, ExpressionPtr f2, std::vector<double>& x);
};

#endif // GENOTYPE_H
