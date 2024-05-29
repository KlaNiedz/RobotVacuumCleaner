#pragma once
#pragma once
#include "Map.h"
#include "Robot.h"
#include "RaylibGame.h"

class RaylibManualGame : public RaylibGame {
public:
	void movement() override;
};