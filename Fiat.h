#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
    const char* GetNume();
    double GetCapacitateRezervor();
    double GetConsum();
    double GetViteza(Weather vreme);
};