#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "MapObject.h"
#include <stdexcept>

class Obstacle : public MapObject {
private:
    int width;
    int length;

public:
    Obstacle(int x, int y, IDType ID, int width, int length);

    int getWidth() const;
    int getLength() const;

    void setWidth(int newWidth);
    void setLength(int newLength);

    void displayInfo() const override;
    void draw();
};

#endif // OBSTACLE_H

