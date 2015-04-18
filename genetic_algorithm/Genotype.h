#ifndef GENOTYPE_H
#define GENOTYPE_H

#include <Expression.h>
#include <memory>
#include <vector>

typedef std::shared_ptr<Expression> ExpressionPtr;

class Genotype
{
public:
    Genotype(std::vector<double> functVariables, ExpressionPtr f1, ExpressionPtr f2);
    Genotype(const Genotype& genA, const Genotype& genB);

    void mutate(unsigned mutationProbabilityInPercent);
    double rateByF1() const;
    double rateByF2() const;
private:
    double f1Value;
    double f2Value;
};

#endif // GENOTYPE_H
