#ifndef GENERATION_H
#define GENERATION_H

#include <Subject.h>
#include <vector>

typedef std::shared_ptr<Expression> ExpressionPtr;

class Generation
{
public:
    Generation(unsigned subjectsCount, ExpressionPtr newf1, ExpressionPtr newf2);
    Generation produceNextGeneration();
    void sort();
    unsigned size() const;
private:
    ExpressionPtr f1;
    ExpressionPtr f2;
    std::vector<Subject> subjects;
    void selection(unsigned endSubjectsCount);
};

#endif // GENERATION_H
