#include <unittest++/UnitTest++.h>
#include <Fronts.h>
#include <FenotypeMock.h>

class FrontsTest
{
public:
    struct ParsedFunctions {
        Functions f;
        Functions g;
        ParsedFunctions() : f(2,2), g(2,2)
        {
            f[0].parse("x1-x2");
            f[1].parse("x1+x2");
        }
    } parsed;
    SubjectsContainer subjects;
    Fronts fronts;

    FrontsTest() : fronts(parsed.f) {}
};

TEST_FIXTURE(FrontsTest, creatingFronts)
{
    CHECK_EQUAL(0, fronts.size());

    fronts.add(0, std::make_shared<Subject>(parsed.f, parsed.g, -5, 5));
    fronts.add(0, std::make_shared<Subject>(parsed.f, parsed.g, -5, 5));
    fronts.add(1, std::make_shared<Subject>(parsed.f, parsed.g, -5, 5));

    CHECK_EQUAL(2, fronts.size());
    CHECK_EQUAL(2, fronts[0].size());
    CHECK_EQUAL(1, fronts[1].size());
    CHECK_ASSERT(fronts[2].size());
}

TEST_FIXTURE(FrontsTest, nonDominatedSortWithNoSubjects)
{
    fronts.nonDominatedSort(subjects);
    CHECK_EQUAL(0, fronts.size());
}

class FrontsWithSubjects : public FrontsTest
{
public:
    std::vector<double> x1;
    std::vector<double> x2;

    FrontsWithSubjects() : FrontsTest()
    {
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
            gen.reset(new FenotypeMock(x,parsed.f,parsed.g));
            subjects.emplace_back(std::make_shared<Subject>(*gen));
        }
    }
};

TEST_FIXTURE(FrontsWithSubjects, nonDominatedSortWithOneSubject)
{
    SubjectsContainer oneSubject{subjects[0]};
    fronts.nonDominatedSort(oneSubject);
    CHECK_EQUAL(1, fronts.size());
}

TEST_FIXTURE(FrontsWithSubjects, nonDominatedSortSimpleCase)
{
    fronts.nonDominatedSort(subjects);
    CHECK_EQUAL(4, fronts.size());
    CHECK_EQUAL(5, fronts[0].size());
    CHECK_EQUAL(3, fronts[1].size());
    CHECK_EQUAL(1, fronts[2].size());
    CHECK_EQUAL(1, fronts[3].size());
}

TEST_FIXTURE(FrontsWithSubjects, crowdingDistanceAssigment)
{
    fronts.nonDominatedSort(subjects);
    const unsigned initialSize = subjects.size();

    subjects = fronts.getFirstSubjects(initialSize);
    CHECK_EQUAL(initialSize, subjects.size());

    const double inf = std::numeric_limits<double>::infinity();

    CHECK_CLOSE(inf, subjects[0]->getDistance(), 0.01);
    CHECK_CLOSE(0.28, subjects[1]->getDistance(), 0.01);
    CHECK_CLOSE(0.19, subjects[2]->getDistance(), 0.01);
    CHECK_CLOSE(0.25, subjects[3]->getDistance(), 0.01);
    CHECK_CLOSE(inf, subjects[4]->getDistance(), 0.01);

    CHECK_CLOSE(inf, subjects[5]->getDistance(), 0.01);
    CHECK_CLOSE(0.12, subjects[6]->getDistance(), 0.01);
    CHECK_CLOSE(inf, subjects[7]->getDistance(), 0.01);

    CHECK_CLOSE(inf, subjects[8]->getDistance(), 0.01);

    CHECK_CLOSE(inf, subjects[9]->getDistance(), 0.01);
}

TEST_FIXTURE(FrontsWithSubjects, returnFirstFront)
{
    fronts.nonDominatedSort(subjects);
    std::vector<std::vector<double>> firstFront = fronts.getFirstFront();
    CHECK_EQUAL(5, firstFront.size());
    const auto xSize = 2;
    CHECK_EQUAL(parsed.f.size()+xSize, firstFront[0].size());
    // assume that first front is on begining of our subjects vector
    for(unsigned i = 0; i < firstFront.size(); ++i)
        for(unsigned j = 0; j < parsed.f.size(); ++j)
            CHECK_EQUAL(subjects[i]->rateByF(j), firstFront[i][j]);
}

TEST_FIXTURE(FrontsWithSubjects, getFirstNSubjects)
{
    const double inf = std::numeric_limits<double>::infinity();
    fronts.nonDominatedSort(subjects);
    subjects = fronts.getFirstSubjects(3);
    CHECK_EQUAL(3, subjects.size());
    for(auto& subject : subjects)
        CHECK_EQUAL(1, subject->getRank());
    CHECK_CLOSE(inf, subjects[0]->getDistance(), 0.01);
    CHECK_CLOSE(inf, subjects[1]->getDistance(), 0.01);
    CHECK_CLOSE(0.29, subjects[2]->getDistance(), 0.01);

    subjects = fronts.getFirstSubjects(6);
    CHECK_EQUAL(6, subjects.size());
    for(unsigned i = 0; i < 5; ++i)
        CHECK_EQUAL(1, subjects[i]->getRank());
    CHECK_CLOSE(inf, subjects[0]->getDistance(), 0.01);
    CHECK_CLOSE(0.29, subjects[1]->getDistance(), 0.01);
    CHECK_CLOSE(0.19, subjects[2]->getDistance(), 0.01);
    CHECK_CLOSE(0.25, subjects[3]->getDistance(), 0.01);
    CHECK_CLOSE(inf, subjects[4]->getDistance(), 0.01);

    CHECK_EQUAL(2, subjects[5]->getRank());
    CHECK_CLOSE(inf, subjects[5]->getDistance(), 0.01);
}
