#pragma once
#include "Sensor.h"

class FrontSensor : public Sensor {
public:
	FrontSensor(int x, int y, Direction h, int r, Map map);

	int get_dist_to_stop() const override;

	bool obstacle_in_range() const override;
	bool wall_detected() const override;
	bool dirt_detected() const override;
};