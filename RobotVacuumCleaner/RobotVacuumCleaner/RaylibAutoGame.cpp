#include "RaylibAutoGame.h"

void RaylibAutoGame::movement() {
	switch (myRobot.get_heading()) {
	case Direction::North:
		if (myRobot.get_f_sensor().wall_detected() || myRobot.get_f_sensor().get_dist_to_stop() == 0) {
			myRobot.go_right();
		}
		else {
			myRobot.go_up();
		}
		break;

	case Direction::South:
		if (myRobot.get_f_sensor().wall_detected() || myRobot.get_f_sensor().get_dist_to_stop() == 0) {
			myRobot.go_left();
		}
		else {
			myRobot.go_down();
		}
		break;

	case Direction::East:
		if (myRobot.get_f_sensor().wall_detected() || myRobot.get_f_sensor().get_dist_to_stop() == 0) {
			myRobot.go_down();
		}
		else {
			myRobot.go_right();
		}
		break;

	case Direction::West:
		if (myRobot.get_f_sensor().wall_detected() || myRobot.get_f_sensor().get_dist_to_stop() == 0) {
			myRobot.go_up();
		}
		else {
			myRobot.go_left();
		}
		break;

	}
}
