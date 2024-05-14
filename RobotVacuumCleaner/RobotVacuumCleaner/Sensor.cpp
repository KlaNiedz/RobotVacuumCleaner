#include "Sensor.h"

Sensor::Sensor(int x, int y, Direction h, int r) {
	x_coord = x;
	y_coord = y;
	heading = h;
	range = r;
}

int Sensor::get_x() const {
	return x_coord;
}

int Sensor::get_y() const {
	return y_coord;
}

int Sensor::get_range() const {
	return range;
}

Direction Sensor::get_heading() const {
	return heading;
}

void Sensor::set_x(int new_x) {
	x_coord = new_x;
}

void Sensor::set_y(int new_y) {
	y_coord = new_y;
}

void Sensor::set_range(int new_range) {
	range = new_range;
}

void Sensor::set_heading(Direction new_heading) {
	heading = new_heading;
}

bool Sensor::update_position(int current_x, int current_y, Direction current_heading) {
	set_x(current_x);
	set_y(current_y);
	set_heading(current_heading);
	return true;
}