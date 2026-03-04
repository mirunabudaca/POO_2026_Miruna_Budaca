#include "Student.h"

void Student::setName(string n)
{
    name = n;
}

string Student::getName()
{
    return name;
}

void Student::setMath(float m)
{
    math = m;
}

float Student::getMath()
{
    return math;
}

void Student::setEnglish(float e)
{
    english = e;
}

float Student::getEnglish()
{
    return english;
}

void Student::setHistory(float h)
{
    history = h;
}

float Student::getHistory()
{
    return history;
}

float Student::getAverage()
{
    return (math + english + history) / 3;
}