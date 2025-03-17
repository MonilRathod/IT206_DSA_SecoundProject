#include "game.h"
#include<random>

game::game()
{
    grid = Grid();
    blocks = {Iblock(),Lblock(),Jblock(),Oblock(),Sblock()};   
    currentblock = getrandomblock();
    nextblock = getrandomblock(); 
    gameover = false;
}
 
block game::getrandomblock()
{
    int random = GetRandomValue(0,blocks.size()-1);
    return blocks[random];
}

void game::draw()
{
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
        case KEY_UP:
            rotateblock();
            break;    
    }
}

void game::moveblockleft()
{
    if(!gameover)
    {
        currentblock.move(0,-1);
        if(isblockoutside() || blockfits() == false)
        {
            currentblock.move(0,1);
        }
    }

}
void game::moveblockright()
{
    if(!gameover)
    {
        currentblock.move(0,1);
        if(isblockoutside() || blockfits() == false)
        {
            currentblock.move(0,-1);
        }
    }
}
void game::moveblockdown()
{
    if(!gameover)
    {
        currentblock.move(1,0);
        if(isblockoutside() || blockfits() == false)
        {
            currentblock.move(-1,0);
            lockblock();
        }
    }
}

void game::lockblock()
{
    vector<position> tiles = currentblock.getcellposition();
    for(position item: tiles)
    {
        grid.grid[item.row][item.colums] = currentblock.id;
    }
    currentblock = nextblock;
    if(blockfits() == false)
    {
        gameover = true;
        return;
    }
    else
    {
        nextblock = getrandomblock();
    }
    grid.clearfullrows();
}

bool game::isblockoutside()
{
    vector<position> tiles = currentblock.getcellposition();
    for(position item: tiles)
    {
        if(grid.iscelloutside(item.row,item.colums))
        {
            return true;
        }
    }
    return false;
}

void game::rotateblock()
{
    if(!gameover)
    {
        currentblock.rotate();
        if(isblockoutside() || blockfits() == false)
        {
            currentblock.undurotation();
        }
    }
}

bool game::blockfits()
{
    vector<position> tiles = currentblock.getcellposition();
    for(position item: tiles)
    {
        if(grid.iscellempty(item.row,item.colums) == false)
        {
            return false;
        }
    }
    return true;
}

