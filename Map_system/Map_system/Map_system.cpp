// Map_system.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "Map.h"

#include <iostream>

int main()
{
    ChargingStation char_stat(40, 40);
    Map map1(208, 200, char_stat);
    map1.showMap();
    
}

