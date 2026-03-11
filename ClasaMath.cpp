#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
    cout << "Add(int, int): " << Math::Add(2, 3) << endl;
    cout << "Add(int, int, int): " << Math::Add(2, 3, 4) << endl;

    cout << "Add(double, double): " << Math::Add(2.5, 3.7) << endl;
    cout << "Add(double, double, double): " << Math::Add(1.2, 2.3, 3.4) << endl;

    cout << "Mul(int, int): " << Math::Mul(2, 3) << endl;
    cout << "Mul(int, int, int): " << Math::Mul(2, 3, 4) << endl;

    cout << "Mul(double, double): " << Math::Mul(2.5, 3.0) << endl;
    cout << "Mul(double, double, double): " << Math::Mul(1.5, 2.0, 3.0) << endl;

    cout << "Add(count, ...): " << Math::Add(5, 1, 2, 3, 4, 5) << endl;

    char* s = Math::Add("Buna ", "Seara");
    if (s != nullptr)
    {
        cout << "Add(const char*, const char*): " << s << endl;
       
    }

    char* s2 = Math::Add(nullptr, "test");
    if (s2 == nullptr)
    {
        cout << "Rezultatul este nullptr." << endl;
    }

    return 0;
}