#include "Map.h"

Map::Map(int height, int width)
{
	// one square is 20x20 cm
	// height and width are represented in cm
	Height = static_cast<int>(round(height/20.0));
	Width = static_cast<int>(round(width/20.0));


	MapArray = new int*[Height];
	for (int i = 0; i < Height; i++)
	{
		MapArray[i] = new int[Width];
	}

	// creating an empty map
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			MapArray[y][x] = 0;
		}
	}

}

Map::~Map()
{
	for (int i = 0; i < Height; i++)
	{
		delete[] MapArray[i];
	}
	delete[] MapArray;
}

int Map::getXY(int y_cor, int x_cor)
{
	return MapArray[y_cor][x_cor];
}

int Map::getHeight()
{
	return Height;
}

int Map::getWidth()
{
	return Width;
}

void Map::setXY(int y_cor, int x_cor, int repr)
{
	MapArray[y_cor][x_cor] = repr;
}

void Map::setHeightandWidth(int width, int height)
{
	Height = static_cast<int>(round(height / 20.0));
	Width = static_cast<int>(round(width / 20.0));
	MapArray = new int* [Height];
	for (int i = 0; i < Height; i++)
	{
		MapArray[i] = new int[Width];
	}

	// creating an empty map
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			MapArray[y][x] = 0;
		}
	}
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
