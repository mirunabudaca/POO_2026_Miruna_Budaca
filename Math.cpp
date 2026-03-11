#include "Math.h"
#include <cstdarg>   
#include <cstring>   

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return (int)(a + b);
}

int Math::Add(double a, double b, double c)
{
    return (int)(a + b + c);
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return (int)(a * b);
}

int Math::Mul(double a, double b, double c)
{
    return (int)(a * b * c);
}

int Math::Add(int count, ...)
{
    va_list arg;
    va_start(arg, count);

    int sum = 0;

    for (int i = 0; i < count; i++)
        sum += va_arg(arg, int);

    va_end(arg);

    return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;

    int lg1 = strlen(s1);
    int lg2 = strlen(s2);

    char* sol = new char[lg1 + lg2 + 1];

    strcpy_s(sol, lg1 + lg2 + 1, s1);
    strcat_s(sol, lg1 + lg2 + 1, s2);

    return sol;
}