#include <unittest++/UnitTest++.h>
#include <Expression.h>


class ExpressionTest
{
public:
    static int assertFailCounter;
    Expression expr;

    ExpressionTest() : expr(4)
    {
        assertFailCounter = 0;
        expr("x1") = 1;
        expr("x2") = 2;
        expr("x3") = 3;
        expr("x4") = 4;
    }
};

int ExpressionTest::assertFailCounter = 0;
void assert(bool expression) {
    if (!expression)
        ExpressionTest::assertFailCounter++;
}

TEST_FIXTURE(ExpressionTest, testUnknownKey)
{
    CHECK_EQUAL(0, assertFailCounter);
    expr("invalidKey");
    expr("x5");
    CHECK_EQUAL(2, assertFailCounter);
}

TEST_FIXTURE(ExpressionTest, testDegenarateExpressions)
{
    expr.parse("");
    CHECK(isnan(expr.value()));
}


class ParsedExpressionTest : public ExpressionTest
{
public:
    ParsedExpressionTest() : ExpressionTest()
    {
        expr.parse("x1+x2+x3+x4");
    }
};

TEST_FIXTURE(ParsedExpressionTest, testSimpleExpression)
{
    CHECK_EQUAL(1+2+3+4, expr.value());
}

TEST_FIXTURE(ParsedExpressionTest, testExpressionCopy)
{
    Expression copiedExpr(expr);

    CHECK_EQUAL(0, assertFailCounter);
    CHECK_EQUAL(1, copiedExpr("x1"));
    CHECK_EQUAL(2, copiedExpr("x2"));
    CHECK_EQUAL(3, copiedExpr("x3"));
    CHECK_EQUAL(4, copiedExpr("x4"));
    CHECK_EQUAL(0, assertFailCounter);

    CHECK_EQUAL(1+2+3+4, expr.value());
    CHECK_EQUAL(1+2+3+4, copiedExpr.value());
}
