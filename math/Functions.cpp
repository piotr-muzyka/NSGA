#include <Functions.h>
#include <CustomAssertion.h>

Functions::Functions(const unsigned &numberOfGoalFunctions, const unsigned &numberOfVariables)
    : functions(numberOfGoalFunctions, Expression(numberOfVariables))
{
    assert(numberOfGoalFunctions > 0);
}

Functions::Functions(std::initializer_list<Expression> f)
    : functions(f)
{
}

Expression &Functions::operator[](const unsigned &id)
{
    return at(id);
}

Expression &Functions::at(const unsigned &id)
{
    assert(id < functions.size());
    return functions[id];
}

unsigned Functions::size() const
{
    return functions.size();
}

std::vector<Expression>::iterator Functions::begin()
{
    return functions.begin();
}

std::vector<Expression>::iterator Functions::end()
{
    return functions.end();
}
