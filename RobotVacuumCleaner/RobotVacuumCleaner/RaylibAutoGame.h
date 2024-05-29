#pragma once
#pragma once
#include "Map.h"
#include "Robot.h"
#include "RaylibGame.h"

class RaylibAutoGame : public RaylibGame {
public:
	void movement() override;
};