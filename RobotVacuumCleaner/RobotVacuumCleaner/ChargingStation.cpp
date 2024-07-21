#include "ChargingStation.h"
#include <iostream>
#include "raylib.h"
#include "Constants.h"

ChargingStation::ChargingStation(int x, int y, IDType ID) : MapObject(x, y, ID) {}

void ChargingStation::displayInfo() const {
    std::cout << "Charging Station ID: " << static_cast<int>(getID()) << " at (" << getX() << ", " << getY() << ")" << std::endl;
}

void ChargingStation::draw()
{
    DrawRectangle(x * cell_size, y * cell_size, cell_size, cell_size, colorMap[BasicColor::DarkBlue]);
}
