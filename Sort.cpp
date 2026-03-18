#include "Sort.h"
#include <ctime>
#include <cstdlib>


Sort::Sort(int nrElemente, int mini, int maxi)
{
    srand(time(0));

    for (int i = 0; i < nrElemente; i++)
    {
        int x = mini + rand() % (maxi - mini + 1);
        v.push_back(x);
    }
}

Sort::Sort(initializer_list<int> list)
{
    for (int x : list)
        v.push_back(x);
}

Sort::Sort(vector<int> vec, int count)
{
    for (int i = 0; i < count && i < vec.size(); i++)
        v.push_back(vec[i]);
}

Sort::Sort(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        v.push_back(va_arg(args, int));

    va_end(args);
}

Sort::Sort(const char* text)
{
    int number = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ',')
        {
            v.push_back(number);
            number = 0;
        }
        else
        {
            number = number * 10 + (text[i] - '0');
        }
    }

    v.push_back(number);
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < v.size(); i++)
    {
        int p = i;
        if (ascendent)
            while (p > 0 && v[p] < v[p - 1])
            {
                swap(v[p], v[p - 1]);
                p--;
            }
        else
            while (p > 0 && v[p] > v[p - 1])
            {
                swap(v[p], v[p - 1]);
                p--;
            }
    }
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (ascendent)
            {
                if (v[j] > v[j + 1])
                    swap(v[j], v[j + 1]);
            }
            else
            {
                if (v[j] < v[j + 1])
                    swap(v[j], v[j + 1]);
            }
        }
}

void Sort::QuickSortRec(int st, int dr, bool ascendent)
{
    if (st < dr)
    {
        int m = (st + dr) / 2;
        swap(v[st], v[m]);

        int i = st, j = dr, d = 0;

        while (i < j)
        {
            if (ascendent)
            {
                if (v[i] > v[j])
                {
                    swap(v[i], v[j]);
                    d = 1 - d;
                }
            }
            else
            {
                if (v[i] < v[j])
                {
                    swap(v[i], v[j]);
                    d = 1 - d;
                }
            }

            i += d;
            j -= 1 - d;
        }

        QuickSortRec(st, i - 1, ascendent);
        QuickSortRec(i + 1, dr, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortRec(0, v.size() - 1, ascendent);
}

void Sort::Print()
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;
}

int Sort::GetElementsCount()
{
    return v.size();
}

int Sort::GetElementFromIndex(int index)
{
    return v[index];
}