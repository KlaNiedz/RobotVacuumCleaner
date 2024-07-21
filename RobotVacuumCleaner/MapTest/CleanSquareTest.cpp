#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/CleanSquare.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CleanSquareTest
{
    TEST_CLASS(CleanSquareTest)
    {
    public:

        TEST_METHOD(Test_parameterized_constructor)
        {
            CleanSquare cs(10, 20, IDType::Clean);
            Assert::AreEqual(10, cs.getX());
            Assert::AreEqual(20, cs.getY());
            Assert::AreEqual(static_cast<int>(IDType::Clean), static_cast<int>(cs.getID()));
        }

        TEST_METHOD(Test_display_info)
        {
            CleanSquare cs(5, 10, IDType::Clean);
            std::ostringstream oss;
            std::streambuf* pbuf = std::cout.rdbuf();
            std::cout.rdbuf(oss.rdbuf());

            cs.displayInfo();

            std::cout.rdbuf(pbuf);
            std::string output = oss.str();
            std::string expected_output = "Clean ID: " + std::to_string(static_cast<int>(cs.getID())) + " at (5, 10)\n";
            Assert::AreEqual(expected_output, output);
        }
    };
}
