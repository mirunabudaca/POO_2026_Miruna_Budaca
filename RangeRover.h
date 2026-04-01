#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
    const char* GetNume();
    double GetCapacitateRezervor();
    double GetConsum();
    double GetViteza(Weather vreme);
};