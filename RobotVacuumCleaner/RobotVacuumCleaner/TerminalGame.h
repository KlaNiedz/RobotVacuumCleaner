#pragma once
#include "Map.h"
#include "Robot.h"
#include "Game.h"

class TerminalGame : public Game {
public:

	void draw() override;
	void run() override;
};