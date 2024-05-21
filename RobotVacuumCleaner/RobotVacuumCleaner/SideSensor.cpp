#include "SideSensor.h"

SideSensor::SideSensor(int x, int y, Direction h, int r, Map m) : Sensor(x, y, h, r, m) {}

bool SideSensor::obstacle_in_range() const = 0;