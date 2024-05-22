#ifndef FILTER_H
#define FILTER_H

#include <stdexcept>

class Filter {
private:
    int fillLevel;

public:
    Filter(int initialFillLevel = 0);

    int getFillLevel() const;
    void setFillLevel(int newFillLevel);
};

#endif // FILTER_H
