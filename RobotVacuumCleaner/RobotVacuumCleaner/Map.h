#pragma once
#include <iostream>
#include <vector>
#include "Obstacle.h"
#include "IDType.h"
#include "ChargingStation.h"
class Map
{
private:
	int** MapArray;
	int Height;
	int Width;
	std::vector<Obstacle> Obstacles;
	ChargingStation CharStat;
public:
	Map(int height = 200, int width = 200);
	~Map();
	int getXY(int y_cor, int x_cor) const;
	int getHeight() const;
	int getWidth() const;
	void setXY(int y_cor, int x_cor, int repr);
	void setHeightandWidth(int width, int height);
	void showMap();
	void generateObstacles();
	int calcEmpty(int col, int length);
};

