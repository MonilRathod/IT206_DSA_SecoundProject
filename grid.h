#pragma once
#include <vector>
#include <raylib.h>
 
using namespace std;
 
class Grid
{
    public:
        Grid();
        void initialize();
        int grid[20][10];
        void print();
        void draw();
        bool iscelloutside(int row, int colum);
        bool iscellempty(int row, int colum);
        int clearfullrows();
        
     
    private:
      
        int numrows;
        int numcols; 
        int cellsize; 
        vector<Color> color;
        bool isrowfull(int row);
        void clearrow(int row);
        void moverowdown(int row,int numrows);

 
 
      
};