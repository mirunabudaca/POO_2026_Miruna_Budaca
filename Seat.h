#pragma once
#include "Car.h"

class Seat : public Car
{
public:
    const char* GetNume();
    double GetCapacitateRezervor();
    double GetConsum();
    double GetViteza(Weather vreme);
};