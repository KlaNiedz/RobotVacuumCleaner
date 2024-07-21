#pragma once
#include "MapObject.h"
class CleanSquare :
    public MapObject
{
public:
    CleanSquare(int x, int y, IDType ID);
    void displayInfo() const override;
    void draw();
};

