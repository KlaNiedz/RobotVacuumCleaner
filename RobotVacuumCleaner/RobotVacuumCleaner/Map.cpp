#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "ChargingStation.h"
#include "IDType.h"
#include "raylib.h"
#include "Constants.h"
#include "CleanSquare.h"

Map::Map(int height, int width)
{
	// one square is 20x20 cm
	// height and width are represented in cm
	if (height < 20 || width < 20) {
		throw std::invalid_argument("Height and width must be at least 20 cm.");
	}
	Height = static_cast<int>(round(height/20.0));
	Width = static_cast<int>(round(width/20.0));


	MapArray = new IDType*[Height];
	for (int i = 0; i < Height; i++)
	{
		MapArray[i] = new IDType[Width];
	}

	// creating an empty map
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			MapArray[y][x] = IDType::Dirty;
		}
	}
	generateObstacles();
	// putting Charging Station into map
	ChargingStation charstat(0, 0, IDType::ChargingStation);
	MapArray[charstat.getY()][charstat.getX()] = charstat.getID();
	
}

Map::~Map()
{
	for (int i = 0; i < Height; i++)
	{
		delete[] MapArray[i];
	}
	delete[] MapArray;
}

void Map::Draw() {
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			DrawRectangle(x * cell_size, y * cell_size, cell_size, cell_size, colorMap[BasicColor::DarkBrown]);
		}
	}
}

IDType Map::getXY(int y_cor, int x_cor) const
{
	return MapArray[y_cor][x_cor];
}

int Map::getHeight() const
{
	return Height;
}

int Map::getWidth() const
{
	return Width;
}

void Map::placeObject(int y_cor, int x_cor, IDType repr)
{
	if (y_cor < 0 || y_cor >= Height || x_cor < 0 || x_cor >= Width)
		throw std::out_of_range("Coordinates out of bounds");
	MapArray[y_cor][x_cor] = repr;
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

// Randomly gererating obstacles on map. 
void Map::generateObstacles()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int num_obs = Height*Width/25;
	std::vector<std::vector<bool>> occupied(Height, std::vector<bool>(Width, false));
	occupied[CharStat.getY()][CharStat.getX()] = true;

	for (int i = 0; i < num_obs; i++)
	{
		int rand_height = 1 + (std::rand() % 3);
		int rand_width = 1 + (std::rand() % 3);
		int rand_x = 0;
		int rand_y = 0;
		bool valid_position = false;

		// generating obstacle till all squares prepared for obstacles are found empty
		while (!valid_position)
		{
			rand_x = 1 + (std::rand() % (Width-1));
			rand_y = 1+  (std::rand() % (Height-1));
			valid_position = true;
			for (int l = 0; l < rand_height && valid_position; l++)
			{
				for (int w = 0; w < rand_width && valid_position; w++)
				{
					int new_x = rand_x + w;
					int new_y = rand_y + l;

					if (new_x >= Width-1 || new_y >= Height-1 || occupied[new_y][new_x])
					{
						valid_position = false;
					}
					
				}
			}
		}

		// occupying squares where obstacle was put
		Obstacles.push_back(Obstacle(rand_x, rand_y, IDType::Obstacle, rand_width, rand_height));
		for (int l = 0; l < rand_height; l++)
		{
			for (int w = 0; w < rand_width; w++)
			{
				occupied[rand_y + l][rand_x + w] = true;
			}
		}
	}

	// putting all obstacles into Map
	for (int obs = 0; obs < Obstacles.size(); obs++)
	{
		int x = Obstacles[obs].getX();
		int y = Obstacles[obs].getY();
		
		for (int l = 0; l < Obstacles[obs].getLength(); l++)
		{
			for (int w = 0; w < Obstacles[obs].getWidth(); w++)
			{
				MapArray[y + l][x + w] = (Obstacles[obs].getID());
				
			}
		}
	}
}
// Adding obstacle on map
void Map::addObject(int y_cor, int x_cor, int height, int width, IDType repr)
{
	try {
		for (int h = 0; h < height; h++)
		{
			for (int w = 0; w < width; w++)
			{
				MapArray[y_cor + h][x_cor + w] = repr;

			}
		}
	}
	catch (const std::out_of_range& e){
		std::cout << "Wrong coordinates:" << e.what() << ". Height of the map : " << Height << " Width of the map : " << Width << std::endl;
	}
}

// Drawing obstacle on graphic map
void Map::addObstacle(Obstacle obs)
{
	obs.draw();
}

void Map::drawAllObstacles()
{
	for (int obs = 0; obs < Obstacles.size(); obs++)
	{
		int x = Obstacles[obs].getX();
		int y = Obstacles[obs].getY();
		/*Obstacles[obs].draw();*/

		for (int l = 0; l < Obstacles[obs].getLength(); l++)
		{
			for (int w = 0; w < Obstacles[obs].getWidth(); w++)
			{				
				DrawRectangle((x+w)*cell_size, (y+l)*cell_size, cell_size, cell_size, colorMap[BasicColor::Bluesih]);

			}
		}
	}
}

// Adding clean squares on map
void Map::clean(int x, int y)
{

	placeObject(y, x, IDType::Clean);
	CleanSquare clean_square(x, y, IDType::Clean);
	Cleaned.push_back(clean_square);
}

void Map::drawCleaned()
{
	for (int i = 0; i < Cleaned.size(); i++)
	{
		Cleaned[i].draw();
	}
}

// Drawing Charging station
void Map::drawCharStat()
{
	CharStat.draw();
}


