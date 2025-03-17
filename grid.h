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
     
    private:
      
        int numrows;
        int numcols; 
        int cellsize; 
        vector<Color> color;
 
 
      
};