#include "MapObject.h"

MapObject::MapObject(int x, int y, IDType ID)
{
    setX(x);
    setY(y);
    setID(ID);
}

MapObject::~MapObject() {}

int MapObject::getX() const {
    return x;
}

int MapObject::getY() const {
    return y;
}

IDType MapObject::getID() const {
    return ID;
}

void MapObject::setX(int newX) {
    x = newX;
}

void MapObject::setY(int newY) {
    y = newY;
}

void MapObject::setID(IDType newID) {
    ID = newID;
}
