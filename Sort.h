#pragma once
#include <vector>
#include <iostream>
#include <cstdarg>
#include <initializer_list>

using namespace std;

class Sort
{
private:
    vector<int> v;

    void QuickSortRec(int st, int dr, bool ascendent);

public:
    
    Sort(int nrElemente, int mini, int maxi);
    Sort(initializer_list<int> list);
    Sort(vector<int> vec, int count);
    Sort(int count, ...);
    Sort(const char* text);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};