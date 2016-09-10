#ifndef FRONTS_H
#define FRONTS_H

#include <Front.h>

class Fronts
{
public:
    Fronts(Functions &newf);
    void add(const unsigned &frontNumber, SubjectPtr subject);
    const Front operator[](const unsigned& frontId) const;
    unsigned size() const;

    void nonDominatedSort(const SubjectsContainer& subjects);
    SubjectsContainer getFirstSubjects(unsigned subjectsCount);
    std::vector<std::vector<double>> getFirstFront();
protected:
    Functions* f;
    std::vector<double> fMax;
    std::vector<double> fMin;
    std::vector<Front> fronts;

    void createFirstFront(const SubjectsContainer &subjects);
    void fillOtherFronts();
    void updateMinMax(const Subject &subject, const unsigned &goalFunctionIndex);
};

#endif // FRONTS_H
