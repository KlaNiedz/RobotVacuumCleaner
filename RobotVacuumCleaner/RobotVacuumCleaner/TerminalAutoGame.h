#pragma once
#include "Map.h"
#include "Robot.h"
#include "TerminalGame.h"

class TerminalAutoGame : public TerminalGame {
public:
	void movement() override;
};