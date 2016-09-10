#ifndef SUBJECT_H
#define SUBJECT_H

#include <Fenotype.h>
#include <list>

class Subject;
typedef std::shared_ptr<Subject> SubjectPtr;

class Subject
{
public:
    Subject(const Fenotype& newGen);
    Subject(Functions& goalFunctions, Functions &newConstraints, double lowerBound,
            double upperBound);
    Subject(const Subject& parentA, const Subject& parentB);
    virtual ~Subject() {}

    const double& rateByF(const unsigned& function) const;
    unsigned violatedConstraintsCount() const;
    void checkDomination(SubjectPtr q);
    bool isDominatedBy(const Subject& s) const;
    bool operator<(const Subject& r) const; // Crowded distance operator

    const Fenotype& getGen() const;
    const unsigned& getRank() const;
    const double& getDistance() const;
    void setRank(const unsigned& newRank);
    void setDistance(const double& newDistance);

    int dominantsCount;
    std::list<SubjectPtr> dominatedSubjects;
private:
    double distance;
    unsigned rank;
    Fenotype gen;
};

#endif // SUBJECT_H
