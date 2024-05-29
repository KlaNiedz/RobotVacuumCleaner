#include "RaylibAutoGame.h"
#include <chrono>
#include <thread>

void RaylibAutoGame::movement() {
	if (myRobot.get_f_sensor().wall_detected() || myRobot.get_f_sensor().get_dist_to_stop() == 0) {
		if (myRobot.get_heading() == Direction::East || myRobot.get_heading() == Direction::North)
			myRobot.turn_right_back();
		else {
			myRobot.turn_left_back();
		}
	}
	else {
		myRobot.take_step();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
