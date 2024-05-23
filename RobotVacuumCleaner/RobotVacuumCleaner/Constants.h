#pragma once
#include <map>
#include <string>
#include "raylib.h"

enum class BasicColor {
    Violet,
    Blue,
    DarkBlue
};

extern std::map<BasicColor, Color> colorMap;
extern const int cell_size;