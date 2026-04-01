#include "Volvo.h"

const char* Volvo::GetNume()
{
    return "Volvo";
}

double Volvo::GetCapacitateRezervor()
{
    return 60;
}

double Volvo::GetConsum()
{
    return 8;
}

double Volvo::GetViteza(Weather vreme)
{
    if (vreme == Weather::Sunny)
        return 100;
    if (vreme == Weather::Rain)
        return 80;
    return 60;
}