#include "TerminalManualGame.h"
#include <iostream>

void TerminalManualGame::movement() {
	char move;
	std::cout << "Next move: ";
	std::cin >> move;
	if (move == 'd' || move == 'D') 
	{
		myRobot.go_right();
	}
	else if (move == 'a' || move == 'A')
	{
		myRobot.go_left();
	}
	else if (move == 'w' || move == 'W')
	{
		myRobot.go_up();
	}
	else if (move == 's' || move == 'S')
	{
		myRobot.go_down();
	}
}