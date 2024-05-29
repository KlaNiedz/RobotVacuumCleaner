#pragma once
#include "Map.h"
#include "Robot.h"
#include "Game.h"

class RaylibGame : public Game {
public:
	Map myMap = Map(350, 350);
	Robot myRobot = Robot(&myMap);

	void draw() override;
	void run() override;
};