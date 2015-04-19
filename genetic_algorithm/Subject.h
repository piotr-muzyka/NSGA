#ifndef SUBJECT_H
#define SUBJECT_H

#include <Genotype.h>

class Subject
{
public:
    Subject(ExpressionPtr newf1, ExpressionPtr newf2);
    Subject(const Subject& parentA, const Subject& parentB);
    virtual ~Subject() {}

    double rateByF1() const;
    double rateByF2() const;
protected:
    Genotype gen;
};

#endif // SUBJECT_H
