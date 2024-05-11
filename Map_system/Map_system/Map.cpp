#include "Map.h"

Map::Map(int height, int width, ChargingStation char_stat)
{
	// jedna kratka reprezentuje kwadrat 20x20
	// height oraz width wyra¿one w cm
	Height = static_cast<int>(round(height/20.0));
	Width = static_cast<int>(round(width/20.0));
	Char_stat = char_stat;


	MapArray = new int*[Height];
	for (int i = 0; i < Height; i++)
	{
		MapArray[i] = new int[Width];
	}

	// tworzenie pustej mapy
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			MapArray[y][x] = 0;
		}
	}
	MapArray[static_cast<int>(round(Char_stat.getY()/20.0))][static_cast<int>(round(Char_stat.getX()/20.0))] = 5;
	

}

Map::~Map()
{
	for (int i = 0; i < Height; i++)
	{
		delete[] MapArray[i];
	}
	delete[] MapArray;
}

void Map::showMap()
{
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			std::cout << MapArray[y][x] << " ";
		}
		std::cout << std::endl;
	}
}
