#include "Filter.h"

Filter::Filter(int initialFillLevel) 
{
    setFillLevel(initialFillLevel);
}

int Filter::getFillLevel() const {
    return fillLevel;
}

void Filter::setFillLevel(int newFillLevel) {
    if (newFillLevel < 0 || newFillLevel > 100) {
        throw std::invalid_argument("Fill level must be between 0 and 100.");
    }
    fillLevel = newFillLevel;
}

