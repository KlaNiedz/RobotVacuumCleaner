#pragma once
#include <iostream>
#include <vector>
#include "ChargingStation.h"
class Map
{
private:
	int** MapArray;
	int Height;
	int Width;
	/*std::vector<Obstacle> Obstacles;*/
	ChargingStation Char_stat;
public:
	Map(int height, int width, ChargingStation Char_stat);
	~Map();
	void showMap();
};

