#include "FrontSensor.h"

FrontSensor::FrontSensor(Map m, int x, int y, Direction h, int r = 3) : Sensor(m, x, y, h, r) {}

bool FrontSensor::obstacle_in_range() const {
	int range;
	switch (get_heading())
	{
	case Direction::North :
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
	case Direction::East :
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
	case Direction::South :
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
	case Direction::West :
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

int FrontSensor::get_dist_to_stop() const {
	if (obstacle_in_range()) {
		int distance = 0;
		switch (get_heading())
		{
		case Direction::North:			
			for (int i = 1; i <= get_range(); i++) {
				if (get_map().getXY(get_y() - i, get_x()) != 3) {
					distance += 1;
				}
				else return distance;
			}
			break;
		case Direction::East:
			for (int i = 1; i <= get_range(); i++) {
				if (get_map().getXY(get_y(), get_x() + i) != 3) {
					distance += 1;
				}
				else return distance;
			}
			break;
		case Direction::South:
			
			for (int i = 1; i <= get_range(); i++) {
				if (get_map().getXY(get_y() + i, get_x()) != 3) {
					distance += 1;
				}
				else return distance;
			}
			break;
		case Direction::West:
			
			for (int i = 1; i <= get_range(); i++) {
				if (get_map().getXY(get_y(), get_x() - i) != 3) {
					distance += 1;
				}
				else return distance;
			}
			break;
		default:
			break;
		}
	}
	else {
		return get_range();
	}
}

bool FrontSensor::wall_detected() const {
	switch (get_heading())
	{
	case Direction::North:
		if (get_y()==0) {
			return true;
		}
		return false;
		break;
	case Direction::East:
		if (get_x() == get_map().getWidth()) {
			return true;
		}
		return false;
		break;
	case Direction::South:
		if (get_y() == get_map().getHeight()) {
			return true;
		}
		return false;
		break;
	case Direction::West:
		if (get_x() == 0) {
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}

bool FrontSensor::dirt_detected() const {
	switch (get_heading())
	{
	case Direction::North:
		if (get_map().getXY(get_y()-1,get_x()) == 0) {// 0 - dirt, 1 - clean
			return true;
		}
		return false;
		break;
	case Direction::East:
		if (get_map().getXY(get_y(), get_x()+1) == 0) {
			return true;
		}
		return false;
		break;
	case Direction::South:
		if (get_map().getXY(get_y() + 1, get_x()) == 0) {
			return true;
		}
		return false;
		break;
	case Direction::West:
		if (get_map().getXY(get_y(), get_x()-1) == 0) {
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}