#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Map.h"
#include "../RobotVacuumCleaner/LeftSideSensor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeftSideSensorTests
{
    TEST_CLASS(LeftSideSensorTests)
    {
    public:

        TEST_METHOD(TestObstacleInRangeNorth)
        {
            Map map(200, 200);
            map.placeObject(2, 1, IDType::Obstacle);

            LeftSideSensor sensor(map, 2, 2, Direction::North, 1);

            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestObstacleInRangeEast)
        {
            Map map(200, 200);
            map.placeObject(1, 2, IDType::Obstacle);

            LeftSideSensor sensor(map, 2, 2, Direction::East, 1);

            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestWallDetectedEast)
        {
            Map map(200, 200);

            LeftSideSensor sensor(map, 9, 5, Direction::South, 1);

            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestWallDetectedNorth)
        {
            Map map(200, 200);

            LeftSideSensor sensor(map, 1, 0, Direction::East, 1);

            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestDirtDetectedNorth)
        {
            Map map(200, 200);
            map.placeObject(2, 3, IDType::Dirty);

            LeftSideSensor sensor(map, 2, 2, Direction::South, 3);

            Assert::IsTrue(sensor.dirt_detected());
        }

        TEST_METHOD(TestDirtDetectedEast)
        {
            Map map(200, 200);
            map.placeObject(3, 2, IDType::Dirty);

            LeftSideSensor sensor(map, 2, 2, Direction::West, 3);

            Assert::IsTrue(sensor.dirt_detected());
        }
    };
}
