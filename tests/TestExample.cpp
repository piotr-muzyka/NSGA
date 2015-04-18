/* Examples are based on site:
 * http://opensimulator.org/git/opensim-libs-save/trunk/unmanaged/OpenDynamicsEngine-r1755/tests/UnitTest++/docs/UnitTest++.html
 */

#include <unittest++/UnitTest++.h>
#include <string>

/* Class we want test */
class foo
{
public:
    void init() {}
    void close() {}
    std::string name() { return "foo"; }
};

SUITE(ExampleTestSuite)
{
    /* Basic test example */
    TEST(SimpleExample)
    {
        CHECK(2+2 == 4);                    // Test boolean expression
        CHECK_EQUAL(2+2, 4);                // Test integers
        CHECK_CLOSE(3.14, 3.1415, 0.01);    // Test real numbers
        CHECK_EQUAL("test", "test");        // Test strings
    }

    class fooFixture : public foo
    {
    public:
        fooFixture() { init(); }            // Fixture setup - it is called on every test start
        ~fooFixture() { close(); }          // Fixture teardown - it is called on every test end
        /* We can override original methods for testing purpose */
        std::string name() { return "fooFixture"; }
    };

    TEST_FIXTURE(fooFixture, testName)
    {
        CHECK_EQUAL("fooFixture", name());
//        CHECK_EQUAL("foo", name());         // fails!
    }
}
