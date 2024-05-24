// RobotVacuumCleaner.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Map.h"
#include "raylib.h"
#include "Constants.h"
#include "Game.h"




int main()
{
	Game game = Game();

	// generating map in terminal
	game.myMap.showMap();
	
	InitWindow(game.myMap.getWidth()*cell_size, game.myMap.getHeight()*cell_size, "Robot Vacuum Cleaner");
	SetTargetFPS(60);
	
	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		//Drawing
		ClearBackground(colorMap[BasicColor::Blue]);
		
		/*myMap.drawAllObstacles();*/
		game.draw();
		game.update();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


