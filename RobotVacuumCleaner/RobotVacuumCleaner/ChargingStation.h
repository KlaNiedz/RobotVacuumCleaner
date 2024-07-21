#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include "MapObject.h"

class ChargingStation : public MapObject {
public:
    ChargingStation(int x = 0, int y = 0, IDType ID = IDType::ChargingStation);

    void displayInfo() const override;
    void draw();
};

#endif // CHARGINGSTATION_H

