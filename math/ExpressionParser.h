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
<<<<<<< HEAD
    ExpressionParser();
    doublesVector createVector(double min, double step, double max);
    doublesVector createVectorWithLength(unsigned length, double min, double max);
    void parse(const std::string& expressionString);
    double currentResult();
    const doublesMatrix results(const doublesVector& x1Vec, const doublesVector& x2Vec);

    double x1;
    double x2;
=======
    ExpressionParser(unsigned xLength = 5);
    doublesVector createVector(double min, double step, double max);
    doublesVector createVectorWithLength(unsigned length, double min, double max);
    void parse(const std::string& expressionString);
    double result();

    doublesVector x;
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
private:
    exprtk::expression<double> expression;
    exprtk::parser<double> parser;
};

#endif // EXPRESSIONPARSER_H
