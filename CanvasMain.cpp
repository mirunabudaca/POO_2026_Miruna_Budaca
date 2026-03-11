#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
    Canvas c(30, 30);

    cout << "SetPoint:";
    c.SetPoint(2, 2, '*');
    c.Print();

    cout << "DrawRect:";
    c.Clear();
    c.DrawRect(1, 1, 15, 6, '#');
    c.Print();

    cout << "FillRect:";
    c.Clear();
    c.FillRect(2, 2, 12, 8, '@');
    c.Print();

    return 0;
}