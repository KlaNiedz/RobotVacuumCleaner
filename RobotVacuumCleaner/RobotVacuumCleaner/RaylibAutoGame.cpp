#include "RaylibAutoGame.h"

void RaylibAutoGame::movement() {
	if (myRobot.battery_low() || myRobot.filter_fullfilled()) {
		if (myRobot.get_x() != 0 && myRobot.get_y() != 0) {
				myRobot.set_heading(Direction::North);
				myRobot.take_step();
				myRobot.turn_left();
				myRobot.take_step();
		}
		else if (myRobot.get_x() == 0 && myRobot.get_y() != 0) {
			myRobot.set_heading(Direction::North);
			myRobot.take_step();
		}
		else if (myRobot.get_x() != 0 && myRobot.get_y() == 0) {
			myRobot.set_heading(Direction::West);
			myRobot.take_step();
		}
	}
	else {
		if (myRobot.get_f_sensor().wall_detected()) {
			if (myRobot.get_heading() == Direction::East || myRobot.get_heading() == Direction::North)
				myRobot.turn_right_back();
			else {
				myRobot.turn_left_back();
			}
		}
		else if (myRobot.get_f_sensor().get_dist_to_stop() == 0) {
			/*myRobot.avoid_obstacle();*/
			if (myRobot.get_heading() == Direction::East || myRobot.get_heading() == Direction::North)
				myRobot.turn_right_back();
			else {
				myRobot.turn_left_back();
			}
		}
		else {
			myRobot.take_step();
		}
	}
}
