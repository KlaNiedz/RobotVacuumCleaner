#include "Robot.h"
#include "raylib.h"
#include "raymath.h"
#include "Constants.h"
#include <thread>
#include <chrono>
Robot::Robot(
	Map* map,
	int x,
	int y,
	Direction h,
	IDType r,
	Battery b,
	Filter f,
	int sc,
	FrontSensor fs,
	RightSideSensor rs,
	LeftSideSensor ls
	)
	: map(map), x_coord(x), y_coord(y), heading(h), repr(r), battery(b), filter(f),step_count(sc), front_sensor(*map, x, y, h, 3), r_sensor(*map, x, y, h, 1), l_sensor(*map, x, y, h, 1)
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
int Robot::get_step_count() { return step_count; }
FrontSensor Robot::get_f_sensor() { return front_sensor; }
RightSideSensor Robot::get_r_sensor() { return r_sensor; }
LeftSideSensor Robot::get_l_sensor() { return l_sensor; }


void Robot::set_x(int new_x) { x_coord = new_x; }
void Robot::set_y(int new_y) { y_coord = new_y; }
void Robot::set_heading(Direction new_heading) { heading = new_heading; }
void Robot::set_repr(IDType new_repr) { repr = new_repr; }
void Robot::set_battery(Battery new_battery) { battery = new_battery; }
void Robot::set_filter(Filter new_filter) { filter = new_filter; }
void Robot::set_step_count(int new_sc) { step_count = new_sc; }
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

void Robot::go_up() {
	set_heading(Direction::North);
	update_sensors();
	if (! front_sensor.wall_detected() && front_sensor.get_dist_to_stop() > 0 && battery.getLevel() > 0) {
		move_up();
	}
	else {
		std::cout << "Cannot move up!!!" << std::endl;
	}
	
}

void Robot::go_down() {
	set_heading(Direction::South);
	update_sensors();
	if (!front_sensor.wall_detected() && front_sensor.get_dist_to_stop() > 0 && battery.getLevel() > 0) {
		move_down();
	}
	else {
		std::cout << "Cannot move down!!!" << std::endl;
	}
}

void Robot::go_left() {
	set_heading(Direction::West);
	update_sensors();
	if (!front_sensor.wall_detected() && front_sensor.get_dist_to_stop() > 0 && battery.getLevel() > 0) {
		move_left();
	}
	else {
		std::cout << "Cannot move left!!!" << std::endl;
	}
}

