#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <exprtk.hpp>
#include <string>
#include <vector>
#include <map>

typedef std::vector<double> doublesVector;
typedef std::vector<doublesVector> doublesMatrix;

class Expression
{
public:
    Expression(unsigned numberOfVariables = 5);
    Expression(const Expression &e);
    doublesVector createVector(double min, double step, double max);
    doublesVector createVectorWithLength(unsigned length, double min, double max);
    void parse(const std::string& newExpressionString);
    double value();

    double& operator()(const std::string& key);
private:
    std::map<std::string,double> x;
    exprtk::expression<double> expression;
    std::string expressionString;
    exprtk::parser<double> parser;
};

#endif // EXPRESSIONPARSER_H
