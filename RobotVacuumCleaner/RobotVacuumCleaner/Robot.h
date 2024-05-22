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
	Robot(
		int x = 0, 
		int y = 0, 
		Direction h = Direction::North,
		IDType r = IDType::Benek,
		Battery b = Battery(),
		Filter f = Filter(),
		FrontSensor fs = FrontSensor(),
		RightSideSensor rs = RightSideSensor(),
		LeftSideSensor ls = LeftSideSensor()
	);
};