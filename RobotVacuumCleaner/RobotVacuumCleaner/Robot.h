#pragma once
#include "Map.h"
#include "Direction.h"
#include "IDType.h"
#include "Battery.h"
#include "Filter.h"
#include "Sensor.h"
#include "FrontSensor.h"
#include "RightSideSensor.h"
#include "LeftSideSensor.h"
#include "raylib.h"


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
	Map* map;
	
public:
	Robot(
		Map* map,
		int x = 0,
		int y = 0,
		Direction h = Direction::North,
		IDType r = IDType::Benek,
		Battery b = Battery(),
		Filter f = Filter()
		//FrontSensor fs = FrontSensor(),
		//RightSideSensor rs = RightSideSensor(),
		//LeftSideSensor ls = LeftSideSensor(), 
	);

	Vector2 body = { static_cast<float>(x_coord), static_cast<float>(y_coord)};
	Vector2 direction = { 1, 0 };


	/*Robot(int x, int y, Direction h, IDType r, Battery b, Filter f, FrontSensor fs, RightSideSensor rs, LeftSideSensor ls, Map* map);*/
	//Robot(int x, int y, Direction h, IDType r, Battery b, Filter f, Map* map);

	//Gettery
	int get_x() const;
	int get_y() const;
	Direction get_heading() const;
	IDType get_repr() const;
	Battery get_battery() const;
	Filter get_filter() const;
	//FrontSensor get_f_sensor() const;
	//RightSideSensor get_r_sensor() const;
	//LeftSideSensor get_l_sensor() const;

	//Setters
	void set_x(int new_x);
	void set_y(int new_y);
	void set_heading(Direction new_heading);
	void set_repr(IDType new_repr);
	void set_battery(Battery new_battery);
	void set_filter(Filter new_filter);
	//void set_f_sensor(FrontSensor new_f_sensor);
	//void set_r_sensor(RightSideSensor new_r_sensor);
	//void set_l_sensor(LeftSideSensor new_l_sensor);

	void update_sensors();

	//Ruch
	bool take_step();
	void turn_right();
	void turn_left();
	void move(int new_x, int new_y);

	//Bateria 
	void discharge_battery();
	bool battery_low();
	void charge_battery(const ChargingStation& charging_station);

	//Filtr
	bool filter_fullfilled();
	void empty_filter(const ChargingStation& charging_station);
	void fill_filter();

	void place_on_map();
	void draw();
	void update();
};