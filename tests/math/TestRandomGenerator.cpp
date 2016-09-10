#include <unittest++/UnitTest++.h>
#include "RandomGenerator.h"

TEST(generateUniformDistributedRandom)
{
    RandomGenerator generator;
    double x = generator.rand(0.5,1);
    CHECK(x >= 0.5);
    CHECK(x <= 1);

    x = generator.rand(0.3,0.8);
    CHECK(x >= 0.3);
    CHECK(x <= 0.8);

    x = generator.rand(0.1,0.5);
    CHECK(x >= 0.1);
    CHECK(x <= 0.5);

    x = generator.rand(0.1,1.8);
    CHECK(x >= 0.1);
    CHECK(x <= 1.8);
}

TEST(generateNormalDistributedRandom)
{
    RandomGenerator generatorN;
    double x = generatorN.randn(0,1);
    CHECK(x >= -4);
    CHECK(x <= 4);

    x = generatorN.randn(0,2);
    CHECK(x >= -8);
    CHECK(x <= 8);
}





