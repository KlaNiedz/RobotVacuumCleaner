#include <map>
#include <string>
#include "raylib.h"
#include "Constants.h"

std::map<BasicColor, Color> colorMap = {
    { BasicColor::Violet, Color { 153, 51, 255, 255 } },
    { BasicColor::DarkBlue, Color{ 0, 76, 153, 255 } },
    { BasicColor::Blue, Color{ 153, 204, 255, 255 } },
    { BasicColor::Pink, Color{  255, 0, 127, 255  } }
};

const int cell_size = 40;