#include "Expression.h"
#include <CustomAssertion.h>

Expression::Expression(unsigned numberOfVariables)
{
    exprtk::symbol_table<double> symbol_table;
    std::string key;
    for(unsigned i = 0; i < numberOfVariables; ++i)
    {
        key = "x"+std::to_string(i+1);
        x[key] = 0;
        symbol_table.add_variable(key,x[key]);
    }
    symbol_table.add_constants();
    expression.register_symbol_table(symbol_table);
}

Expression::Expression(const Expression &e) : x(e.x), expressionString(e.expressionString)
{
    exprtk::symbol_table<double> symbol_table;
    for (auto& element : x)
        symbol_table.add_variable(element.first,element.second);
    symbol_table.add_constants();
    expression.register_symbol_table(symbol_table);
    parse(expressionString);
}

doublesVector Expression::createVector(double min, double step, double max)
{
    doublesVector x(static_cast<unsigned>(((max-min)/step)+1), 0);

    x[0] = min;
    for(doublesVector::size_type i = 1; i != x.size(); i++)
        x[i] = x[i-1]+step;
    return x;
}
doublesVector Expression::createVectorWithLength(unsigned length, double min, double max)
{
    double step = (max-min)/(length-1);
    return createVector(min,step,max);
}

void Expression::parse(const std::string& newExpressionString)
{
    expressionString = newExpressionString;
    parser.compile(expressionString,expression);
}

double Expression::value()
{
    return expression.value();
}

double& Expression::operator()(const std::string& key)
{
    return at(key);
}

double &Expression::at(const std::string &key)
{
    assert(x.find(key) != x.end());
    return x[key];
}

double Expression::variablesCount()
{
    return x.size();
}

std::vector<std::string> Expression::getAllVariableKeys()
{
    std::vector<std::string> keys;
    for (auto& element : x)
        keys.push_back(element.first);
    return keys;
}
