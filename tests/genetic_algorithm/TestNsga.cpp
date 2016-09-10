#include <unittest++/UnitTest++.h>
#include <Nsga.h>

TEST(resultsGeneration)
{
    Nsga core;
    CoreSettings settings(50,5,2,5,2);

    settings.f[0] = "x1+x2";
    settings.f[1] = "x1-x2";

    core.execute(settings);
    auto& results = core.result();

    CHECK(results.size() != 0);
    CHECK(results[0].size() != 0);

    for(unsigned i = 0; i < results.size(); ++i)
        for(unsigned j = 0; j < results[0].size(); ++j)
            CHECK(!isnan(results[i][j]));
}
