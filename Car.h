#pragma once
#include "Weather.h"

class Car
{
public:
    virtual ~Car() {}

    virtual const char* GetNume() = 0;
    virtual double GetCapacitateRezervor() = 0;
    virtual double GetConsum() = 0; 
    virtual double GetViteza(Weather vreme) = 0;
};