#include <unittest++/UnitTest++.h>
#include <Front.h>
#include <FenotypeMock.h>

class FrontTest
{
public:
    Functions f;
    Functions g;
    Front front;

    FrontTest() : f(2,2), g(2,2), front(f) {}
};

TEST_FIXTURE(FrontTest, copy)
{
    Front copy(front);
}

TEST_FIXTURE(FrontTest, assign)
{
    Front copy = front;
}

TEST_FIXTURE(FrontTest, addSubject)
{
    SubjectPtr individual = std::make_shared<Subject>(f,g,-5,5);
    front.add(individual);
    CHECK_EQUAL(1, front.size());
}

TEST_FIXTURE(FrontTest, createVectorOfFronts)
{
    std::vector<Front> fronts(2, f);
    CHECK_EQUAL(2, fronts.size());
    fronts.resize(1, f);
    CHECK_EQUAL(1, fronts.size());
}

class FrontWithSubjects
{
public:
    SubjectsContainer subjects;
    Functions f;
    Functions g;
    std::vector<double> fMin;
    std::vector<double> fMax;
    Front front;

    FrontWithSubjects() : f(2,2), g(2,2), fMin(2), fMax(2), front(f)
    {
        f[0].parse("x1-x2");
        f[1].parse("x1+x2");

        std::vector<double> x{0,0};
        std::vector<double> x1 = {
            // Front 1
            0.5, 1, 0.5, 1, -1,
            //Front 2
            10, 9, 8.5,
            // Front 3
            15,
            // Front 4
            40
        };
        std::vector<double> x2 = {
            // Front 1
            7.5, 0.5, 1.5, 5, -5,
            //Front 2
            -1, 2, 1,
            // Front 3
            3,
            // Front 4
            0
        };

        subjects.reserve(x1.size());
        std::unique_ptr<FenotypeMock> gen;
        for(unsigned i = 0; i < x1.size(); ++i)
        {
            x[0] = x1[i];
            x[1] = x2[i];
            gen.reset(new FenotypeMock(x,f,g));
            subjects.emplace_back(std::make_shared<Subject>(*gen));
            if(i < 5)
                front.add(subjects[i]);
            for(unsigned m = 0; m < f.size(); ++m)
            {
                if(fMin[m] > subjects[i]->rateByF(m))
                    fMin[m] = subjects[i]->rateByF(m);
                if(fMax[m] < subjects[i]->rateByF(m))
                    fMax[m] = subjects[i]->rateByF(m);
            }
        }
    }
};

TEST_FIXTURE(FrontWithSubjects, crowdingDistanceAssignment)
{
    front.calculateDistances(fMin,fMax);

    const double inf = std::numeric_limits<double>::infinity();

    CHECK_CLOSE(inf, front[0]->getDistance(), 0.01);
    CHECK_CLOSE(0.28, front[1]->getDistance(), 0.01);
    CHECK_CLOSE(0.19, front[2]->getDistance(), 0.01);
    CHECK_CLOSE(0.25, front[3]->getDistance(), 0.01);
    CHECK_CLOSE(inf, front[4]->getDistance(), 0.01);
}
