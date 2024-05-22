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

int Robot::get_x() const { return x_coord; }
int Robot::get_y() const { return y_coord; }
Direction Robot::get_heading() const { return heading; }
IDType Robot::get_repr() const { return repr; }
Battery Robot::get_battery() const { return battery; }
Filter Robot::get_filter() const { return filter; }
FrontSensor Robot::get_f_sensor() const { return front_sensor; }
RightSideSensor Robot::get_r_sensor() const { return r_sensor; }
LeftSideSensor Robot::get_l_sensor() const { return l_sensor; }


void Robot::set_x(int new_x) { x_coord = new_x; }
void Robot::set_y(int new_y) { y_coord = new_y; }
void Robot::set_heading(Direction new_heading) { heading = new_heading; }
void Robot::set_repr(IDType new_repr) { repr = new_repr; }
void Robot::set_battery(Battery new_battery) { battery = new_battery; }
void Robot::set_filter(Filter new_filter) { filter = new_filter; }
void Robot::set_f_sensor(FrontSensor new_f_sensor) { front_sensor = new_f_sensor; }
void Robot::set_r_sensor(RightSideSensor new_r_sensor) { r_sensor = new_r_sensor; }
void Robot::set_l_sensor(LeftSideSensor new_l_sensor) { l_sensor = new_l_sensor; }