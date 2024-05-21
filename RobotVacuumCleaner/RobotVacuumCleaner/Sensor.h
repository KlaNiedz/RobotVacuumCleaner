#pragma once
#include "Direction.h"
#include "Map.h"

class Sensor {
	///		Bazowa klasa Sensor ma stale pobiera� po�o�enie (x, y) oraz zwrot robota (z osobnej klasy "modu� GPS"???).
	/// 	Na podstawie po�o�enia i zwrotu:
	///			1) FrontSensor 
	///				- bedzie wiedzia�, czy w jego zasi�gu znajduje sie przeszkoda,
	///				- bedzie oblicza� odleg�o�� do w.w. przeszkody,
	///				- w razie minimalnej odleg�o�ci wy�le do robota sygna� STOP,
	///			2) SideSensor
	///				- b�dzie wiedzia�, czy w jego zasi�gu jest przeszkoda (tu� obok robota),
	///				- b�dzie zwraca� informacj� typu bool ("Czy po bokach jest pusto?"),
	///				- mo�na doda� kolejne dziedziczenie (Right Side Sensor i Left Side Sensor)
	/// 	Za pomoc� tych czujnik�w Benek b�dzie m�g� stosowa� manewry omijania i zawracania.
private:
	int x_coord, y_coord, range;
	Direction heading;
	Map map;
public:
	//Constructor
	Sensor(int x, int y, Direction h, int r, Map m);

	//Virtual deconstructor
	virtual ~Sensor() {};

	//Getters
	int get_x() const;
	int get_y() const;
	int get_range() const;
	Direction get_heading() const;
	Map get_map() const;

	//Setters
	void set_x(int);
	void set_y(int);
	void set_range(int);
	void set_heading(Direction);
	void set_map(Map);

	bool update_position(int, int, Direction);

	virtual int get_dist_to_stop() const = 0;

	virtual bool obstacle_in_range() const = 0;

	virtual bool wall_detected() const = 0;
};