#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Battery.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BatteryTest
{
    TEST_CLASS(BatteryTest)
    {
    public:

        TEST_METHOD(Test_initial_level)
        {
            Battery battery(50);
            Assert::AreEqual(50, battery.getLevel());
        }

        TEST_METHOD(Test_set_level_within_bounds)
        {
            Battery battery;
            battery.setLevel(75);
            Assert::AreEqual(75, battery.getLevel());
        }

        TEST_METHOD(Test_set_level_below_zero)
        {
            Battery battery;
            auto func = [&]() { battery.setLevel(-1); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Test_set_level_above_hundred)
        {
            Battery battery;
            auto func = [&]() { battery.setLevel(101); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Test_default_initial_level)
        {
            Battery battery;
            Assert::AreEqual(100, battery.getLevel());
        }
    };
}
