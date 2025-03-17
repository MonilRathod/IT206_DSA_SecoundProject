#include "grid.h"
#include <iostream>
#include "colors.h"
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

    bool Grid::iscelloutside(int row, int colum)
    {
        if(row >= 0 && row < numrows && colum >= 0 && colum < numcols){
            return false;
        }
        return true;
    }

    bool Grid::iscellempty(int row, int colum)
{
    if(grid[row][colum] == 0)
    {
        return true;
    }
    return false; 
}