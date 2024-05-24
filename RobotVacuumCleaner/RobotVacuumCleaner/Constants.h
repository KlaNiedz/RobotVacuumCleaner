#pragma once
#include <map>
#include <string>
#include "raylib.h"

enum class BasicColor {
    Violet,
    Blue,
    DarkBlue,
    Pink,
    Grey,
    DarkBrown,
    Brown,
    Bluesih,
};

extern std::map<BasicColor, Color> colorMap;
extern const int cell_size;