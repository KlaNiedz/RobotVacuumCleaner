#include "MapObject.h"

MapObject::MapObject(float x, float y, IDType ID)
{
    setX(x);
    setY(y);
    setID(ID);
}

MapObject::~MapObject() {}

float MapObject::getX() const {
    return x;
}

float MapObject::getY() const {
    return y;
}

IDType MapObject::getID() const {
    return ID;
}

void MapObject::setX(float newX) {
    x = newX;
}

void MapObject::setY(float newY) {
    y = newY;
}

void MapObject::setID(IDType newID) {
    ID = newID;
}
