#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Filter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FilterTest
{
    TEST_CLASS(FilterTest)
    {
    public:

        TEST_METHOD(Test_initial_fill_level)
        {
            Filter filter(50);
            Assert::AreEqual(50, filter.getFillLevel());
        }

        TEST_METHOD(Test_set_fill_level_within_bounds)
        {
            Filter filter;
            filter.setFillLevel(75);
            Assert::AreEqual(75, filter.getFillLevel());
        }

        TEST_METHOD(Test_set_fill_level_below_zero)
        {
            Filter filter;
            auto func = [&]() { filter.setFillLevel(-1); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Test_set_fill_level_above_hundred)
        {
            Filter filter;
            auto func = [&]() { filter.setFillLevel(101); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Test_default_initial_fill_level)
        {
            Filter filter;
            Assert::AreEqual(0, filter.getFillLevel());
        }
    };
}
