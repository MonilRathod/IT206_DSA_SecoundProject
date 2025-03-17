#include "block.h"

block::block()
{
    cellsize = 30;
    rotationstate = 0;
    color = getcellcolors();
    rowoffset = 0;
    columoffset = 0;

}

void block::draw(int offsetx,int offsety)
{
    vector<position> tiles = getcellposition();
    for(position item : tiles)
    {
        DrawRectangle(item.colums * cellsize+offsetx, item.row * cellsize+offsety, cellsize-1, cellsize-1, color[id]);
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

 void block::rotate()
 {
    rotationstate++;
    if(rotationstate == (int)cells.size())
    {
        rotationstate = 0;
    }
 }

 void block::undurotation()
 {
    rotationstate--;
    if(rotationstate == -1)
    {
        rotationstate = cells.size()-1;
    }
 }
