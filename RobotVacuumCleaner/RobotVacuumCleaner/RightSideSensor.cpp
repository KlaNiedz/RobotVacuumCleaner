#include "RightSideSensor.h"

RightSideSensor::RightSideSensor(int x, int y, Direction h, int r, Map m) : SideSensor(x, y, h, r, m) {}

bool RightSideSensor::obstacle_in_range() const {
	int range;
	switch (get_heading())
	{
	case Direction::West :
		if (get_y() - get_range() < 0) {
			range = get_y();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y() - i, get_x()) == 3) {	
				return true;
			}
		}
		return false;
		break;
	case Direction::North :
		if (get_x() + get_range() > get_map().getWidth()) {
			range = get_map().getWidth() - get_x();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y(), get_x()+i) == 3) {
				return true;
			}
		}
		return false;
		break;
	case Direction::East :
		if (get_y() + get_range() > get_map().getHeight()) {
			range = get_map().getHeight() - get_y();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y() + i, get_x()) == 3) {
				return true;
			}
		}
		return false;
		break;
	case Direction::South :
		if (get_x() - get_range() < 0) {
			range = get_x();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y(), get_x() - i) == 3) {
				return true;
			}
		}
		return false;
		break;
	default:
		break;
	}
}