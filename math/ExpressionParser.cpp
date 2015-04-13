#include "ExpressionParser.h"
#include <assert.h>

ExpressionParser::ExpressionParser(unsigned numberOfVariables)
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

doublesVector ExpressionParser::createVector(double min, double step, double max)
{
    doublesVector x(static_cast<unsigned>(((max-min)/step)+1), 0);

    x[0] = min;
    for(doublesVector::size_type i = 1; i != x.size(); i++)
        x[i] = x[i-1]+step;
    return x;
}
doublesVector ExpressionParser::createVectorWithLength(unsigned length, double min, double max)
{
    double step = (max-min)/(length-1);
    return createVector(min,step,max);
}

void ExpressionParser::parse(const std::string& expressionString)
{
    parser.compile(expressionString,expression);
}

double ExpressionParser::value()
{
    return expression.value();
}

double& ExpressionParser::operator()(const std::string& key)
{
    assert(x.find(key) != x.end());
    return x[key];
}
