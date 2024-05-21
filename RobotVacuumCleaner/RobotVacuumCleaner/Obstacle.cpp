#include "Obstacle.h"
#include <iostream>

Obstacle::Obstacle(float x, float y, IDType ID, float width, float length)
    : MapObject(x, y, ID)
{
    setLength(length);
    setWidth(width);
}

float Obstacle::getWidth() const {
    return width;
}

float Obstacle::getLength() const {
    return length;
}

void Obstacle::setWidth(float newWidth) {
    if (newWidth <= 0) {
        throw std::invalid_argument("Width must be a positive value.");
    }
    width = newWidth;
}

void Obstacle::setLength(float newLength) {
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
