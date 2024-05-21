#pragma once
#include "SideSensor.h"

class RightSideSensor : public SideSensor {
public:
	RightSideSensor(int x, int y, Direction h, int r, Map m);

	bool obstacle_in_range() const override;
	bool wall_detected() const override;
	bool dirt_detected() const override;
};