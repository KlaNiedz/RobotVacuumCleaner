#pragma once
#include "Direction.h"
#include "IDType.h"
#include "Battery.h"
#include "Filter.h"
#include "Sensor.h"
#include "FrontSensor.h"
#include "RightSideSensor.h"
#include "LeftSideSensor.h"

class Robot {
	int x_coord, y_coord;
	Direction heading;
	IDType repr;
	Battery battery;
	Filter filter;
	
	//Sensors
	FrontSensor front_sensor;
	RightSideSensor r_sensor;
	LeftSideSensor l_sensor;
	
public:
	Robot(int x, int y, Direction h, IDType repr, Battery b, Filter f, FrontSensor fs, RightSideSensor rs, LeftSideSensor ls);
};