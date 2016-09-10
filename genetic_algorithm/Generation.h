#ifndef GENERATION_H
#define GENERATION_H

#include <Fronts.h>
#include <vector>

class Generation
{
    static const int matingSize = 30;
    static const int tournamentSize = 5;
public:
    Generation(unsigned subjectsCount, Functions& newGoalFunctions, Functions& newConstraints,
               double lowerBound, double upperBound);
    Generation(SubjectsContainer newSubjects, Functions& newGoalFunctions,
               Functions& newConstraints);
    Generation produceNextGeneration();
    unsigned size() const;
    void addSubject(std::shared_ptr<Subject> subject);
    std::vector<std::vector<double>> getFirstFront();
protected:
    Functions* goalFunctions;
    Functions* constraints;
    std::vector<double> fMax;
    std::vector<double> fMin;
    SubjectsContainer subjects;

    Fronts fronts;

    Generation fitFrontsToNextGeneration(const unsigned subjectsCount);
    SubjectsContainer reproduction (unsigned subjectsCount);
    SubjectsContainer createOffspringsFromPool(unsigned subjectsCount,
                                               SubjectsContainer matingPool);
    SubjectsContainer createMatingPool();
    std::shared_ptr<Subject> findBestContestant(SubjectsContainer tournamentPool);
    SubjectsContainer createTournamentPool();
};

#endif // GENERATION_H
