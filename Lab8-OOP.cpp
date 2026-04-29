#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

using namespace std;

struct Cuvant
{
    string text;
    int aparitii;
};

class Comparare
{
public:
    bool operator()(const Cuvant& a, const Cuvant& b)
    {
        if (a.aparitii != b.aparitii)
            return a.aparitii < b.aparitii;

        return a.text > b.text;
    }
};

bool esteSeparator(char caracter)
{
    return caracter == ' ' || caracter == ',' || caracter == '?' || caracter == '!' || caracter == '.';
}

string transformaInLitereMici(string cuvant)
{
    for (int i = 0; i < cuvant.size(); i++)
    {
        cuvant[i] = tolower(cuvant[i]);
    }

    return cuvant;
}

int main()
{
    ifstream fisier("text.txt");

    string fraza;
    string linie;

    while (getline(fisier, linie))
    {
        fraza += linie;
        fraza += ' ';
    }

    fisier.close();

    map<string, int> frecventaCuvinte;

    int pozitie = 0;

    while (pozitie < fraza.size())
    {
        while (pozitie < fraza.size() && esteSeparator(fraza[pozitie]))
        {
            pozitie++;
        }

        int inceput = pozitie;

        while (pozitie < fraza.size() && !esteSeparator(fraza[pozitie]))
        {
            pozitie++;
        }

        int lungime = pozitie - inceput;

        if (lungime > 0)
        {
            string cuvant = fraza.substr(inceput, lungime);
            cuvant = transformaInLitereMici(cuvant);

            frecventaCuvinte[cuvant]++;
        }
    }

    priority_queue<Cuvant, vector<Cuvant>, Comparare> coadaPrioritati;

    for (map<string, int>::iterator it = frecventaCuvinte.begin(); it != frecventaCuvinte.end(); it++)
    {
        Cuvant cuvantCurent;

        cuvantCurent.text = it->first;
        cuvantCurent.aparitii = it->second;

        coadaPrioritati.push(cuvantCurent);
    }

    while (!coadaPrioritati.empty())
    {
        Cuvant cuvantCurent = coadaPrioritati.top();

        cout << cuvantCurent.text << " => " << cuvantCurent.aparitii << endl;

        coadaPrioritati.pop();
    }

    return 0;
}