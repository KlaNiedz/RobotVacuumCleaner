#include "RaylibAutoGame.h"

void RaylibAutoGame::movement() {
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
