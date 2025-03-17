#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

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
    void rotateblock();
    void reset();
    void harddrop();
    bool gameover;
    int score;

private:
    std::vector<block> blocks;
    block currentblock;
    block nextblock;
    void lockblock();
    bool isblockoutside();
    bool blockfits();
    void updatescore(int rowscleared);
};