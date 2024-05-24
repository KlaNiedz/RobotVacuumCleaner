#include "Robot.h"
#include "raylib.h"
#include "raymath.h"
#include "Constants.h"

Robot::Robot(
	Map* map,
	int x,
	int y,
	Direction h,
	IDType r,
	Battery b,
	Filter f
	//FrontSensor fs,
	//RightSideSensor rs,
	//LeftSideSensor ls,
	)
	: map(map), x_coord(x), y_coord(y), heading(h), repr(r), battery(b), filter(f), front_sensor(*map, x, y, h), r_sensor(*map, x, y, h), l_sensor(*map, x, y, h, 3)
{
	if (map == nullptr)
	{
		throw std::invalid_argument("Map cannot be null");
	}
	if (x_coord < 0 || x_coord >= map->getWidth() || y_coord < 0 || y_coord >= map->getHeight())
	{
		throw std::out_of_range("Robot coordinates out of bounds");
	}
	update_sensors();
}

int Robot::get_x() const { return x_coord; }
int Robot::get_y() const { return y_coord; }
Direction Robot::get_heading() const { return heading; }
IDType Robot::get_repr() const { return repr; }
Battery Robot::get_battery() const { return battery; }
Filter Robot::get_filter() const { return filter; }
//FrontSensor Robot::get_f_sensor() const { return front_sensor; }
//RightSideSensor Robot::get_r_sensor() const { return r_sensor; }
//LeftSideSensor Robot::get_l_sensor() const { return l_sensor; }


void Robot::set_x(int new_x) { x_coord = new_x; }
void Robot::set_y(int new_y) { y_coord = new_y; }
void Robot::set_heading(Direction new_heading) { heading = new_heading; }
void Robot::set_repr(IDType new_repr) { repr = new_repr; }
void Robot::set_battery(Battery new_battery) { battery = new_battery; }
void Robot::set_filter(Filter new_filter) { filter = new_filter; }
//void Robot::set_f_sensor(FrontSensor new_f_sensor) { front_sensor = new_f_sensor; }
//void Robot::set_r_sensor(RightSideSensor new_r_sensor) { r_sensor = new_r_sensor; }
//void Robot::set_l_sensor(LeftSideSensor new_l_sensor) { l_sensor = new_l_sensor; }

void Robot::update_sensors() {
	//get_f_sensor().update_position(get_x(), get_y(), get_heading());
	//get_l_sensor().update_position(get_x(), get_y(), get_heading());
	//get_r_sensor().update_position(get_x(), get_y(), get_heading());
	front_sensor.update_position(x_coord, y_coord, heading);
	l_sensor.update_position(x_coord, y_coord, heading);
	r_sensor.update_position(x_coord, y_coord, heading);
}

bool Robot::take_step() {
	update_sensors();
	if (front_sensor.wall_detected() && front_sensor.get_dist_to_stop() == 0) {
		return false;
	}
	else {
		switch (get_heading()) {
		case Direction::North:
			set_y(get_y() - 1);
			break;
		case Direction::South:
			set_y(get_y() + 1);
			break;
		case Direction::East:
			set_x(get_x() + 1);
			break;
		case Direction::West:
			set_x(get_x() - 1);
			break;
		}
		discharge_battery();
		fill_filter();
		return true;
	}
}

void Robot::turn_left() {
	switch (get_heading()) {
	case Direction::North:
		set_heading(Direction::West);
		break;
	case Direction::South:
		set_heading(Direction::East);
		break;
	case Direction::East:
		set_heading(Direction::North);
		break;
	case Direction::West:
		set_heading(Direction::South);
		break;
	}
}

void Robot::turn_right() {
	switch (get_heading()) {
	case Direction::North:
		set_heading(Direction::East);
		break;
	case Direction::South:
		set_heading(Direction::West);
		break;
	case Direction::East:
		set_heading(Direction::South);
		break;
	case Direction::West:
		set_heading(Direction::North);
		break;
	}
}

void Robot::move(int new_x, int new_y)
{
	if (new_x < 0 || new_x >= map->getWidth() || new_y < 0 || new_y >= map->getHeight())
	{
		throw std::out_of_range("New coordinates out of bounds");
	}
	if (map->getXY(new_y, new_x) != IDType::Dirty)
	{
		throw std::runtime_error("Cannot move robot to a non-empty cell");
	}
	map->placeObject(y_coord, x_coord, IDType::Dirty); // Clear old position
	x_coord = new_x;
	y_coord = new_y;
	map->placeObject(y_coord, x_coord, repr); // Place robot in new position
}


void Robot::discharge_battery() {
	// Roz³adowanie baterii o pewn¹ wartoœæ za ka¿dy krok
	int current_level = battery.getLevel();
	if (current_level > 0) {
		battery.setLevel(current_level - 1);
	}
}

bool Robot::battery_low() {
	return battery.getLevel() <= 15;
}

void Robot::fill_filter() {
	int current_level = filter.getFillLevel();
	if (current_level < 100) {
		filter.setFillLevel(current_level + 1);
	}
}

void Robot::place_on_map()
{
	map->placeObject(y_coord, x_coord, repr);
}

void Robot::draw()
{
	/*DrawCircle((x_coord +)*cell_size*cell_size, (y_coord + 10)*cell_size, cell_size, colorMap[BasicColor::Pink]);*/
	Rectangle segment = Rectangle{ static_cast<float>(x_coord * cell_size),  static_cast<float>(y_coord * cell_size),  static_cast<float>(cell_size),  static_cast<float>(cell_size) };
	DrawRectangleRounded(segment, 0.5, 6, colorMap[BasicColor::Grey]);
}

void Robot::move_right()
{
	body = Vector2Add(body, direction_right);
	map->clean(x_coord, y_coord);
	x_coord = body.x;
	y_coord = body.y;
	place_on_map();

}

void Robot::move_left()
{
	body = Vector2Add(body, direction_left);
	map->clean(x_coord, y_coord);
	x_coord = body.x;
	y_coord = body.y;
	place_on_map();
}

void Robot::move_up()
{
	body = Vector2Add(body, direction_up);
	map->clean(x_coord, y_coord);
	x_coord = body.x;
	y_coord = body.y;
	place_on_map();
}

void Robot::move_down()
{
	body = Vector2Add(body, direction_down);
	map->clean(x_coord, y_coord);
	x_coord = body.x;
	y_coord = body.y;
	place_on_map();
}


bool Robot::filter_fullfilled() {
	return filter.getFillLevel() >= 85;
}

void Robot::charge_battery(const ChargingStation& charging_station) {
	if (get_x() == charging_station.getX() && get_y() == charging_station.getY()) {
		battery.setLevel(100);
	}
}

void Robot::empty_filter(const ChargingStation& charging_station) {
	if (get_x() == charging_station.getX() && get_y() == charging_station.getY()) {
		filter.setFillLevel(0);
	}
}
