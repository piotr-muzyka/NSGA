#include <unittest++/UnitTest++.h>
#include <Expression.h>
#include <CustomAssertion.h>
#include <iostream>

class ExpressionTest
{
public:
    Expression expr;

    ExpressionTest() : expr(4)
    {
        expr("x1") = 1;
        expr("x2") = 2;
        expr("x3") = 3;
        expr("x4") = 4;
    }
};

TEST_FIXTURE(ExpressionTest, unknownKey)
{
    CHECK_ASSERT(expr("invalidKey"));
    CHECK_ASSERT(expr("x5"));
}

TEST_FIXTURE(ExpressionTest, degenarateExpressions)
{
    expr.parse("");
    CHECK(isnan(expr.value()));
}

TEST_FIXTURE(ExpressionTest, getVariablesCount)
{
    CHECK_EQUAL(4, expr.variablesCount());
}

TEST_FIXTURE(ExpressionTest, getVariablesKeys)
{
    std::vector<std::string> variables = expr.getAllVariableKeys();
    CHECK_EQUAL(4, variables.size());

    for(auto& key : variables)
    {
        expr(key);
    }
}

TEST_FIXTURE(ExpressionTest, inequality)
{
    expr.parse("x1+x2>0");
    CHECK(expr.isFeasible());
    expr.parse("x1+x2<0");
    CHECK(!expr.isFeasible());

    expr.parse("x1-x2<0");
    CHECK(expr.isFeasible());
    expr.parse("x1-x2>0");
    CHECK(!expr.isFeasible());

    expr.parse("x1>x1");
    CHECK(!expr.isFeasible());
    expr.parse("x1<x1");
    CHECK(!expr.isFeasible());

    expr.parse("x1>=x1");
    CHECK(expr.isFeasible());
    expr.parse("x1<=x1");
    CHECK(expr.isFeasible());

    expr.parse("x1==x1");
    CHECK(expr.isFeasible());
    expr.parse("x1!=x1");
    CHECK(!expr.isFeasible());
}

class ParsedExpressionTest : public ExpressionTest
{
public:
    ParsedExpressionTest() : ExpressionTest()
    {
        expr.parse("x1+x2+x3+x4");
    }
};

TEST_FIXTURE(ParsedExpressionTest, simpleExpression)
{
    CHECK_EQUAL(1+2+3+4, expr.value());
}

TEST_FIXTURE(ParsedExpressionTest, expressionCopy)
{
    Expression copiedExpr(expr);

    CHECK_EQUAL(1, copiedExpr("x1"));
    CHECK_EQUAL(2, copiedExpr("x2"));
    CHECK_EQUAL(3, copiedExpr("x3"));
    CHECK_EQUAL(4, copiedExpr("x4"));

    CHECK_EQUAL(1+2+3+4, expr.value());
    CHECK_EQUAL(1+2+3+4, copiedExpr.value());
}
