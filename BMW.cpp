#include "BMW.h"

const char* BMW::GetNume()
{
    return "BMW";
}

double BMW::GetCapacitateRezervor()
{
    return 55;
}

double BMW::GetConsum()
{
    return 7;
}

double BMW::GetViteza(Weather vreme)
{
    if (vreme == Weather::Sunny)
        return 120;
    if (vreme == Weather::Rain)
        return 90;
    return 70;
}