#include "RaylibManualGame.h"

void RaylibManualGame::movement() {
	if (IsKeyPressed(KEY_RIGHT))
	{
		myRobot.go_right();
	}
	else if (IsKeyPressed(KEY_LEFT))
	{
		myRobot.go_left();
	}
	else if (IsKeyPressed(KEY_UP))
	{
		myRobot.go_up();
	}
	else if (IsKeyPressed(KEY_DOWN))
	{
		myRobot.go_down();
	}
}