// RobotVacuumCleaner.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Map.h"
#include "raylib.h"
#include "Constants.h"
#include "RaylibManualGame.h"
#include "TerminalManualGame.h"



int main()
{

	 TerminalManualGame game = TerminalManualGame();

	// generating map in terminal
	/*game.myMap.showMap();*/
	
	game.run();
	return 0;
}


