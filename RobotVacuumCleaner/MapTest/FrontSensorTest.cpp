#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/FrontSensor.h"
#include "../RobotVacuumCleaner/Map.h"
#include "../RobotVacuumCleaner/IDType.h"
#include "../RobotVacuumCleaner/Direction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FrontSensorTests
{
    TEST_CLASS(FrontSensorTests)
    {
    public:

        TEST_METHOD(TestObstacleInRangeNorth)
        {

            Map map(100,100);
            map.placeObject(2, 1, IDType::Obstacle);

            FrontSensor sensor(map, 1, 4, Direction::North, 3);

            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestObstacleInRangeEast)
        {
            Map map(100, 100);
            map.placeObject(2, 4, IDType::Obstacle);

            FrontSensor sensor(map, 2, 2, Direction::East, 3);

            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestGetDistToStop)
        {
            Map map(200,200);
            map.placeObject(0, 1, IDType::Obstacle);

            FrontSensor sensor(map, 0, 0, Direction::East, 3);

            Assert::AreEqual(0, sensor.get_dist_to_stop());
        }

        TEST_METHOD(TestWallDetectedNorth)
        {
            Map map(200, 200);

            FrontSensor sensor(map, 10, 0, Direction::North, 3);

            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestWallDetectedEast)
        {
            Map map(200, 200);

            FrontSensor sensor(map, 9, 9, Direction::East, 3);

            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestDirtDetectedNorth)
        {
            // Initialize a 5x5 map with dirt at (2, 2)
            Map map(200, 200);
            map.placeObject(2, 2, IDType::Dirty);

            // Create a FrontSensor at position (3, 2) facing North
            FrontSensor sensor(map, 2, 3, Direction::North, 3);

            // Check if dirt is detected
            Assert::IsTrue(sensor.dirt_detected());
        }

        TEST_METHOD(TestDirtDetectedEast)
        {
            // Initialize a 5x5 map with dirt at (2, 3)
            Map map(200, 200);
            map.placeObject(2, 3, IDType::Dirty);

            // Create a FrontSensor at position (2, 2) facing East
            FrontSensor sensor(map, 2, 2, Direction::East, 3);

            // Check if dirt is detected
            Assert::IsTrue(sensor.dirt_detected());
        }

    };
}
