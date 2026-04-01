#pragma once
#include "Car.h"
#include "Weather.h"
#include <iostream>
using namespace std;

class Circuit
{
private:
    int lungime;
    Weather vreme;
    Car* masini[101];
    int numarMasini;

    double timpi[101];
    bool aTerminat[101];

public:
    Circuit();

    void SetLength(int lungime);
    void SetWeather(Weather vreme);
    void AddCar(Car* masina);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();

    ~Circuit();
};