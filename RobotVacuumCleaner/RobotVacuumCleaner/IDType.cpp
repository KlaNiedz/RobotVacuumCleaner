#include "IDType.h"

std::ostream& operator<<(std::ostream& os, const IDType& idtype)
{
    switch (idtype)
    {
    case IDType::Dirty:
        os << 0;
        break;
    case IDType::Clean:
        os << 1;
        break;
    case IDType::ChargingStation:
        os << 2;
        break;
    case IDType::Obstacle:
        os << 3;
        break;
    case IDType::Benek:
        os << 4;
        break;
    }
    return os;
}
