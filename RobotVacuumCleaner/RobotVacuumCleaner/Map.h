#pragma once
#include <iostream>
#include <vector>
#include "Obstacle.h"
#include "IDType.h"
#include "ChargingStation.h"
#include "CleanSquare.h"
//#include "Robot.h"

class Map
{
private:
	IDType** MapArray;
	int Height;
	int Width;
	std::vector<Obstacle> Obstacles;
	ChargingStation CharStat;
	std::vector<CleanSquare> Cleaned;
public:
	Map(int height = 200, int width = 200);
	~Map();
	IDType getXY(int y_cor, int x_cor) const;
	int getHeight() const;
	int getWidth() const;
	void placeObject(int y_cor, int x_cor, IDType repr);
	void setHeightandWidth(int width, int height);
	void showMap();
	void generateObstacles();
	void addObject(int y_cor, int x_cor, int height, int width, IDType repr);
	//void Draw();
	void addObstacle(Obstacle obs);
	void drawAllObstacles();
	void clean(int x, int y);
	void drawCleaned();
	//void placeRobot(Robot* robot);
	/*int calcEmpty(int col, int length);*/
};

