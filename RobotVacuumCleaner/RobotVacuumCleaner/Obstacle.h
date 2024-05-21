#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "MapObject.h"
#include <stdexcept>

class Obstacle : public MapObject {
private:
    float width;
    float length;

public:
    Obstacle(float x, float y, IDType ID, float width, float length);

    float getWidth() const;
    float getLength() const;

    void setWidth(float newWidth);
    void setLength(float newLength);

    void displayInfo() const override;
};

#endif // OBSTACLE_H

