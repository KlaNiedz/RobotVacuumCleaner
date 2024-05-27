#include <map>
#include <string>
#include "raylib.h"
#include "Constants.h"

std::map<BasicColor, Color> colorMap = {
    { BasicColor::Violet, Color { 153, 51, 255, 255 } },
    { BasicColor::DarkBlue, Color{ 0, 76, 153, 255 } },
    { BasicColor::Blue, Color{ 153, 204, 255, 255 } },
    { BasicColor::Pink, Color{  255, 0, 127, 255  } },
    { BasicColor::Grey, Color{  64, 64, 64, 255  } },
    { BasicColor::Brown, Color{  219, 185, 140, 255  } },
    { BasicColor::DarkBrown, Color{  141, 119, 92, 255  } },
    { BasicColor::Bluesih, Color{  0, 102, 102, 255  } },
    { BasicColor::White, Color{  255, 255, 255, 255  } },
    { BasicColor::Red, Color{  139, 0, 0, 255  } },
};

const int cell_size = 40;