/* Examples are based on site:
 * http://opensimulator.org/git/opensim-libs-save/trunk/unmanaged/OpenDynamicsEngine-r1755/tests/UnitTest++/docs/UnitTest++.html
 */

#include <unittest++/UnitTest++.h>
#include <string>

/* Class we want test */
class Foo
{
    std::string objectName;
public:
    void init(std::string newName = "foo") { objectName = newName; }
    void close() {}
    std::string name() { return objectName; }
};

SUITE(ExampleTestSuite)
{
    /* Basic test example */
    TEST(SimpleExample)
    {
        CHECK(2+2 == 4);                            // Test boolean expression
        CHECK_EQUAL(4, 2+2);                        // Test integers
        CHECK_CLOSE(3.14, 3.1415, 0.01);            // Test real numbers
        CHECK_EQUAL("test", "test");                // Test strings
    }

    TEST(fooTest)
    {
        Foo testObject;
        testObject.init();
        CHECK_EQUAL("foo", testObject.name());
    }

    class FooFixture
    {
    public:
        Foo object;
        FooFixture() { object.init("fooFixture"); } // Fixture setup - it is called on every test start
        ~FooFixture() { object.close(); }           // Fixture teardown - it is called on every test end
    };

    TEST_FIXTURE(FooFixture, testName)
    {
        CHECK_EQUAL("fooFixture", object.name());
//        CHECK_EQUAL("foo", object.name());         // fails!
    }
}
