#include "TerminalGame.h"

void TerminalGame::draw() {
	myMap.showMap();
}

void TerminalGame::run() {
	while (true) {
		draw();
		movement();
	}
}