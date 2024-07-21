#include "../RobotVacuumCleaner/Robot.h"
#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RobotTests
{
    TEST_CLASS(RobotInitializationTests)
    {
    public:
        TEST_METHOD(TestInitialization)
        {
            Map map(200, 200);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());

            Assert::AreEqual(5, robot.get_x());
            Assert::AreEqual(5, robot.get_y());
            Assert::AreEqual(static_cast<int>(Direction::North), static_cast<int>(robot.get_heading()));
            Assert::AreEqual(100, robot.get_battery().getLevel());
            Assert::AreEqual(0, robot.get_filter().getFillLevel());
        }

        TEST_METHOD(TestInitializationOutOfBounds)
        {
            Map map(200, 200);
            Battery battery(100);
            Filter filter(0);

            auto func = [&]() { Robot robot(&map, -1, -1, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor()); };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(TestNullMap)
        {
            Battery battery(100);
            Filter filter(0);

            auto func = [&]() { Robot robot(nullptr, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor()); };
            Assert::ExpectException<std::invalid_argument>(func);
        }
    };

    TEST_CLASS(RobotMovementTests)
    {
    public:
        TEST_METHOD(TestMoveUp)
        {
            Map map(200, 200);
            map.placeObject(5, 5, IDType::Dirty);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 0, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());
            robot.go_up();

            Assert::AreEqual(0, robot.get_x());
            Assert::AreEqual(4, robot.get_y());
        }

        TEST_METHOD(TestMoveDown)
        {
            Map map(200, 200);
            map.placeObject(5, 5, IDType::Dirty);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 0, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());
            robot.go_down();

            Assert::AreEqual(0, robot.get_x());
            Assert::AreEqual(6, robot.get_y());
        }

        TEST_METHOD(TestMoveLeft)
        {
            Map map(200, 200);
            map.placeObject(5, 5, IDType::Dirty);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 5, 0, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());
            robot.go_left();

            Assert::AreEqual(4, robot.get_x());
            Assert::AreEqual(0, robot.get_y());
        }

        TEST_METHOD(TestMoveRight)
        {
            Map map(200, 200);
            map.placeObject(5, 5, IDType::Dirty);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 5, 0, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());
            robot.go_right();

            Assert::AreEqual(6, robot.get_x());
            Assert::AreEqual(0, robot.get_y());
        }
    };

    TEST_CLASS(RobotBatteryTests)
    {
    public:
        TEST_METHOD(TestBatteryDischarge)
        {
            Map map(200, 200);
            map.placeObject(5, 5, IDType::Dirty);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());
            robot.take_step();

            Assert::AreEqual(99, robot.get_battery().getLevel());
        }

        TEST_METHOD(TestBatteryLow)
        {
            Map map(200, 200);
            Battery battery(10);
            Filter filter(0);

            Robot robot(&map, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());

            Assert::IsTrue(robot.battery_low());
        }

        TEST_METHOD(TestBatteryNotLow)
        {
            Map map(200, 200);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());

            Assert::IsFalse(robot.battery_low());
        }
    };

    TEST_CLASS(RobotFilterTests)
    {
    public:
        TEST_METHOD(TestFilterFill)
        {
            Map map(200, 200);
            map.placeObject(5, 5, IDType::Dirty);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());
            robot.take_step();

            Assert::AreEqual(1, robot.get_filter().getFillLevel());
        }

        TEST_METHOD(TestFilterFull)
        {
            Map map(200, 200);
            Battery battery(100);
            Filter filter(85);

            Robot robot(&map, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());

            Assert::IsTrue(robot.filter_fullfilled());
        }

        TEST_METHOD(TestFilterNotFull)
        {
            Map map(200, 200);
            Battery battery(100);
            Filter filter(0);

            Robot robot(&map, 5, 5, Direction::North, IDType::Benek, battery, filter, 0, FrontSensor(), RightSideSensor(), LeftSideSensor());

            Assert::IsFalse(robot.filter_fullfilled());
        }
    };
}
