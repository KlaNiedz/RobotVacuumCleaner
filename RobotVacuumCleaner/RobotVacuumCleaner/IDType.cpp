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

int to_int(const IDType& idtype) {
    switch (idtype) {
    case IDType::Dirty: return 0;
    case IDType::Clean: return 1;
    case IDType::ChargingStation: return 2;
    case IDType::Obstacle: return 3;
    case IDType::Benek: return 4;
    default: return 9;
    }
}