#include "ExpressionParser.h"

ExpressionParser::ExpressionParser() : x1(0), x2(0)
{
    exprtk::symbol_table<double> symbol_table;
    symbol_table.add_variable("x1",x1);
    symbol_table.add_variable("x2",x2);
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

double ExpressionParser::currentResult()
{
    return expression.value();
}

const doublesMatrix ExpressionParser::results(const doublesVector& x1Vec, const doublesVector& x2Vec)
{
    doublesMatrix result(x1Vec.size(), doublesVector(x2Vec.size(), 0));

    for(doublesVector::size_type i = 0; i != x1Vec.size(); i++)
        for(doublesVector::size_type j = 0; j != x2Vec.size(); j++)
        {
            x1 = x1Vec[i];
            x2 = x2Vec[j];
            result[i][j] = expression.value();
        }

    return result;
}
