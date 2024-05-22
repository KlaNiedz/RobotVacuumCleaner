#ifndef IDTYPE_H
#define IDTYPE_H
#include <iostream>

enum class IDType {
    Dirty = 0,
    Clean = 1,
    ChargingStation = 2,
    Obstacle = 3,
    Benek = 4
};


std::ostream& operator<<(std::ostream& os, const IDType& idtype);

#endif // IDTYPE_H

