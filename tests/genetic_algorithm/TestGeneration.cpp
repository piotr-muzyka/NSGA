#include <unittest++/UnitTest++.h>
#include <Generation.h>

class GenerationTest
{
public:
    ExpressionPtr f1, f2;
    unsigned generationSize = 50;
    Generation generation;

    GenerationTest()
        : f1(new Expression(5)),
          f2(new Expression(5)),
          generation(generationSize, f1, f2) {}
};

TEST_FIXTURE(GenerationTest, generationCreation)
{
    CHECK_EQUAL(generationSize, generation.size());
}

TEST_FIXTURE(GenerationTest, produceNextGeneration)
{
    Generation newGeneration = generation.produceNextGeneration();
    CHECK_EQUAL(generationSize, newGeneration.size());
}
