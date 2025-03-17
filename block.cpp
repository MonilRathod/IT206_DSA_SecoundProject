#include "block.h"

block::block()
{
    cellsize = 30;
    rotationstate = 0;
    color = getcellcolors();
    rowoffset = 0;
    columoffset = 0;

}

void block::draw()
{
    vector<position> tiles = getcellposition();
    for(position item : tiles)
    {
        DrawRectangle(item.colums * cellsize+1, item.row * cellsize+1, cellsize-1, cellsize-1, color[id]);
    }
}
 void block::move(int row, int colum)
 {
        rowoffset += row;
        columoffset += colum;
 }

 vector<position> block::getcellposition()
 {
     vector<position> tiles = cells[rotationstate];
     vector<position> movedtiles;
        for(position item : tiles)
        {
            position newpos = position(item.row + rowoffset, item.colums + columoffset);
            movedtiles.push_back(newpos);
        }
        return movedtiles;
 }