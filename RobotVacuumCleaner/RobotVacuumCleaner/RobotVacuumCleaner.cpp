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
		ClearBackground(colorMap[BasicColor::DarkBrown]);
		
		/*myMap.drawAllObstacles();*/
		game.draw();

		if (IsKeyPressed(KEY_RIGHT))
		{
			game.myRobot.go_right();
		}
		else if (IsKeyPressed(KEY_LEFT))
		{
			game.myRobot.go_left();
		}
		else if (IsKeyPressed(KEY_UP))
		{
			game.myRobot.go_up();
		}
		else if (IsKeyPressed(KEY_DOWN))
		{
			game.myRobot.go_down();
		}
	
		//game.update();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


