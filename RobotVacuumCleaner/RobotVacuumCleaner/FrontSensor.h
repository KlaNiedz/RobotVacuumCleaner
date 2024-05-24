#pragma once
#include "Sensor.h"
#include "Direction.h"
#include "IDType.h"
#include "Map.h"

class FrontSensor : public Sensor {
//protected:
//	int x_coord, y_coord, range;
//	Direction heading;
//	Map map;
public:
	FrontSensor(const Map& m, int x = 0, int y = 0, Direction h = Direction::North, int r = 3);
	FrontSensor& operator=(const FrontSensor&) = delete;
	int get_dist_to_stop() const;

	bool obstacle_in_range() const override;
	bool wall_detected() const override;
	bool dirt_detected() const override;
};