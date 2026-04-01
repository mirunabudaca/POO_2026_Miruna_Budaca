#include "RangeRover.h"

const char* RangeRover::GetNume()
{
    return "RangeRover";
}

double RangeRover::GetCapacitateRezervor()
{
    return 70;
}

double RangeRover::GetConsum()
{
    return 12;
}

double RangeRover::GetViteza(Weather vreme)
{
    if (vreme == Weather::Sunny)
        return 105;
    if (vreme == Weather::Rain)
        return 85;
    return 75;
}