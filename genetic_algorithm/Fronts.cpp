#include "Fronts.h"
#include <CustomAssertion.h>

Fronts::Fronts(Functions& newf)
    : f(&newf)
    , fMax(newf.size(), std::numeric_limits<double>::min())
    , fMin(newf.size(), std::numeric_limits<double>::infinity())
{
}

void Fronts::add(const unsigned &frontNumber, SubjectPtr subject)
{
    if(fronts.size() <= frontNumber)
        fronts.emplace_back(*f);
    assert(fronts.size() > frontNumber);
    subject->setRank(frontNumber + 1);
    fronts[frontNumber].add(subject);
}

const Front Fronts::operator[](const unsigned &frontId) const
{
    assert(frontId < fronts.size());
    return fronts[frontId];
}

unsigned Fronts::size() const
{
    return fronts.size();
}

void Fronts::nonDominatedSort(const SubjectsContainer &subjects)
{
    fronts.clear();
    if(subjects.size() > 0)
    {
        for(auto& subject : subjects)
        {
            subject->dominatedSubjects.clear();
            subject->dominantsCount = 0;
        }

        createFirstFront(subjects);
        fillOtherFronts();

        if(fronts[fronts.size()-1].empty())
            fronts.pop_back();
    }
}

SubjectsContainer Fronts::getFirstSubjects(unsigned subjectsCount)
{
    SubjectsContainer subjects;
    unsigned i = 0;
    for(i = 0; i < fronts.size(); ++i)
    {
        fronts[i].calculateDistances(fMin, fMax);
        if((subjects.size() + fronts[i].size()) > subjectsCount)
            break;

        for(auto& subject : fronts[i])
            subjects.emplace_back(subject);
    }
    std::sort(fronts[i].begin(), fronts[i].end(),
              [](const SubjectPtr a, const SubjectPtr b){ return *a < *b; });
    for(unsigned j = 0; subjects.size() < subjectsCount; ++j)
        subjects.emplace_back(fronts[i][j]);
    assert(subjects.size() == subjectsCount);

    return subjects;
}

std::vector<std::vector<double>> Fronts::getFirstFront()
{
    assert(fronts.size() > 0);
    std::vector<std::vector<double>> firstFront(fronts[0].size(),
            std::vector<double>(f->size()+fronts[0][0]->getGen().getGenotype().size()));
    for(unsigned i = 0; i < fronts[0].size(); ++i)
    {
        for(unsigned j = 0; j < f->size(); ++j)
            firstFront[i][j] = fronts[0][i]->rateByF(j);
        for(unsigned j = 0; j < fronts[0][i]->getGen().getGenotype().size(); ++j)
            firstFront[i][f->size()+j] = fronts[0][i]->getGen().getGenotype()[j];
    }
    return firstFront;
}

void Fronts::createFirstFront(const SubjectsContainer &subjects)
{
    for(auto& p : subjects)
    {
        for(auto& q : subjects)
            p->checkDomination(q);

        if(p->dominantsCount == 0)
            add(0, p);

        for(unsigned m = 0; m < f->size(); ++m)
            updateMinMax(*p, m);
    }
}

void Fronts::fillOtherFronts()
{
    for(unsigned n = 0; !fronts[n].empty(); ++n)
    {
        fronts.emplace_back(*f);
        for(auto& p : fronts[n])
        {
            for(auto& q : p->dominatedSubjects)
            {
                q->dominantsCount -= 1;
                assert(q->dominantsCount >= 0);
                if (q->dominantsCount == 0)
                    add(n+1, q);
            }
        }
    }
}

void Fronts::updateMinMax(const Subject &subject, const unsigned &goalFunctionIndex)
{
    double tmpFValue = 0;
    tmpFValue = subject.rateByF(goalFunctionIndex);
    if (fMax[goalFunctionIndex] < tmpFValue)
        fMax[goalFunctionIndex] = tmpFValue;
    if (fMin[goalFunctionIndex] > tmpFValue)
        fMin[goalFunctionIndex] = tmpFValue;
}
