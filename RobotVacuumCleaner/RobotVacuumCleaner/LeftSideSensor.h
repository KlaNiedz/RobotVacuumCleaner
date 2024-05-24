#pragma once
#include "SideSensor.h"

class LeftSideSensor : public SideSensor {
//protected:
//	int x_coord, y_coord, range;
//	Direction heading;
//	Map map;
public:
	LeftSideSensor(const Map& m, int x = 0, int y = 0, Direction h = Direction::North, int r = 1);

	bool obstacle_in_range() const override;
	bool wall_detected() const override;
	bool dirt_detected() const override;
};