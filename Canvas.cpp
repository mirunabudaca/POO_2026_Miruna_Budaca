#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

Canvas::Canvas(int w, int h): width(w), height(h)
{
    mat = new char* [height];
    for (int i = 0; i < height; i++)
    {
        mat[i] = new char[width];
    }

    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mat[i][j] = ' ';
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        mat[y][x] = ch;
    }
}

void Canvas::Print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int x = left; x <= right; x++)
    {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }

    for (int y = top; y <= bottom; y++)
    {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; y++)
    {
        for (int x = left; x <= right; x++)
        {
            SetPoint(x, y, ch);
        }
    }
}



