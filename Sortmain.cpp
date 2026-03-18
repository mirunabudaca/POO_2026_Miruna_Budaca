#include "Sort.h"

int main()
{
    cout << "Constructor random\n";
    Sort s1(10, 1, 100);
    s1.Print();
    s1.InsertSort(true);
    cout << "InsertSort ascendent\n";
    s1.Print();
    cout << "Count: " << s1.GetElementsCount() << endl;
    cout << "Element index 3: " << s1.GetElementFromIndex(3) << endl;

    cout << "\nConstructor initialization list\n";
    Sort s2{ 10, 40, 100, 5, 70 };
    s2.Print();
    s2.QuickSort(true);
    cout << "QuickSort ascendent\n";
    s2.Print();

    cout << "\nConstructor vector\n";
    vector<int> a = { 7, 2, 9, 1, 6, 8 };
    Sort s3(a, 4);
    s3.Print();
    s3.BubbleSort(false);
    cout << "BubbleSort descendent\n";
    s3.Print();

    cout << "\nConstructor variadic\n";
    Sort s4(5, 10, 40, 100, 5, 70);
    s4.Print();
    s4.InsertSort(false);
    cout << "InsertSort descendent\n";
    s4.Print();

    cout << "\nConstructor string\n";
    Sort s5("10,40,100,5,70");
    s5.Print();
    s5.QuickSort(true);
    cout << "QuickSort ascendent\n";
    s5.Print();

    return 0;
}