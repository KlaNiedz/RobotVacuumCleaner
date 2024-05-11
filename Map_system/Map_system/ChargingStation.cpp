#include "ChargingStation.h"

ChargingStation::ChargingStation(int x, int y) {
	this->x = x;
	this->y = y;
}

int ChargingStation::getX() {
	return x;
}

int ChargingStation::getY() {
	return y;
}