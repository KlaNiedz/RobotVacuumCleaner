#pragma once
#include "Map.h"
#include "Robot.h"
#include "Game.h"

class TerminalGame : public Game {
public:
	Map myMap = Map(350, 350);
	Robot myRobot = Robot(&myMap);

	void draw() override;
	void run() override;
};