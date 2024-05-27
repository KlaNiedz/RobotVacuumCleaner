#include "Game.h"
#include "Robot.h"
#include "Constants.h"
Font font = LoadFontEx("RobotVacuumCleaner\Font\slkscr.ttf", 64, 0, 0);

void Game::draw()
{
	myMap.Draw();
	myMap.drawAllObstacles();
	myMap.drawCleaned();
	myMap.drawCharStat();
	myRobot.draw();

	DrawTextEx(font, "Battery:", {static_cast<float>((myMap.getWidth() * cell_size) + 10),
	static_cast<float>(myMap.getHeight() * cell_size) /6 }, 38, 2, colorMap[BasicColor::White]);

	std::string battery_level = std::to_string(myRobot.get_battery().getLevel()) + "%";
	DrawTextEx(font, battery_level.c_str(), {static_cast<float>((myMap.getWidth() * cell_size) + 10),
	static_cast<float>((myMap.getHeight() * cell_size) / 6)+50 }, 38, 2, colorMap[BasicColor::White]);

	DrawTextEx(font, "Bin filling:", { static_cast<float>((myMap.getWidth() * cell_size) + 10),
	static_cast<float>(myMap.getHeight() * cell_size) / 2 }, 38, 2, colorMap[BasicColor::White]);

	std::string bin_filling = std::to_string(myRobot.get_filter().getFillLevel()) + "%";
	DrawTextEx(font, bin_filling.c_str(), { static_cast<float>((myMap.getWidth() * cell_size) + 10),
	static_cast<float>((myMap.getHeight() * cell_size) / 2) + 50 }, 38, 2, colorMap[BasicColor::White]);

	// Sprawdzanie niskiego poziomu baterii
	if (myRobot.battery_low()) {
		DrawTextEx(font, "Low Battery!", { static_cast<float>((myMap.getWidth() * cell_size) + 10),
			static_cast<float>((myMap.getHeight() * cell_size) / 6) + 100 }, 24, 2, colorMap[BasicColor::Red]);
	}

	// Sprawdzanie przepe³nienia filtra
	if (myRobot.filter_fullfilled()) {
		DrawTextEx(font, "Filter Full!", { static_cast<float>((myMap.getWidth() * cell_size) + 10),
			static_cast<float>((myMap.getHeight() * cell_size) / 2) + 100 }, 24, 2, colorMap[BasicColor::Red]);
	}
}

//void Game::update()
//{
//	myRobot.update();
//}