#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "IDType.h"

class MapObject {
protected:
    float x;
    float y;
    IDType ID;

public:
    MapObject(float x, float y, IDType ID);

    virtual ~MapObject();

    virtual void displayInfo() const = 0;

    float getX() const;
    float getY() const;
    IDType getID() const;

    void setX(float newX);
    void setY(float newY);
    void setID(IDType newID);
};

#endif // MAPOBJECT_H
