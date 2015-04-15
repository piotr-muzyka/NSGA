#ifndef GENERATION_H
#define GENERATION_H

#include <Subject.h>
#include <vector>

class Generation
{
public:
    Generation(unsigned subjectsCount);
    Generation produceNextGeneration();
    void sort();
private:
    std::vector<Subject> subjects;
    void selection(unsigned endSubjectsCount);
};

#endif // GENERATION_H
