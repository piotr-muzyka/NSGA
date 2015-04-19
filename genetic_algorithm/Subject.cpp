#include "Subject.h"

Subject::Subject(ExpressionPtr newf1, ExpressionPtr newf2)
    : gen(newf1, newf2)
{
}

Subject::Subject(const Subject &parentA, const Subject &parentB) : gen(parentA.gen, parentB.gen)
{
}

double Subject::rateByF1() const
{
    return gen.rateByF1();
}

double Subject::rateByF2() const
{
    return gen.rateByF2();
}
