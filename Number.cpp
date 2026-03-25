#include "Number.h"

int Number::CharLaValoare(char c) const
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return 0;
}

char Number::ValoareLaChar(int x) const
{
    if (x >= 0 && x <= 9)
        return char('0' + x);
    return char('A' + x - 10);
}

unsigned long long Number::InBaza10() const
{
    unsigned long long numar10 = 0;
    int lungime = (int)strlen(sir);

    for (int i = 0; i < lungime; i++)
    {
        numar10 = numar10 * baza + CharLaValoare(sir[i]);
    }

    return numar10;
}

void Number::DinBaza10(unsigned long long numar10, int bazaNoua)
{
    if (numar10 == 0)
    {
        delete[] sir;
        sir = new char[2];
        sir[0] = '0';
        sir[1] = '\0';
        baza = bazaNoua;
        return;
    }

    char invers[100];
    int k = 0;

    while (numar10 > 0)
    {
        int cifra = (int)(numar10 % bazaNoua);
        invers[k++] = ValoareLaChar(cifra);
        numar10 /= bazaNoua;
    }

    delete[] sir;
    sir = new char[k + 1];

    for (int i = 0; i < k; i++)
    {
        sir[i] = invers[k - 1 - i];
    }
    sir[k] = '\0';

    baza = bazaNoua;
}

Number::Number(const char* valoare, int bazaInitiala)
{
    baza = bazaInitiala;
    sir = new char[strlen(valoare) + 1];
    strcpy(sir, valoare);
}

Number::Number(int valoare)
{
    baza = 10;
    sir = nullptr;
    DinBaza10(valoare, 10);
}

Number::Number(const Number& altul)
{
    baza = altul.baza;
    sir = new char[strlen(altul.sir) + 1];
    strcpy(sir, altul.sir);
}

Number::Number(Number&& altul)
{
    baza = altul.baza;
    sir = altul.sir;

    altul.sir = nullptr;
    altul.baza = 10;
}

Number::~Number()
{
    delete[] sir;
}

Number& Number::operator=(const Number& altul)
{
    if (this != &altul)
    {
        delete[] sir;
        baza = altul.baza;
        sir = new char[strlen(altul.sir) + 1];
        strcpy(sir, altul.sir);
    }
    return *this;
}

Number& Number::operator=(Number&& altul)
{
    if (this != &altul)
    {
        delete[] sir;
        baza = altul.baza;
        sir = altul.sir;

        altul.sir = nullptr;
        altul.baza = 10;
    }
    return *this;
}

Number& Number::operator=(int valoare)
{
    unsigned long long numar10 = valoare;
    DinBaza10(numar10, baza);
    return *this;
}

Number& Number::operator=(const char* valoare)
{
    delete[] sir;
    sir = new char[strlen(valoare) + 1];
    strcpy(sir, valoare);
    return *this;
}

Number operator+(const Number& a, const Number& b)
{
    unsigned long long x = a.InBaza10();
    unsigned long long y = b.InBaza10();
    int bazaRezultat = a.baza > b.baza ? a.baza : b.baza;

    unsigned long long suma = x + y;

    Number rezultat("0", bazaRezultat);
    rezultat.DinBaza10(suma, bazaRezultat);
    return rezultat;
}

Number operator-(const Number& a, const Number& b)
{
    unsigned long long x = a.InBaza10();
    unsigned long long y = b.InBaza10();
    int bazaRezultat = a.baza > b.baza ? a.baza : b.baza;

    unsigned long long diferenta;
    if (x >= y)
        diferenta = x - y;
    else
        diferenta = 0;

    Number rezultat("0", bazaRezultat);
    rezultat.DinBaza10(diferenta, bazaRezultat);
    return rezultat;
}

Number& Number::operator+=(const Number& altul)
{
    *this = *this + altul;
    return *this;
}

char Number::operator[](int index) const
{
    return sir[index];
}

bool Number::operator<(const Number& altul) const
{
    return InBaza10() < altul.InBaza10();
}

bool Number::operator>(const Number& altul) const
{
    return InBaza10() > altul.InBaza10();
}

bool Number::operator<=(const Number& altul) const
{
    return InBaza10() <= altul.InBaza10();
}

bool Number::operator>=(const Number& altul) const
{
    return InBaza10() >= altul.InBaza10();
}

bool Number::operator==(const Number& altul) const
{
    return InBaza10() == altul.InBaza10();
}

bool Number::operator!=(const Number& altul) const
{
    return InBaza10() != altul.InBaza10();
}

Number& Number::operator--()
{
    int lungime = (int)strlen(sir);

    if (lungime <= 1)
    {
        delete[] sir;
        sir = new char[2];
        sir[0] = '0';
        sir[1] = '\0';
        return *this;
    }

    for (int i = 0; i < lungime - 1; i++)
    {
        sir[i] = sir[i + 1];
    }
    sir[lungime - 1] = '\0';

    return *this;
}

Number Number::operator--(int)
{
    Number copie(*this);

    int lungime = (int)strlen(sir);

    if (lungime <= 1)
    {
        delete[] sir;
        sir = new char[2];
        sir[0] = '0';
        sir[1] = '\0';
        return copie;
    }

    sir[lungime - 1] = '\0';
    return copie;
}

void Number::SwitchBase(int bazaNoua)
{
    unsigned long long numar10 = InBaza10();
    DinBaza10(numar10, bazaNoua);
}

void Number::Print() const
{
    cout << sir << '\n';
}

int Number::GetDigitsCount() const
{
    return (int)strlen(sir);
}

int Number::GetBase() const
{
    return baza;
}