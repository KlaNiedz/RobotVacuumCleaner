#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/ChargingStation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChargingStationTest
{
    TEST_CLASS(ChargingStationTest)
    {
    public:

        TEST_METHOD(Test_default_constructor)
        {
            ChargingStation cs;
            Assert::AreEqual(0, cs.getX());
            Assert::AreEqual(0, cs.getY());
            Assert::AreEqual(static_cast<int>(IDType::ChargingStation), static_cast<int>(cs.getID()));
        }

        TEST_METHOD(Test_parameterized_constructor)
        {
            ChargingStation cs(10, 20);
            Assert::AreEqual(10, cs.getX());
            Assert::AreEqual(20, cs.getY());
            Assert::AreEqual(static_cast<int>(IDType::ChargingStation), static_cast<int>(cs.getID()));
        }

        TEST_METHOD(Test_display_info)
        {
            ChargingStation cs(5, 10);
            std::ostringstream oss;
            std::streambuf* pbuf = std::cout.rdbuf();
            std::cout.rdbuf(oss.rdbuf());

            cs.displayInfo();

            std::cout.rdbuf(pbuf);
            std::string output = oss.str();
            std::string expected_output = "Charging Station ID: " + std::to_string(static_cast<int>(cs.getID())) + " at (5, 10)\n";
            Assert::AreEqual(expected_output, output);
        }
        //TEST_METHOD(test_draw)
    };
}
