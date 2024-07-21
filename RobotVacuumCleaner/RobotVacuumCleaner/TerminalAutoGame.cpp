#include "TerminalAutoGame.h"
#include <iostream>

void TerminalAutoGame::movement() {
	if (myRobot.battery_low() || myRobot.filter_fullfilled()) {
		myRobot.come_back_to_base();
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