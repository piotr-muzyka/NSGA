#include <unittest++/UnitTest++.h>
#include <Subject.h>
#include <FenotypeMock.h>
#include <memory>
#include <limits>

class SubjectTest
{
public:
    Functions f;
    Functions g;
    Subject individual;

    SubjectTest()
        : f(2,5)
        , g(5,5)
        , individual(f,g,-5,5)
    {
    }
};

TEST_FIXTURE(SubjectTest, subjectCanCopy)
{
    Subject copy(individual);
}

TEST_FIXTURE(SubjectTest, childSubjectCreation)
{
    Subject parentA(individual), parentB(individual);
    Subject child(parentA, parentB);
}

TEST_FIXTURE(SubjectTest, setAndGetDistance)
{
    CHECK_CLOSE(0, individual.getDistance(), 0.01);
    individual.setDistance(1);
    CHECK_CLOSE(1, individual.getDistance(), 0.01);

    const double infinity = std::numeric_limits<double>::infinity();
    individual.setDistance(infinity);
    CHECK_CLOSE(infinity, individual.getDistance(), 0.01);
}

TEST_FIXTURE(SubjectTest, crowdedComparisonOperator)
{
    Subject A(individual);
    Subject B(individual);
    Subject C(individual);
    A.setRank(5);
    B.setRank(7);
    B.setDistance(10);
    C.setRank(7);
    C.setDistance(std::numeric_limits<unsigned>::max());

    CHECK(A < B);
    CHECK(C < B);
    CHECK(A < C);
}

class SubjectDominationTest : public SubjectTest
{
public:
    std::vector<double> x1;
    std::vector<double> x2;
    std::shared_ptr<Subject> A;
    std::shared_ptr<Subject> B;
    std::shared_ptr<Subject> C;
    std::shared_ptr<Subject> D;
    std::shared_ptr<Subject> E;

    SubjectDominationTest() : x1{1,0.5,0,1,-1}, x2{1,1.5,0,5,-5}
    {
        f[0].parse("x1-x2");
        f[1].parse("x1+x2");

        std::vector<double> x{1,1,0,0,0};
        std::vector<std::shared_ptr<Subject>> subjects(5);
        std::unique_ptr<FenotypeMock> gen;

        for (unsigned i = 0; i < x1.size(); ++i)
        {
            x[0] = x1[i];
            x[1] = x2[i];
            gen.reset(new FenotypeMock(x,f,g));
            subjects[i].reset(new Subject(*gen));
        }
        A = subjects[0];
        B = subjects[1];
        C = subjects[2];
        D = subjects[3];
        E = subjects[4];
    }
};

TEST_FIXTURE(SubjectDominationTest, properSubjectsCreation)
{
    CHECK(A.get() != NULL);
    CHECK(B.get() != NULL);
    CHECK(C.get() != NULL);
    CHECK(D.get() != NULL);
    CHECK(E.get() != NULL);

    CHECK_EQUAL(0, A->rateByF(0));
    CHECK_EQUAL(2, A->rateByF(1));

    CHECK_EQUAL(-1, B->rateByF(0));
    CHECK_EQUAL(2, B->rateByF(1));

    CHECK_EQUAL(0, C->rateByF(0));
    CHECK_EQUAL(0, C->rateByF(1));

    CHECK_EQUAL(-4, D->rateByF(0));
    CHECK_EQUAL(6, D->rateByF(1));

    CHECK_EQUAL(4, E->rateByF(0));
    CHECK_EQUAL(-6, E->rateByF(1));
}

TEST_FIXTURE(SubjectDominationTest, domination)
{
    CHECK(!A->isDominatedBy(*A));
    CHECK(A->isDominatedBy(*B));
    CHECK(A->isDominatedBy(*C));
    CHECK(!A->isDominatedBy(*D));
    CHECK(!A->isDominatedBy(*E));
}

class SubjectWithConstraints : public SubjectDominationTest
{
public:
    SubjectWithConstraints() : SubjectDominationTest()
    {
        f[0].parse("x1-x2");
        f[1].parse("x1+x2");

        g[0].parse(f[0].getExpressionString() + ">= 0");
        g[1].parse(f[1].getExpressionString() + "< 6");
        g[2].parse(f[1].getExpressionString() + "> -1");

        std::vector<double> x{1,1,0,0,0};
        std::vector<std::shared_ptr<Subject>> subjects(5);
        std::unique_ptr<FenotypeMock> gen;

        for (unsigned i = 0; i < x1.size(); ++i)
        {
            x[0] = x1[i];
            x[1] = x2[i];
            gen.reset(new FenotypeMock(x,f,g));
            subjects[i].reset(new Subject(*gen));
        }
        A = subjects[0];
        B = subjects[1];
        C = subjects[2];
        D = subjects[3];
        E = subjects[4];
    }
};

TEST_FIXTURE(SubjectWithConstraints, violatedConstraintsCount)
{
    CHECK_EQUAL(0, A->violatedConstraintsCount());
    CHECK_EQUAL(1, B->violatedConstraintsCount());
    CHECK_EQUAL(0, C->violatedConstraintsCount());
    CHECK_EQUAL(2, D->violatedConstraintsCount());
    CHECK_EQUAL(1, E->violatedConstraintsCount());
}

TEST_FIXTURE(SubjectWithConstraints, crowdedComparisonOperator)
{
    A->setRank(2);
    B->setRank(1);
    C->setRank(1);
    D->setRank(1);
    E->setRank(1);

    CHECK(*A < *B);
    CHECK(*A < *D);
    CHECK(*A < *E);
    CHECK(*B < *D);
    CHECK(*C < *A);
    CHECK(*E < *D);
}
