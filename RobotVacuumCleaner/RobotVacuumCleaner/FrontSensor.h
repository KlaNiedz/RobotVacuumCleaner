#pragma once
#include "Sensor.h"

class FrontSensor : public Sensor {
public:
	FrontSensor(Map m = Map(), int x = 0, int y = 0, Direction h = Direction::North, int r = 3);

	int get_dist_to_stop() const;

	bool obstacle_in_range() const override;
	bool wall_detected() const override;
	bool dirt_detected() const override;
};