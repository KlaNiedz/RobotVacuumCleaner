#pragma once
#include "Sensor.h"
class SideSensor : public Sensor {
protected:
	int x_coord, y_coord, range;
	Direction heading;
	Map map;
public:
	SideSensor(const Map& m = Map(), int x = 0, int y = 0, Direction h = Direction::North, int r = 1);

};