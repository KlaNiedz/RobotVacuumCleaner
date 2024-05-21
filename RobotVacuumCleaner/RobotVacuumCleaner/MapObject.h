#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "IDType.h"

class MapObject {
protected:
    int x;
    int y;
    IDType ID;

public:
    MapObject(int x, int y, IDType ID);

    virtual ~MapObject();

    virtual void displayInfo() const = 0;

    int getX() const;
    int getY() const;
    IDType getID() const;

    void setX(int newX);
    void setY(int newY);
    void setID(IDType newID);
};

#endif // MAPOBJECT_H
