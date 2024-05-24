#pragma once
#include "Map.h"
#include "Direction.h"


class Sensor {
	///		Bazowa klasa Sensor ma stale pobieraæ po³o¿enie (x, y) oraz zwrot robota (z osobnej klasy "modu³ GPS"???).
	/// 	Na podstawie po³o¿enia i zwrotu:
	///			1) FrontSensor 
	///				- bedzie wiedzia³, czy w jego zasiêgu znajduje sie przeszkoda,
	///				- bedzie oblicza³ odleg³oœæ do w.w. przeszkody,
	///				- w razie minimalnej odleg³oœci wyœle do robota sygna³ STOP,
	///			2) SideSensor
	///				- bêdzie wiedzia³, czy w jego zasiêgu jest przeszkoda (tu¿ obok robota),
	///				- bêdzie zwraca³ informacjê typu bool ("Czy po bokach jest pusto?"),
	///				- mo¿na dodaæ kolejne dziedziczenie (Right Side Sensor i Left Side Sensor)
	/// 	Za pomoc¹ tych czujników Benek bêdzie móg³ stosowaæ manewry omijania i zawracania.
protected:
	const Map& map;
	int x_coord, y_coord, range;
	Direction heading;
	
public:
	//Constructor
	Sensor(const Map& m, int x = 0, int y = 0, Direction h = Direction::North, int r = 1);


	//Virtual deconstructor
	virtual ~Sensor() = default;

	//Getters
	int get_x() const;
	int get_y() const;
	int get_range() const;
	Direction get_heading() const;
	const Map& get_map() const;

	//Setters
	void set_x(int);
	void set_y(int);
	void set_range(int);
	void set_heading(Direction);
	/*void set_map(const Map&);*/

	void update_position(int, int, Direction);

	virtual bool obstacle_in_range() const = 0;

	virtual bool wall_detected() const = 0;

	virtual bool dirt_detected() const = 0;
};