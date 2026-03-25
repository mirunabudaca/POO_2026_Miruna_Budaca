#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Number
{
private:
    char* sir;
    int baza;

    int CharLaValoare(char c) const;
    char ValoareLaChar(int x) const;
    unsigned long long InBaza10() const;
    void DinBaza10(unsigned long long numar10, int bazaNoua);

public:
    Number(const char* valoare, int baza);
    Number(int valoare);
    Number(const Number& altul);
    Number(Number&& altul);
    ~Number();

    Number& operator=(const Number& altul);
    Number& operator=(Number&& altul);
    Number& operator=(int valoare);
    Number& operator=(const char* valoare);

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    Number& operator+=(const Number& altul);

    char operator[](int index) const;

    bool operator<(const Number& altul) const;
    bool operator>(const Number& altul) const;
    bool operator<=(const Number& altul) const;
    bool operator>=(const Number& altul) const;
    bool operator==(const Number& altul) const;
    bool operator!=(const Number& altul) const;

    Number& operator--();
    Number operator--(int);

    void SwitchBase(int bazaNoua);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
}; 
