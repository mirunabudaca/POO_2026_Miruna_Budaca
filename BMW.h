#pragma once
#include "Car.h"

class BMW : public Car
{
public:
    const char* GetNume();
    double GetCapacitateRezervor();
    double GetConsum();
    double GetViteza(Weather vreme);
};