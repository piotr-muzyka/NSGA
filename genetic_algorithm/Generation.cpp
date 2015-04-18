#include "Generation.h"

Generation::Generation(unsigned subjectsCount, ExpressionPtr newf1, ExpressionPtr newf2)
    : f1(newf1)
    , f2(newf2)
{
    std::vector<double> dummyX{0,0,0,0,0};
    subjects.resize(subjectsCount, Subject(dummyX, f1,f2));
}

Generation Generation::produceNextGeneration()
{
    return Generation(subjects.size(), f1, f2);
}

unsigned Generation::size() const
{
    return subjects.size();
}

void Generation::selection(unsigned)
{
}
