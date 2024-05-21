#pragma once
#include <iostream>
#include <vector>
#include "Obstacle.h"
class Map
{
private:
	int** MapArray;
	int Height;
	int Width;
	std::vector<Obstacle> Obstacles;
public:
	Map(int height, int width);
	~Map();
	int getXY(int y_cor, int x_cor);
	int getHeight();
	int getWidth();
	void setXY(int y_cor, int x_cor, int repr);
	void setHeightandWidth(int width, int height);
	void showMap();
	void generateObstacles();
};

