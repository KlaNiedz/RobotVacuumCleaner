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
	int choice;
	std::cout << "Do you want to see game in terminal on graphic design? If Graphic type 1, if in Terminal type 2: " << std::endl;
	std::cin >> choice;
	if (choice == 1)
	{
		RaylibManualGame game = RaylibManualGame();
		game.run();
	}
	else if (choice == 2)
	{
		TerminalManualGame game = TerminalManualGame();
		game.run();
	}
	else
	{
		std::cout << "Invalid input. If Graphic type 1, if in Terminal type 2: " << std::endl;
	}

	return 0;
}


