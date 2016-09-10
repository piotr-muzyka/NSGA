#include <unittest++/UnitTest++.h>
#include <GenerationMock.h>
#include <FenotypeMock.h>
#include <CustomAssertion.h>

class GenerationTest
{
public:
    struct ParsedFunctions {
        Functions f;
        Functions g;
        ParsedFunctions() : f(2,2), g(5,2)
        {
            f[0].parse("x1-x2");
            f[1].parse("x1+x2");
        }
    } parsed;
    unsigned generationSize;
    GenerationMock generation;

    GenerationTest()
        : parsed()
        , generationSize(50)
        , generation(generationSize, parsed.f, parsed.g)
    {
    }
};

TEST_FIXTURE(GenerationTest, generationCreation)
{
    CHECK_EQUAL(generationSize, generation.size());
}

TEST_FIXTURE(GenerationTest, produceNextGeneration)
{
    for(int i = 0; i < 100; ++i)
    {
        auto originalFront = generation.getFirstFront();
        generation = generation.produceNextGeneration();
        auto nextFront = generation.getFirstFront();

        CHECK_EQUAL(generationSize, generation.size());
        CHECK_EQUAL(originalFront[0].size(), nextFront[0].size());

        for(unsigned i = 0; i < nextFront.size(); ++i)
            for(unsigned j = 0; j < originalFront.size(); ++j)
                CHECK(nextFront[i][0] <= originalFront[j][0] ||
                      nextFront[i][1] <= originalFront[j][1]);
    }
}

class GenerationWithSubjects : public GenerationTest
{
public:
    SubjectsContainer subjects;
    std::vector<double> x1;
    std::vector<double> x2;

    GenerationWithSubjects()
        : GenerationTest()
        , x1 {
            // Front 1
            0.5, 1, 0.5, 1, -1,
            //Front 2
            10, 9, 8.5,
            // Front 3
            15,
            // Front 4
            40
          }
        , x2 {
            // Front 1
            7.5, 0.5, 1.5, 5, -5,
            //Front 2
            -1, 2, 1,
            // Front 3
            3,
            // Front 4
            0
          }
    {
        std::vector<double> x{0,0};

        subjects.reserve(x1.size());
        std::unique_ptr<FenotypeMock> gen;
        for(unsigned i = 0; i < x1.size(); ++i)
        {
            x[0] = x1[i];
            x[1] = x2[i];
            gen.reset(new FenotypeMock(x,parsed.f,parsed.g));
            subjects.emplace_back(std::make_shared<Subject>(*gen));
        }
    }
};

TEST_FIXTURE(GenerationWithSubjects, reproduction)
{
    GenerationMock generation = GenerationMock(subjects, parsed.f, parsed.g);
    SubjectsContainer offsprings = generation.reproduction(generation.size());
    CHECK_EQUAL(generation.size(), offsprings.size());
        for(auto& offspring : offsprings)
            for(auto& subject : subjects)
                for(unsigned m = 0; m < parsed.f.size(); ++m)
                    CHECK(offspring->rateByF(m) != subject->rateByF(m));
}

class GenerationWithFronts : public GenerationWithSubjects
{
public:
    GenerationMock generation;

    GenerationWithFronts()
        : GenerationWithSubjects(), generation(subjects, parsed.f, parsed.g)
    {
    }
};

TEST_FIXTURE(GenerationWithFronts, returnFirstFront)
{
    std::vector<std::vector<double>> firstFront = generation.getFirstFront();
    CHECK_EQUAL(5, firstFront.size());
    const auto xSize = 2;
    CHECK_EQUAL(parsed.f.size()+xSize, firstFront[0].size());
    // assume that first front is on begining of our subjects vector
    for(unsigned i = 0; i < firstFront.size(); ++i)
        for(unsigned j = 0; j < parsed.f.size(); ++j)
            CHECK_EQUAL(subjects[i]->rateByF(j), firstFront[i][j]);
}

class GenerationWithConstraints : public GenerationWithSubjects
{
public:
    std::unique_ptr<GenerationMock> generation;

    GenerationWithConstraints()
        : GenerationWithSubjects()
    {
        parsed.g[0].parse(parsed.f[0].getExpressionString() + "< 5");
        parsed.g[1].parse(parsed.f[1].getExpressionString() + ">= 1.5");
        parsed.g[2].parse(parsed.f[1].getExpressionString() + "< 10");
        parsed.g[3].parse(parsed.f[0].getExpressionString() + "<" +
                parsed.f[1].getExpressionString());
        parsed.g[4].parse(parsed.f[1].getExpressionString() + ">= -7");

        std::vector<double> x{0,0};
        std::unique_ptr<FenotypeMock> gen;
        subjects.clear();
        for(unsigned i = 0; i < x1.size(); ++i)
        {
            x[0] = x1[i];
            x[1] = x2[i];
            gen.reset(new FenotypeMock(x,parsed.f,parsed.g));
            subjects.emplace_back(std::make_shared<Subject>(*gen));
        }

        generation.reset(new GenerationMock(subjects, parsed.f, parsed.g));
    }

    unsigned countInfeasibleSubjects(const GenerationMock& generation)
    {
        unsigned infeasibleSubjects = 0;
        for(auto& subject : generation.getSubjects())
            if(subject->violatedConstraintsCount() > 0)
                ++infeasibleSubjects;
        return infeasibleSubjects;
    }
};

TEST_FIXTURE(GenerationWithConstraints, checkViolatedConstraints)
{
    CHECK_EQUAL(6, countInfeasibleSubjects(*generation));
    CHECK_EQUAL(0, subjects[0]->violatedConstraintsCount());
    CHECK_EQUAL(0, subjects[1]->violatedConstraintsCount());
    CHECK_EQUAL(0, subjects[2]->violatedConstraintsCount());
    CHECK_EQUAL(0, subjects[3]->violatedConstraintsCount());
    CHECK_EQUAL(2, subjects[4]->violatedConstraintsCount());

    CHECK_EQUAL(2, subjects[5]->violatedConstraintsCount());
    CHECK_EQUAL(2, subjects[6]->violatedConstraintsCount());
    CHECK_EQUAL(1, subjects[7]->violatedConstraintsCount());
    CHECK_EQUAL(2, subjects[8]->violatedConstraintsCount());
    CHECK_EQUAL(3, subjects[9]->violatedConstraintsCount());
}

TEST_FIXTURE(GenerationWithConstraints, infeasibleSubjectsInNextGeneration)
{
    generation.reset(new GenerationMock(generation->produceNextGeneration()));
    for (unsigned i = 0; i < 20; ++i)
    {
        generation.reset(new GenerationMock(generation->produceNextGeneration()));
        CHECK_EQUAL(0, countInfeasibleSubjects(*generation));
    }
}
