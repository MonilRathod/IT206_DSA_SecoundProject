#include "block.h"

block::block()
{
    cellsize = 30;
    rotationstate = 0;
    color = getcellcolors();
}

void block::draw()
{
    vector<position> tiles = cells[rotationstate];
    for(position item : tiles)
    {
        DrawRectangle(item.colums * cellsize+1, item.row * cellsize+1, cellsize-1, cellsize-1, color[id]);
    }
}
