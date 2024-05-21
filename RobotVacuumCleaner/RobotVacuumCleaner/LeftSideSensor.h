#pragma once
#pragma once
#include "SideSensor.h"

class LeftSideSensor : public SideSensor {
public:
	LeftSideSensor(int x, int y, Direction h, int r, Map m);

	bool obstacle_in_range() const override;
};