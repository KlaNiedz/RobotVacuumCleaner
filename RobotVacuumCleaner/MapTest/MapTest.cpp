#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Map.h"
#include "../RobotVacuumCleaner/ChargingStation.h"
#include "../RobotVacuumCleaner/CleanSquare.h"
#include "../RobotVacuumCleaner/Constants.h"
#include "../RobotVacuumCleaner//IDType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapTest
{
	TEST_CLASS(MapTest)
	{
	public:
		
		TEST_METHOD(Test_creating_map)
		{
			Map map(350, 350);
			int map_height = map.getHeight();
			int map_width = map.getWidth();
			int h = 18;
			int w = 18;
			Assert::AreEqual(h, map_height);
			Assert::AreEqual(w, map_width);
		}

		TEST_METHOD(Test_Initialization)
		{
			Map map(100, 100);
			Assert::AreEqual(to_int(map.getXY(0, 0)), to_int(IDType::ChargingStation));
			
		}

		TEST_METHOD(Test_Add_Object)
		{
			Map map(350, 350);
			map.addObject(2, 2, 3, 3, IDType::Obstacle);
			Assert::AreEqual(to_int(map.getXY(2, 2)), to_int(IDType::Obstacle));
			Assert::AreEqual(to_int(map.getXY(3, 2)), to_int(IDType::Obstacle));
		}
		TEST_METHOD(Test_Clean)
		{
			Map map(350, 350);
			map.clean(1, 0);
			Assert::AreEqual(to_int(map.getXY(0, 1)), to_int(IDType::Clean));
		}
	};
}
