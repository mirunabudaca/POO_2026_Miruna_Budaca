#include "Fiat.h"

const char* Fiat::GetNume()
{
    return "Fiat";
}

double Fiat::GetCapacitateRezervor()
{
    return 15;
}

double Fiat::GetConsum()
{
    return 20;
}

double Fiat::GetViteza(Weather vreme)
{
    if (vreme == Weather::Sunny)
        return 95;
    if (vreme == Weather::Rain)
        return 75;
    return 55;
}