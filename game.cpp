#include "game.h"
#include<random>

game::game()
{
    grid = Grid();
    blocks = {Iblock(),Lblock(),Jblock(),Oblock(),Sblock()};   
    currentblock = getrandomblock();
    nextblock = getrandomblock(); 
}
 
block game::getrandomblock()
{
    int random = GetRandomValue(0,blocks.size()-1);
    return blocks[random];
}

void game::draw(){
    grid.draw();
    currentblock.draw();
}

void game::handleinput()
{
    int keypressed = GetKeyPressed();
    switch(keypressed)
    {
        case KEY_DOWN:
            moveblockdown();
            break;
        case KEY_LEFT:
            moveblockleft();
            break;
        case KEY_RIGHT:
            moveblockright();
            break;
    }
}

void game::moveblockleft()
{
    currentblock.move(0,-1);
}
void game::moveblockright()
{
    currentblock.move(0,1);
}
void game::moveblockdown()
{
    currentblock.move(1,0);
}


