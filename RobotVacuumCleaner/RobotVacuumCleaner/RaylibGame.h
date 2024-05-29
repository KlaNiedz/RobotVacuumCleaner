#pragma once
#include "Map.h"
#include "Robot.h"
#include "Game.h"

class RaylibGame : public Game {
public:

	void draw() override;
	void run() override;
};