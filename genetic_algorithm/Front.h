#ifndef FRONT_H
#define FRONT_H

#include <Subject.h>

typedef std::vector<SubjectPtr> SubjectsContainer;

class Front
{
public:
    class iterator;

    Front(const Functions& f);
    void add(SubjectPtr individual);
    const SubjectPtr operator[](const unsigned& subjectId) const;
    SubjectsContainer::iterator begin();
    SubjectsContainer::iterator end();
    unsigned size() const;
    bool empty();
    void calculateDistances(const std::vector<double>& fMin, const std::vector<double>& fMax);
private:
    unsigned fSize;
    SubjectsContainer subjects;

    double calculateDistance(unsigned subjectIndex, const unsigned &goalFunctionIndex,
                             const double &fMin, const double &fMax);
};

#endif // FRONT_H