void Robot::go_right() {
	set_heading(Direction::East);
	update_sensors();
	if (!front_sensor.wall_detected() && front_sensor.get_dist_to_stop() > 0 && battery.getLevel() > 0) {
		move_right();
	}
	else {
		std::cout << "Cannot move right!!!" << std::endl;
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
void Robot::make_pause() {
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void Robot::take_step() {
	switch (get_heading()) {
	case Direction::North:
		go_up();
		break;

	case Direction::East:
		go_right();
		break;

	case Direction::South:
		go_down();
		break;

	case Direction::West:
		go_left();
		break;
	}
	update_sensors();
	make_pause();
}

void Robot::turn_right() {
	switch (get_heading()) {
	case Direction::North:
		set_heading(Direction::East);
		break;

	case Direction::East:
		set_heading(Direction::South);
		break;

	case Direction::South:
		set_heading(Direction::West);
		break;

	case Direction::West:
		set_heading(Direction::North);
		break;
	}
	update_sensors();
}

void Robot::turn_left() {
	switch (get_heading()) {
	case Direction::North:
		set_heading(Direction::West);
		break;

	case Direction::East:
		set_heading(Direction::North);
		break;

	case Direction::South:
		set_heading(Direction::East);
		break;

	case Direction::West:
		set_heading(Direction::South);
		break;
	}
	update_sensors();
}

void Robot::turn_right_back() {
	turn_right();
	take_step();
	turn_right();
}

void Robot::turn_left_back() {
	turn_left();
	take_step();
	turn_left();
}

void Robot::avoid_obstacle() {
	int go_back = 0;
	turn_right();
	if (get_l_sensor().obstacle_in_range()) {
		take_step();
		go_back++;
	}
	else {
		turn_left();
		take_step();
		if (get_l_sensor().obstacle_in_range()) {
			take_step();
		}
		else {
			turn_left();
			if (go_back != 0) {
				take_step();
				go_back--;
			}
			else {
				turn_right();
			}
		}
	}
}

void Robot::come_back_to_base() {
	std::cout << "Coming back to the charging station...\n";
	if (get_x() != 0 && get_y() != 0) {
		set_heading(Direction::North);
		take_step();
		turn_left();
		take_step();
	}
	else if (get_x() == 0 && get_y() != 0) {
		set_heading(Direction::North);
		take_step();
	}
	else if (get_x() != 0 && get_y() == 0) {
		set_heading(Direction::West);
		take_step();
	}
}

void Robot::discharge_battery() {
	if (step_count % 2 == 0) { // Rozładowanie baterii co drugi krok
		int current_level = battery.getLevel();
		if (current_level > 0) {
			battery.setLevel(current_level - 1);
		}
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


void Robot::charge_battery() {
	battery.setLevel(100);
	std::cout << "Battery charged!\n";
}

void Robot::empty_filter() {
	filter.setFillLevel(0);
	std::cout << "Filter emptied!\n";
}

void Robot::place_on_map()
{
	IDType currentCellType = map->getXY(y_coord, x_coord);
	if (currentCellType != IDType::ChargingStation) {
		map->placeObject(y_coord, x_coord, repr);
	}
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
	int new_x = static_cast<int>(body.x);
	int new_y = static_cast<int>(body.y);

	IDType cellType = map->getXY(new_y, new_x);

	if (cellType == IDType::Dirty) {
		fill_filter(); // Fill filter if the cell is dirty
	}

	discharge_battery(); // Discharge battery

	if (cellType == IDType::ChargingStation) {
		charge_battery(); // Charge the battery
		empty_filter();
	}

	x_coord = new_x;
	y_coord = new_y;

	place_on_map();

	if (cellType != IDType::ChargingStation && filter.getFillLevel() < 100)
	{
		map->clean(x_coord, y_coord);
	}
	else if (cellType == IDType::ChargingStation) {
		map->placeObject(y_coord, x_coord, IDType::ChargingStation);
	}
	step_count++;
}

void Robot::move_left()
{
	body = Vector2Add(body, direction_left);
	int new_x = static_cast<int>(body.x);
	int new_y = static_cast<int>(body.y);

	IDType cellType = map->getXY(new_y, new_x);

	if (cellType == IDType::Dirty) {
		fill_filter(); // Fill filter if the cell is dirty
	}

	discharge_battery(); // Discharge battery

	if (cellType == IDType::ChargingStation) {
		charge_battery(); // Charge the battery
		empty_filter();
	}

	x_coord = new_x;
	y_coord = new_y;

	place_on_map();

	if (cellType != IDType::ChargingStation && filter.getFillLevel()<100) 
	{
		map->clean(x_coord, y_coord);
	}
	else if (cellType == IDType::ChargingStation) {
		map->placeObject(y_coord, x_coord, IDType::ChargingStation);
	}
	step_count++;

}

void Robot::move_up()
{
	body = Vector2Add(body, direction_up);
	int new_x = static_cast<int>(body.x);
	int new_y = static_cast<int>(body.y);

	IDType cellType = map->getXY(new_y, new_x);

	if (cellType == IDType::Dirty) {
		fill_filter(); // Fill filter if the cell is dirty
	}

	discharge_battery(); // Discharge battery

	if (cellType == IDType::ChargingStation) {
		charge_battery(); // Charge the battery
		empty_filter();
	}

	x_coord = new_x;
	y_coord = new_y;

	place_on_map();

	if (cellType != IDType::ChargingStation && filter.getFillLevel() < 100)
	{
		map->clean(x_coord, y_coord);
	}
	else if (cellType == IDType::ChargingStation) {
		map->placeObject(y_coord, x_coord, IDType::ChargingStation);
	}
	step_count++;

}

void Robot::move_down()
{
	body = Vector2Add(body, direction_down);
	int new_x = static_cast<int>(body.x);
	int new_y = static_cast<int>(body.y);

	IDType cellType = map->getXY(new_y, new_x);

	if (cellType == IDType::Dirty) {
		fill_filter(); // Fill filter if the cell is dirty
	}

	discharge_battery(); // Discharge battery

	if (cellType == IDType::ChargingStation) {
		charge_battery(); // Charge the battery
		empty_filter();
	}

	x_coord = new_x;
	y_coord = new_y;

	place_on_map();

	if (cellType != IDType::ChargingStation && filter.getFillLevel() < 100)
	{
		map->clean(x_coord, y_coord);
	}
	else if (cellType == IDType::ChargingStation) {
		map->placeObject(y_coord, x_coord, IDType::ChargingStation);
	}
	step_count++;

}


bool Robot::filter_fullfilled() {
	return filter.getFillLevel() >= 85;
}

