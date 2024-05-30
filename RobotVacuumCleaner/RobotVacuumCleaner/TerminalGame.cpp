#include "TerminalGame.h"

void TerminalGame::draw() {
	myMap.showMap();
}

void TerminalGame::run() {
	while (true) {
		draw();
		movement();
		if (myRobot.get_battery().getLevel() == 0) {
			std::cout << "Robot discharged completely! End of the simulation.\n";
			break;
		}
	}
}