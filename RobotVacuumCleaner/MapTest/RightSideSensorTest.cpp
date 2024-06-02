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
            // Initialize a 5x5 map with an obstacle at (2, 3)
            Map map(5, 5);
            map.placeObject(2, 3, IDType::Obstacle);

            // Create a RightSideSensor at position (2, 2) facing North with range 3
            RightSideSensor sensor(map, 2, 2, Direction::North, 3);

            // Check if obstacle is detected in range
            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestObstacleInRangeEast)
        {
            // Initialize a 5x5 map with an obstacle at (3, 2)
            Map map(5, 5);
            map.placeObject(3, 2, IDType::Obstacle);

            // Create a RightSideSensor at position (2, 2) facing East with range 3
            RightSideSensor sensor(map, 2, 2, Direction::East, 3);

            // Check if obstacle is detected in range
            Assert::IsTrue(sensor.obstacle_in_range());
        }

        TEST_METHOD(TestWallDetectedNorth)
        {
            // Initialize a 5x5 map
            Map map(5, 5);

            // Create a RightSideSensor at position (2, 4) facing North
            RightSideSensor sensor(map, 2, 4, Direction::North, 3);

            // Check if wall is detected
            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestWallDetectedEast)
        {
            // Initialize a 5x5 map
            Map map(5, 5);

            // Create a RightSideSensor at position (4, 2) facing East
            RightSideSensor sensor(map, 4, 2, Direction::East, 3);

            // Check if wall is detected
            Assert::IsTrue(sensor.wall_detected());
        }

        TEST_METHOD(TestDirtDetectedNorth)
        {
            // Initialize a 5x5 map with dirt at (2, 3)
            Map map(5, 5);
            map.placeObject(2, 3, IDType::Dirty);

            // Create a RightSideSensor at position (2, 2) facing North
            RightSideSensor sensor(map, 2, 2, Direction::North, 3);

            // Check if dirt is detected
            Assert::IsTrue(sensor.dirt_detected());
        }

        TEST_METHOD(TestDirtDetectedEast)
        {
            // Initialize a 5x5 map with dirt at (3, 2)
            Map map(5, 5);
            map.placeObject(3, 2, IDType::Dirty);

            // Create a RightSideSensor at position (2, 2) facing East
            RightSideSensor sensor(map, 2, 2, Direction::East, 3);

            // Check if dirt is detected
            Assert::IsTrue(sensor.dirt_detected());
        }
    };
}
