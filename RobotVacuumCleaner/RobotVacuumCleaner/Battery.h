#ifndef BATTERY_H
#define BATTERY_H

#include <stdexcept>

class Battery {
private:
    int level;

public:
    Battery(int initialLevel = 100);

    int getLevel() const;
    void setLevel(int newLevel);
};

#endif // BATTERY_H

