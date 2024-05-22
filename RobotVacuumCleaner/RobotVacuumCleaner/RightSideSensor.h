#pragma once
#include "SideSensor.h"

class RightSideSensor : public SideSensor {
public:
	RightSideSensor(Map m = Map(), int x = 0, int y = 0, Direction h = Direction::North, int r = 1);

	bool obstacle_in_range() const override;
	bool wall_detected() const override;
	bool dirt_detected() const override;
};