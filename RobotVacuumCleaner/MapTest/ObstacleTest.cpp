#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Obstacle.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObstacleTest
{
    TEST_CLASS(ObstacleTest)
    {
    public:

        TEST_METHOD(Test_constructor)
        {
            Obstacle obs(10, 20, IDType::Obstacle, 5, 7);
            Assert::AreEqual(10, obs.getX());
            Assert::AreEqual(20, obs.getY());
            Assert::AreEqual(static_cast<int>(IDType::Obstacle), static_cast<int>(obs.getID()));
            Assert::AreEqual(5, obs.getWidth());
            Assert::AreEqual(7, obs.getLength());
        }

        TEST_METHOD(Test_set_get_Width)
        {
            Obstacle obs(0, 0, IDType::Obstacle, 1, 1);
            obs.setWidth(15);
            Assert::AreEqual(15, obs.getWidth());
        }

        TEST_METHOD(Test_set_get_Length)
        {
            Obstacle obs(0, 0, IDType::Obstacle, 1, 1);
            obs.setLength(25);
            Assert::AreEqual(25, obs.getLength());
        }

        TEST_METHOD(Test_set_Width_negative)
        {
            Obstacle obs(0, 0, IDType::Obstacle, 1, 1);
            auto func = [&]() { obs.setWidth(-1); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Test_set_Length_negative)
        {
            Obstacle obs(0, 0, IDType::Obstacle, 1, 1);
            auto func = [&]() { obs.setLength(-1); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Test_display_info)
        {
            Obstacle obs(5, 10, IDType::Obstacle, 3, 4);
            std::ostringstream oss;
            std::streambuf* pbuf = std::cout.rdbuf();
            std::cout.rdbuf(oss.rdbuf());

            obs.displayInfo();

            std::cout.rdbuf(pbuf);
            std::string output = oss.str();
            std::string expected_output = "Obstacle ID: " + std::to_string(static_cast<int>(obs.getID())) + " at (5, 10) with width: 3 and length: 4\n";
            Assert::AreEqual(expected_output, output);
        }
    };
}
