#include "Circuit.h"
using namespace std;

Circuit::Circuit()
{
    lungime = 0;
    vreme = Weather::Sunny;
    numarMasini = 0;
}

void Circuit::SetLength(int lungime)
{
    this->lungime = lungime;
}

void Circuit::SetWeather(Weather vreme)
{
    this->vreme = vreme;
}

void Circuit::AddCar(Car* masina)
{
    if (numarMasini < 101)
    {
        masini[numarMasini] = masina;
        numarMasini++;
    }
}

void Circuit::Race()
{
    for (int i = 0; i < numarMasini; i++)
    {
        double combustibilNecesar = masini[i]->GetConsum() * lungime / 100.0;
        double combustibilDisponibil = masini[i]->GetCapacitateRezervor();

        if (combustibilDisponibil >= combustibilNecesar)
        {
            aTerminat[i] = true;
            timpi[i] = (double)lungime / masini[i]->GetViteza(vreme);
        }
        else
        {
            aTerminat[i] = false;
            timpi[i] = -1;
        }
    }
}

void Circuit::ShowFinalRanks()
{
    int pozitii[101];
    int numarFinalisti = 0;

    for (int i = 0; i < numarMasini; i++)
    {
        if (aTerminat[i] == true)
        {
            pozitii[numarFinalisti] = i;
            numarFinalisti++;
        }
    }

    for (int i = 0; i < numarFinalisti - 1; i++)
    {
        for (int j = i + 1; j < numarFinalisti; j++)
        {
            if (timpi[pozitii[i]] > timpi[pozitii[j]])
            {
                swap(pozitii[i], pozitii[j]);
            }
        }
    }

    cout << "Clasament final:" << endl;
    for (int i = 0; i < numarFinalisti; i++)
    {
        cout << i + 1 << ". " << masini[pozitii[i]]->GetNume() << " - timp: " << timpi[pozitii[i]] << " ore" << endl;
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    cout << "Nu au terminat cursa:" << endl;
    for (int i = 0; i < numarMasini; i++)
    {
        if (aTerminat[i] == false)
        {
            cout << masini[i]->GetNume() << endl;
        }
    }
}

Circuit::~Circuit()
{
    for (int i = 0; i < numarMasini; i++)
    {
        delete masini[i];
    }
}