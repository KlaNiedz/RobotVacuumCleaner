#pragma once
#include "Map.h"
#include "Robot.h"
//#include "raylib.h"

class Game
{
public:
	Map myMap = Map(350, 350);
	Robot myRobot = Robot(&myMap);

	virtual void draw() = 0;
	virtual void movement() = 0;
	virtual void run() = 0;
	void update();
};