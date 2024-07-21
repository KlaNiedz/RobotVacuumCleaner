#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Map.h"
#include "../RobotVacuumCleaner/RightSideSensor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RightSideSensorTests
{
    TEST_CLASS(RightSideSensorTests)
    {
    public:

        TEST_METHOD(TestObstacleInRangeNorth)
        {
            Map map(200, 200);
            map.placeObject(2, 3, IDType::Obstacle);

            RightSideSensor sensor(map, 2, 2, Direction::North, 1);

            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestObstacleInRangeEast)
        {
            Map map(200, 200);
            map.placeObject(3, 2, IDType::Obstacle);

            RightSideSensor sensor(map, 2, 2, Direction::East, 1);

            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestWallDetectedEast)
        {
            Map map(200, 200);

            RightSideSensor sensor(map, 9, 5, Direction::North, 1);

            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestWallDetectedNorth)
        {
            Map map(200, 200);

            RightSideSensor sensor(map, 1, 0, Direction::West, 1);

            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestDirtDetectedNorth)
        {
            Map map(200, 200);
            map.placeObject(2, 3, IDType::Dirty);

            RightSideSensor sensor(map, 2, 2, Direction::North, 3);

            Assert::IsTrue(sensor.dirt_detected());
        }

        TEST_METHOD(TestDirtDetectedEast)
        {
            Map map(200, 200);
            map.placeObject(3, 2, IDType::Dirty);

            RightSideSensor sensor(map, 2, 2, Direction::East, 3);

            Assert::IsTrue(sensor.dirt_detected());
        }
    };
}
