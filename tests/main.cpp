#include <unittest++/UnitTest++.h>
#include <iostream>

int main()
{
    int result = UnitTest::RunAllTests();
    std::cout << __FILE__ << "(" << __LINE__ << ") : "
              << "warning:  Unit Tests " << (result == 0 ? "are OK" : "FAILED") << "!" <<  std::endl;
    return result;
}
