#include "LeftSideSensor.h"

LeftSideSensor::LeftSideSensor(Map m, int x, int y, Direction h, int r) : SideSensor(m, x, y, h, r) {}

bool LeftSideSensor::obstacle_in_range() const {
	int range;
	switch (get_heading())
	{
	case Direction::East:
		if (get_y() - get_range() < 0) {
			range = get_y();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y() - i, get_x()) == IDType::Obstacle) {
				return true;
			}
		}
		return false;
		break;
	case Direction::South:
		if (get_x() + get_range() > get_map().getWidth()) {
			range = get_map().getWidth() - get_x();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y(), get_x() + i) == IDType::Obstacle) {
				return true;
			}
		}
		return false;
		break;
	case Direction::West:
		if (get_y() + get_range() > get_map().getHeight()) {
			range = get_map().getHeight() - get_y();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y() + i, get_x()) == IDType::Obstacle) {
				return true;
			}
		}
		return false;
		break;
	case Direction::North:
		if (get_x() - get_range() < 0) {
			range = get_x();
		}
		else {
			range = get_range();
		}
		for (int i = 1; i <= range; i++) {
			if (get_map().getXY(get_y(), get_x() - i) == IDType::Obstacle) {
				return true;
			}
		}
		return false;
		break;
	default:
		break;
	}
}

bool LeftSideSensor::wall_detected() const {
	switch (get_heading())
	{
	case Direction::East:
		if (get_y() == 0) {
			return true;
		}
		return false;
		break;
	case Direction::South:
		if (get_x() == get_map().getWidth()) {
			return true;
		}
		return false;
		break;
	case Direction::West:
		if (get_y() == get_map().getHeight()) {
			return true;
		}
		return false;
		break;
	case Direction::North:
		if (get_x() == 0) {
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}

bool LeftSideSensor::dirt_detected() const {
	switch (get_heading())
	{
	case Direction::North:
		if (get_map().getXY(get_y(), get_x()-1) == IDType::Dirty) {// 0 - dirt, 1 - clean
			return true;
		}
		return false;
		break;
	case Direction::East:
		if (get_map().getXY(get_y()-1, get_x()) == IDType::Dirty) {
			return true;
		}
		return false;
		break;
	case Direction::South:
		if (get_map().getXY(get_y(), get_x()+1) == IDType::Dirty) {
			return true;
		}
		return false;
		break;
	case Direction::West:
		if (get_map().getXY(get_y()+1, get_x()) == IDType::Dirty) {
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}