#ifndef SUBJECT_H
#define SUBJECT_H

#include <Genotype.h>

class Subject
{
public:
    Subject(std::vector<double> functVariables, ExpressionPtr newf1, ExpressionPtr newf2);
    Subject(const Subject& parentA, const Subject& parentB);
    double rateByF1() const;
    double rateByF2() const;
private:
    Genotype gen;
};

#endif // SUBJECT_H
