#include "Generation.h"
#include "CustomAssertion.h"

Generation::Generation(unsigned subjectsCount, Functions& newGoalFunctions,
                       Functions& newConstraints, double lowerBound, double upperBound)
    : goalFunctions(&newGoalFunctions)
    , constraints(&newConstraints)
    , fMax(newGoalFunctions.size(), std::numeric_limits<double>::min())
    , fMin(newGoalFunctions.size(), std::numeric_limits<double>::infinity())
    , fronts(newGoalFunctions)
{
    for(unsigned i = 0; i < subjectsCount; ++i)
        subjects.push_back(
                std::make_shared<Subject>(*goalFunctions, *constraints, lowerBound, upperBound)
            );
}

Generation::Generation(SubjectsContainer newSubjects, Functions& newGoalFunctions,
                       Functions &newConstraints)
    : goalFunctions(&newGoalFunctions)
    , constraints(&newConstraints)
    , fMax(newGoalFunctions.size(), std::numeric_limits<double>::min())
    , fMin(newGoalFunctions.size(), std::numeric_limits<double>::infinity())
    , subjects(newSubjects)
    , fronts(newGoalFunctions)
{
}

Generation Generation::produceNextGeneration()
{
    const unsigned subjectsCount = subjects.size();
    SubjectsContainer offsprings = reproduction(subjects.size());
    subjects.insert(subjects.end(), offsprings.begin(), offsprings.end());
    assert(subjects.size() == 2*subjectsCount);

    fronts.nonDominatedSort(subjects);
    subjects.resize(subjectsCount);
    assert(fronts.size() > 0);

    return fitFrontsToNextGeneration(subjectsCount);
}

Generation Generation::fitFrontsToNextGeneration(const unsigned subjectsCount)
{
    Generation nextGeneration(fronts.getFirstSubjects(subjectsCount), *goalFunctions, *constraints);
    return nextGeneration;
}

void Generation::addSubject(std::shared_ptr<Subject> subject)
{
    subjects.emplace_back(subject);
}

unsigned Generation::size() const
{
    return subjects.size();
}

SubjectsContainer Generation::reproduction(unsigned subjectsCount)
{
    SubjectsContainer matingPool = createMatingPool();
    return createOffspringsFromPool(subjectsCount, matingPool);
}

std::vector<std::vector<double>> Generation::getFirstFront()
{
    if(fronts.size() <= 0)
        fronts.nonDominatedSort(subjects);
    assert(fronts.size() > 0);
    return fronts.getFirstFront();
}

SubjectsContainer Generation::createMatingPool()
{
    SubjectsContainer matingPool;

    while(matingPool.size() < matingSize)
    {
        SubjectsContainer tournamentPool = createTournamentPool();
        std::shared_ptr<Subject> bestContestant = findBestContestant(tournamentPool);
        matingPool.emplace_back(bestContestant);
    }
    return matingPool;
}

SubjectsContainer Generation::createTournamentPool()
{
    RandomGenerator generator;
    SubjectsContainer tournamentPool;
    std::vector<bool> usedSubjects(subjects.size(),false);
    int contestant;

    while(tournamentPool.size() < tournamentSize)
    {
        contestant = generator.rand(0,subjects.size());
        if(!usedSubjects[contestant])
        {
            tournamentPool.emplace_back(subjects[contestant]);
            usedSubjects[contestant] = true;
        }
    }

    return tournamentPool;
}

std::shared_ptr<Subject> Generation::findBestContestant(SubjectsContainer tournamentPool)
{
    std::shared_ptr<Subject> bestContestant = tournamentPool[0];
    for(auto& subject : tournamentPool)
        if(*subject < *bestContestant)
            bestContestant = subject;

    return bestContestant;
}

SubjectsContainer Generation::createOffspringsFromPool(unsigned subjectsCount,
                                                       SubjectsContainer matingPool)
{
    RandomGenerator generator;

    unsigned parentA;
    unsigned parentB;
    SubjectsContainer offsprings;
    while(offsprings.size() < subjectsCount)
    {
        parentA = parentB = generator.rand(0,matingPool.size());
        while(parentA == parentB)
            parentB = generator.rand(0,matingPool.size());
        offsprings.push_back(std::make_shared<Subject>(*matingPool[parentA],*matingPool[parentB]));
    }

    return offsprings;
}
