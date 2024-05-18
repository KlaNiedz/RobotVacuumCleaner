#pragma once
#include <iostream>
#include <vector>
class Map
{
private:
	int** MapArray;
	int Height;
	int Width;
	/*std::vector<Obstacle> Obstacles;*/
public:
	Map(int height, int width);
	~Map();
	int getXY(int x_cor, int y_cor);
	int getHeight();
	int getWidth();
	void setXY(int x_cor, int y_cor, int repr);
	void setHeightandWidth(int width, int height);
	void showMap();
};

