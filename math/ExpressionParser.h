#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <exprtk.hpp>
#include <string>
#include <vector>

typedef std::vector<double> doublesVector;
typedef std::vector<doublesVector> doublesMatrix;

class ExpressionParser
{
public:
    ExpressionParser(unsigned xLength = 5);
    doublesVector createVector(double min, double step, double max);
    doublesVector createVectorWithLength(unsigned length, double min, double max);
    void parse(const std::string& expressionString);
    double result();

    doublesVector x;
private:
    exprtk::expression<double> expression;
    exprtk::parser<double> parser;
};

#endif // EXPRESSIONPARSER_H
