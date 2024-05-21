#pragma once
#include "Direction.h"
class Robot {
	int x_coord, y_coord;
	Direction heading;
	//repr
	//battery
	//filter
	//sensors
public:
	Robot(int x, int y, Direction h);
};