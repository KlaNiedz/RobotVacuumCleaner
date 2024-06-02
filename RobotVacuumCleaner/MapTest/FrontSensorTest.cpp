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
            // Initialize a 5x5 map with an obstacle at (1, 2)
            Map map(100,100);
            map.placeObject(1, 2, IDType::Obstacle);

            // Create a FrontSensor at position (3, 2) facing North with range 3
            FrontSensor sensor(map, 3, 2, Direction::North, 3);

            // Check if obstacle is detected in range
            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestObstacleInRangeEast)
        {
            // Initialize a 5x5 map with an obstacle at (2, 4)
            Map map(5, 5);
            map.placeObject(2, 4, IDType::Obstacle);

            // Create a FrontSensor at position (2, 2) facing East with range 3
            FrontSensor sensor(map, 2, 2, Direction::East, 3);

            // Check if obstacle is detected in range
            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestGetDistToStop)
        {
            // Initialize a 5x5 map with an obstacle at (2, 4)
            Map map(5, 5);
            map.placeObject(2, 4, IDType::Obstacle);

            // Create a FrontSensor at position (2, 2) facing East with range 3
            FrontSensor sensor(map, 2, 2, Direction::East, 3);

            // Check the distance to the obstacle
            Assert::AreEqual(2, sensor.get_dist_to_stop());
        }

        TEST_METHOD(TestWallDetectedNorth)
        {
            // Initialize a 5x5 map
            Map map(5, 5);

            // Create a FrontSensor at position (0, 2) facing North
            FrontSensor sensor(map, 0, 2, Direction::North, 3);

            // Check if wall is detected
            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestWallDetectedEast)
        {
            // Initialize a 5x5 map
            Map map(5, 5);

            // Create a FrontSensor at position (2, 4) facing East
            FrontSensor sensor(map, 2, 4, Direction::East, 3);

            // Check if wall is detected
            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestDirtDetectedNorth)
        {
            // Initialize a 5x5 map with dirt at (2, 2)
            Map map(5, 5);
            map.placeObject(2, 2, IDType::Dirty);

            // Create a FrontSensor at position (3, 2) facing North
            FrontSensor sensor(map, 3, 2, Direction::North, 3);

            // Check if dirt is detected
            Assert::IsTrue(sensor.dirt_detected());
        }

        TEST_METHOD(TestDirtDetectedEast)
        {
            // Initialize a 5x5 map with dirt at (2, 3)
            Map map(5, 5);
            map.placeObject(2, 3, IDType::Dirty);

            // Create a FrontSensor at position (2, 2) facing East
            FrontSensor sensor(map, 2, 2, Direction::East, 3);

            // Check if dirt is detected
            Assert::IsTrue(sensor.dirt_detected());
        }

    };
}
