#ifndef GOALFUNCTIONS_H
#define GOALFUNCTIONS_H

#include <Expression.h>

class Functions : public Expression
{
public:
    Functions(const unsigned& numberOfGoalFunctions, const unsigned& numberOfVariables = 5);
    Functions(std::initializer_list<Expression> f);

    Expression& operator[](const unsigned& id);
    Expression& at(const unsigned& id);
    unsigned size() const;
    std::vector<Expression>::iterator begin();
    std::vector<Expression>::iterator end();
private:
    std::vector<Expression> functions;
};

#endif // GOALFUNCTIONS_H
