#pragma once
#include "Sensor.h"
class SideSensor : public Sensor {
public:
	SideSensor(int x, int y, Direction h, int r, Map map);

	bool obstacle_in_range() const override;
};