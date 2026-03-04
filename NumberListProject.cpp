#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList lista;

    lista.Init();

    lista.Add(6);
    lista.Add(3);
    lista.Add(5);
    lista.Add(1);

    cout << "Inainte de sortare: ";
    lista.Print();

    lista.Sort();

    cout << "Dupa sortare: ";
    lista.Print();

    return 0;
}