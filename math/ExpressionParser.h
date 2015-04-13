#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <exprtk.hpp>
#include <string>
#include <vector>
#include <map>

typedef std::vector<double> doublesVector;
typedef std::vector<doublesVector> doublesMatrix;

class ExpressionParser
{
public:
    ExpressionParser(unsigned numberOfVariables = 2);
    doublesVector createVector(double min, double step, double max);
    doublesVector createVectorWithLength(unsigned length, double min, double max);
    void parse(const std::string& expressionString);
    double value();

    double& operator()(const std::string& key);
private:
    std::map<std::string,double> x;
    exprtk::expression<double> expression;
    exprtk::parser<double> parser;
};

#endif // EXPRESSIONPARSER_H
