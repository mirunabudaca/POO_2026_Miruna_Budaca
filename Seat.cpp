#include "Seat.h"

const char* Seat::GetNume()
{
    return "Seat";
}

double Seat::GetCapacitateRezervor()
{
    return 50;
}

double Seat::GetConsum()
{
    return 6;
}

double Seat::GetViteza(Weather vreme)
{
    if (vreme == Weather::Sunny)
        return 110;
    if (vreme == Weather::Rain)
        return 85;
    return 65;
}