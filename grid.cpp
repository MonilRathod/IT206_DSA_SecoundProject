#include "grid.h"
#include <iostream>
using namespace std;


Grid::Grid()
{
    numrows = 20;
    numcols = 10;
    cellsize = 30;
    initialize();
    color = getcellcolors();
}

void Grid::initialize()
{
    for (int row = 0; row < numrows; row++)
    {
        for (int colums = 0; colums < numcols; colums++)
        {
            grid[row][colums] = 0;
        }
    }
}
void Grid::print()
{
    for (int row = 0; row < numrows; row++)
    {
        for (int colums = 0; colums < numcols; colums++)
        {
           cout<<grid[row][colums]<<" ";
        }
        cout<<endl;
    }
}

vector<Color> Grid::getcellcolors()
{
    Color darkgray = { 167, 206, 240, 255 };
    Color yello = { 255, 255, 0, 255 };
    Color green = { 0, 255, 0, 255 };
    Color purple = { 128, 0, 128, 255 };
    Color red = { 255, 0, 0, 255 };
    Color orange = { 255, 165, 0, 255 };
    Color pink = { 255, 192, 203, 255 };
    Color blue = { 0, 0, 255, 255 };
    
    return {darkgray, yello, green, purple, red, orange, pink, blue};
}

void Grid::draw()
{
    for (int row = 0; row < numrows; row++)
    {
        for (int colums = 0; colums < numcols; colums++)
        {
            int cellvalue = grid[row][colums];
                DrawRectangle(colums * cellsize+1, row * cellsize+1, cellsize-1, cellsize-1, color[cellvalue]);
            }
        }
    }

