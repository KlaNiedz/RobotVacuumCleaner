#include "CppUnitTest.h"
#include "../RobotVacuumCleaner/Map.h"
#include "../RobotVacuumCleaner/ChargingStation.h"
#include "../RobotVacuumCleaner/CleanSquare.h"
#include "../RobotVacuumCleaner/Constants.h"

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

		//TEST_METHOD(Test_Add_Object)
		//{
		//	Map map(350, 350);
		//	map.addObject(2, 2, )
		//	
		//	Assert::AreEqual(h, map_height);
		//	Assert::AreEqual(w, map_width);
		//}
	};
}
