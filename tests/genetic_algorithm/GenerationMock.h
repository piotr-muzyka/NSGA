#ifndef GENERATIONMOCK_H
#define GENERATIONMOCK_H

#include <Generation.h>

class GenerationMock : public Generation
{
public:
    GenerationMock(unsigned& subjectsCount, Functions& goalFunctions, Functions& constraints)
        : Generation(subjectsCount, goalFunctions, constraints, -5, 5)
    {
    }

    GenerationMock(SubjectsContainer subjects, Functions& goalFunctions, Functions& constraints)
        : Generation(subjects, goalFunctions, constraints)
    {
    }

    GenerationMock(const Generation& other)
        : Generation(other)
    {
    }

    const SubjectsContainer& getSubjects() const
    {
        return subjects;
    }

    const Fronts& getFronts() const
    {
        return fronts;
    }

    // Change function visibility for testing purposes
    using Generation::reproduction;
};

#endif // GENERATIONMOCK_H
