#pragma once
#include <iostream>
#include <vector>
#include "Obstacle.h"
#include "IDType.h"
class Map
{
private:
	IDType** MapArray;
	int Height;
	int Width;
	std::vector<Obstacle> Obstacles;
public:
	Map(int height = 200, int width = 200);
	~Map();
	IDType getXY(int y_cor, int x_cor);
	int getHeight();
	int getWidth();
	void setXY(int y_cor, int x_cor, int repr);
	void setHeightandWidth(int width, int height);
	void showMap();
	/*void generateObstacles();*/
};

