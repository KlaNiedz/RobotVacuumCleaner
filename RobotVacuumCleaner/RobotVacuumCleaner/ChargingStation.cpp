#include "ChargingStation.h"
#include <iostream>

ChargingStation::ChargingStation(float x, float y, IDType ID) : MapObject(x, y, ID) {}

void ChargingStation::displayInfo() const {
    std::cout << "Charging Station ID: " << static_cast<int>(getID()) << " at (" << getX() << ", " << getY() << ")" << std::endl;
}
