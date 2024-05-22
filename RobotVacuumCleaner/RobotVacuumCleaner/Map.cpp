#include "Map.h"

Map::Map(int height, int width)
{
	// one square is 20x20 cm
	// height and width are represented in cm
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
	//generateObstacles();

}

Map::~Map()
{
	for (int i = 0; i < Height; i++)
	{
		delete[] MapArray[i];
	}
	delete[] MapArray;
}

IDType Map::getXY(int y_cor, int x_cor)
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
	if (y_cor < 0 || y_cor >= Height || x_cor < 0 || x_cor >= Width)
		throw std::out_of_range("Coordinates out of bounds");
	MapArray[y_cor][x_cor] = repr;
}

void Map::setHeightandWidth(int width, int height)
{
	for (int i = 0; i < Height; i++)
	{
		delete[] MapArray[i];
	}
	delete[] MapArray;
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

//void Map::generateObstacles()
//{
//	int num_obs = Height*Width/10;
//	std::vector<std::vector<bool>> occupied(Height, std::vector<bool>(Width, false));
//	for (int i = 0; i < num_obs; i++)
//	{
//		int rand_height = 1 + (std::rand() % (Height/4));
//		int rand_width = 1 + (std::rand() % (Width/4));
//		int rand_x = 0;
//		int rand_y = 0;
//		bool valid_position = false;
//
//
//		while (!valid_position)
//		{
//			int rand_x = std::rand() % Width;
//			int rand_y = std::rand() % Height;
//			valid_position = true;
//			for (int l = 0; l < rand_height && valid_position; l++)
//			{
//				for (int w = 0; w < rand_width && valid_position; w++)
//				{
//					int new_x = rand_x + w;
//					int new_y = rand_y + l;
//
//					if (new_x >= Width || new_y >= Height || occupied[new_y][new_x])
//					{
//						valid_position = false;
//					}
//				}
//			}
//		}
//
//		Obstacles.push_back(Obstacle(rand_x, rand_y, IDType::Obstacle, rand_width, rand_height));
//		for (int l = 0; l < rand_height; l++)
//		{
//			for (int w = 0; w < rand_width; w++)
//			{
//				occupied[rand_y + l][rand_x + w] = true;
//			}
//		}
//	}
//	for (int obs = 0; obs < Obstacles.size(); obs++)
//	{
//		int x = Obstacles[obs].getX();
//		int y = Obstacles[obs].getY();
//		
//		/*MapArray[y][x] = static_cast<int>(Obstacles[obs].getID());*/
//		for (int l = 0; l < Obstacles[obs].getLength(); l++)
//		{
//			for (int w = 0; w < Obstacles[obs].getWidth(); w++)
//			{
//				MapArray[y + l][x + w] = static_cast<int>(Obstacles[obs].getID());
//			}
//		}
//	}
//}
