#pragma once
#include <iostream>
#include <vector>
#include "Obstacle.h"
#include "IDType.h"
#include "ChargingStation.h"
class Map
{
private:
	IDType** MapArray;
	int Height;
	int Width;
	std::vector<Obstacle> Obstacles;
	ChargingStation CharStat;
public:
	Map(int height = 200, int width = 200);
	/*~Map();*/
	IDType getXY(int y_cor, int x_cor) const;
	int getHeight() const;
	int getWidth() const;
	void setXY(int y_cor, int x_cor, IDType repr);
	void setHeightandWidth(int width, int height);
	void showMap();
	void generateObstacles();
	void addObject(int y_cor, int x_cor, int height, int width, IDType repr);
	void Draw();
	void addObstacle(Obstacle obs);
	void drawAllObstacles();
	/*int calcEmpty(int col, int length);*/
};

