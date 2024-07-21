#include "Obstacle.h"
#include <iostream>
#include "raylib.h"
#include "Constants.h"

Obstacle::Obstacle(int x, int y, IDType ID, int width, int length)
    : MapObject(x, y, ID)
{
    setLength(length);
    setWidth(width);
}

int Obstacle::getWidth() const {
    return width;
}

int Obstacle::getLength() const {
    return length;
}

void Obstacle::setWidth(int newWidth) {
    if (newWidth <= 0) {
        throw std::invalid_argument("Width must be a positive value.");
    }
    width = newWidth;
}

void Obstacle::setLength(int newLength) {
    if (newLength <= 0) {
        throw std::invalid_argument("Length must be a positive value.");
    }
    length = newLength;
}

void Obstacle::displayInfo() const {
    std::cout << "Obstacle ID: " << static_cast<int>(getID())
        << " at (" << getX() << ", " << getY() << ")"
        << " with width: " << getWidth()
        << " and length: " << getLength() << std::endl;
}

void Obstacle::draw()
{
    DrawRectangle(x*cell_size, y*cell_size, cell_size, cell_size, colorMap[BasicColor::Violet]);
}
