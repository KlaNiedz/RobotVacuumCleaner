#include "FrontSensor.h"

FrontSensor::FrontSensor(int x, int y, Direction h, int r, Map m) : Sensor(x, y, h, r, m) {}

bool FrontSensor::obstacle_in_range() const {
	get_map().
}