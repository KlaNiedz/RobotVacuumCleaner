#include "Game.h"
#include "Robot.h"

void Game::draw()
{
	myMap.drawAllObstacles();
	myMap.drawCleaned();
	myRobot.draw();
	
}

//void Game::update()
//{
//	myRobot.update();
//}