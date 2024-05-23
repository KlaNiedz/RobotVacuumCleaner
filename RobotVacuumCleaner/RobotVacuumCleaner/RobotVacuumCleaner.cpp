// RobotVacuumCleaner.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Map.h"
#include "raylib.h"
#include "Constants.h"




int main()
{
	Map myMap(300, 350);
	// generating map in terminal
	myMap.showMap();
	
	InitWindow(myMap.getWidth()*cell_size, myMap.getHeight()*cell_size, "Robot Vacuum Cleaner");
	SetTargetFPS(60);
	
	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		//Drawing
		ClearBackground(colorMap[BasicColor::Blue]);
		
		myMap.drawAllObstacles();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


