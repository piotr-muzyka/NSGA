#include "Front.h"
#include <CustomAssertion.h>

Front::Front(const Functions &f) : fSize(f.size())
{
}

void Front::add(SubjectPtr individual)
{
    subjects.push_back(individual);
}

const SubjectPtr Front::operator[](const unsigned &subjectId) const
{
    assert(subjectId < subjects.size());
    assert(subjects[subjectId] != NULL);
    return subjects[subjectId];
}

SubjectsContainer::iterator Front::begin()
{
    return subjects.begin();
}

SubjectsContainer::iterator Front::end()
{
    return subjects.end();
}

unsigned Front::size() const
{
    return subjects.size();
}

bool Front::empty()
{
    return subjects.empty();
}

void Front::calculateDistances(const std::vector<double> &fMin, const std::vector<double> &fMax)
{
    assert(subjects.size() > 0);

    const double infinity = std::numeric_limits<double>::infinity();

    for(unsigned m = 0; m < fSize; ++m)
    {
        std::sort(subjects.begin(), subjects.end(),
            [m](const SubjectPtr a, const SubjectPtr b){ return a->rateByF(m) < b->rateByF(m); });
        subjects[0]->setDistance(infinity);
        subjects[subjects.size()-1]->setDistance(infinity);

        for(unsigned k = 1; k < subjects.size()-1; ++k)
        {
            if (m == 0)
                subjects[k]->setDistance(0);
            subjects[k]->setDistance(calculateDistance(k, m, fMin[m], fMax[m]));
        }
    }
}

double Front::calculateDistance(unsigned subjectIndex, const unsigned& goalFunctionIndex,
    const double& fMin, const double& fMax)
{
    return subjects[subjectIndex]->getDistance()+
            (
                subjects[subjectIndex+1]->rateByF(goalFunctionIndex)-
                subjects[subjectIndex-1]->rateByF(goalFunctionIndex)
            )/
            (fMax-fMin);
}
