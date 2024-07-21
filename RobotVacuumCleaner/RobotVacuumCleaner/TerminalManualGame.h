#pragma once
#include "Map.h"
#include "Robot.h"
#include "TerminalGame.h"

class TerminalManualGame : public TerminalGame {
public:
	void movement() override;
};