#pragma once
#include "Map.h"
#include "Robot.h"
#include "TerminalGame.h"

class TerminalAutoGame : public TerminalGame {
public:
	//Map myMap = Map(350, 350);
	//Robot myRobot = Robot(&myMap);

	void movement() override;
};