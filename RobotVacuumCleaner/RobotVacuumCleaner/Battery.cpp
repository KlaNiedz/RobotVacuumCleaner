#include "Battery.h"

Battery::Battery(int initialLevel)
{
    setLevel(initialLevel);
}

int Battery::getLevel() const {
    return level;
}

void Battery::setLevel(int newLevel) {
    if (newLevel < 0 || newLevel > 100) {
        throw std::invalid_argument("Battery level must be between 0.0 and 100.0.");
    }
    level = newLevel;
}
