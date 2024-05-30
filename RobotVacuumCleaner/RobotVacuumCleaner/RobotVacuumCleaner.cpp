// RobotVacuumCleaner.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Map.h"
#include "raylib.h"
#include "Constants.h"
#include "RaylibManualGame.h"
#include "TerminalManualGame.h"
#include "RaylibAutoGame.h"
#include "TerminalAutoGame.h"



int main()
{
	int choice1, choice2;
	std::cout << "Do you want to see game in terminal on graphic design? If Graphic type 1, if in Terminal type 2: " << std::endl;
	std::cin >> choice1;
	std::cout << "If you want to control the robot manually - type 1, if you want the robot to move automatically - type 2: " << std::endl;
	std::cin >> choice2;
	if (choice1 == 1 && choice2 == 1)
	{
		RaylibManualGame game = RaylibManualGame();
		game.run();
	}
	else if (choice1 == 2 && choice2 == 1)
	{
		TerminalManualGame game = TerminalManualGame();
		game.run();
	}
	else if (choice1 == 1 && choice2 == 2)
	{
		RaylibAutoGame game = RaylibAutoGame();
		game.run();
	}
	else if (choice1 == 2 && choice2 == 2)
	{
		TerminalAutoGame game = TerminalAutoGame();
		game.run();
	}
	else
	{
		std::cout << "Invalid input. If Graphic type 1, if in Terminal type 2: " << std::endl;
	}

	return 0;
}