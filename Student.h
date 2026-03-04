#pragma once
#include <string>

using namespace std;

class Student
{
private:
    string name;
    float math;
    float english;
    float history;

public:
    void setName(string n);
    string getName();

    void setMath(float m);
    float getMath();

    void setEnglish(float e);
    float getEnglish();

    void setHistory(float h);
    float getHistory();

    float getAverage();
};