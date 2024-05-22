#include "Robot.h"

Robot::Robot(
	int x,
	int y,
	Direction h,
	IDType r,
	Battery b,
	Filter f,
	FrontSensor fs,
	RightSideSensor rs,
	LeftSideSensor ls)
	: x_coord(x), y_coord(y), heading(h), repr(r), battery(b), filter(f), front_sensor(fs), r_sensor(rs), l_sensor(ls) {}