#include <unittest++/UnitTest++.h>
#include <Expression.h>
#include <CustomAssertion.h>

class ExpressionTest
{
public:
    Expression expr;
    AssertSpy assertion;

    ExpressionTest() : expr(4)
    {
        assertion.reset();
        expr("x1") = 1;
        expr("x2") = 2;
        expr("x3") = 3;
        expr("x4") = 4;
    }
};

TEST_FIXTURE(ExpressionTest, unknownKey)
{
    CHECK_EQUAL(0, assertion.fails());
    expr("invalidKey");
    expr("x5");
    CHECK_EQUAL(2, assertion.fails());
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

    CHECK_EQUAL(0, assertion.fails());
    for(auto& key : variables)
    {
        expr(key);
        CHECK_EQUAL(0, assertion.fails());
    }
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

    CHECK_EQUAL(0, assertion.fails());
    CHECK_EQUAL(1, copiedExpr("x1"));
    CHECK_EQUAL(2, copiedExpr("x2"));
    CHECK_EQUAL(3, copiedExpr("x3"));
    CHECK_EQUAL(4, copiedExpr("x4"));
    CHECK_EQUAL(0, assertion.fails());

    CHECK_EQUAL(1+2+3+4, expr.value());
    CHECK_EQUAL(1+2+3+4, copiedExpr.value());
}
