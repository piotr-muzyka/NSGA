#include "Subject.h"

Subject::Subject(const Fenotype &newGen)
    : distance(0)
    , rank(0)
    , gen(newGen)
{
}

Subject::Subject(Functions& goalFunctions, Functions &newConstraints, double lowerBound,
                 double upperBound)
    : distance(0)
    , rank(0)
    , gen(goalFunctions, newConstraints, lowerBound, upperBound)
{
}

Subject::Subject(const Subject &parentA, const Subject &parentB)
    : distance(0)
    , rank(0)
    , gen(parentA.gen, parentB.gen)
{
}

const double& Subject::rateByF(const unsigned& function) const
{
    return gen.rateByF(function);
}

unsigned Subject::violatedConstraintsCount() const
{
    return gen.violatedConstraintsCount();
}

const unsigned &Subject::getRank() const
{
    return rank;
}

const double &Subject::getDistance() const
{
    return distance;
}


void Subject::setRank(const unsigned &newRank)
{
    rank = newRank;
}

void Subject::setDistance(const double &newDistance)
{
    distance = newDistance;
}

void Subject::checkDomination(SubjectPtr q)
{
    if(q->isDominatedBy(*this))
        dominatedSubjects.emplace_back(q);
    else if (isDominatedBy(*q))
        dominantsCount += 1;
}

bool Subject::isDominatedBy(const Subject &s) const
{
    if(violatedConstraintsCount() != s.violatedConstraintsCount())
        return s.violatedConstraintsCount() < violatedConstraintsCount();

    bool isDominatedWithRespectToF1 = (s.rateByF(0) < rateByF(0)) && (s.rateByF(1) <= rateByF(1));
    bool isDominatedWithRespectToF2 = (s.rateByF(1) < rateByF(1)) && (s.rateByF(0) <= rateByF(0));
    return isDominatedWithRespectToF1 || isDominatedWithRespectToF2;
}

bool Subject::operator<(const Subject &r) const
{
    if(violatedConstraintsCount() != r.violatedConstraintsCount())
        return violatedConstraintsCount() < r.violatedConstraintsCount();

    if(rank == r.rank)
        return distance > r.distance;
    else
        return rank < r.rank;
}

const Fenotype &Subject::getGen() const
{
    return gen;
}

