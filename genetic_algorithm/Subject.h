#ifndef SUBJECT_H
#define SUBJECT_H

#include <Genotype.h>

class Subject
{
public:
    Subject();
    Subject(const Subject& parentA, const Subject& parentB);
private:
    Genotype gen;
};

#endif // SUBJECT_H
