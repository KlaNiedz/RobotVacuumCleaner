#pragma once
#include "Sensor.h"
class SideSensor : public Sensor {
public:
	SideSensor(Map m = Map(), int x = 0, int y = 0, Direction h = Direction::North, int r = 1);

};