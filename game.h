#pragma once
#include "grid.h"
#include "blocks.cpp"

class game
{
    public:
    game();
    block getrandomblock();
    Grid grid;
    void draw();
    void handleinput();
    void moveblockleft();
    void moveblockright();
    void moveblockdown();
   

private:
    vector<block>blocks;
    block currentblock;
    block nextblock;
    void lockblock();
    bool isblockoutside();
    void rotateblock();
    bool blockfits();
    
};