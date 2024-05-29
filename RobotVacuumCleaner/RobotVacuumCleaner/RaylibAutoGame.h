#pragma once
#pragma once
#include "Map.h"
#include "Robot.h"
#include "RaylibGame.h"

class RaylibManualGame : public RaylibGame {
public:
	Map myMap = Map(350, 350);
	Robot myRobot = Robot(&myMap);

	void movement() override;
};