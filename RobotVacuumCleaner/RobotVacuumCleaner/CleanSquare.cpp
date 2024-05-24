#include "CleanSquare.h"
#include "raylib.h"
#include "Constants.h"

CleanSquare::CleanSquare(int x, int y, IDType ID) : MapObject(x, y, ID) {}

void CleanSquare::displayInfo() const
{
	std::cout << "Clean ID: " << static_cast<int>(getID())
		<< " at (" << getX() << ", " << getY() << ")" << std::endl;
}

void CleanSquare::draw() 
{
	DrawRectangle(x * cell_size, y * cell_size, cell_size, cell_size, colorMap[BasicColor::Brown]);

}