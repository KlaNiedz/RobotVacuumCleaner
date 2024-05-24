#include "Game.h"
#include "Robot.h"

void Game::draw()
{
	myMap.drawAllObstacles();
	myRobot.draw();
}

void Game::update()
{
	myRobot.update();
}