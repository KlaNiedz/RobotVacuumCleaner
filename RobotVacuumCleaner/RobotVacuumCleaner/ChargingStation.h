#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include "MapObject.h"

class ChargingStation : public MapObject {
public:
    ChargingStation(float x, float y, IDType ID);

    void displayInfo() const override;
};

#endif // CHARGINGSTATION_H

