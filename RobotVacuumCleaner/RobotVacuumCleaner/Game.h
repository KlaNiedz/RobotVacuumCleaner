#pragma once
#include "Map.h"
#include "Robot.h"
//#include "raylib.h"

class Game
{
public:
	Map myMap = Map(350, 350);
	Robot myRobot = Robot(&myMap);

	void draw();
	void update();
};