#include "game.h"
#include<random>

game::game()
{
    grid = Grid();
    blocks = {Iblock(),Lblock(),Jblock(),Oblock(),Sblock(),Zblock(),Tblock()};     
    currentblock = getrandomblock();
    nextblock = getrandomblock(); 
    gameover = false;
    score = 0;
}

block game::getrandomblock()
{
    int random = GetRandomValue(0,blocks.size()-1);
    return blocks[random];
}

void game::draw()
{
    grid.draw();
    currentblock.draw(11,11);
    switch (nextblock.id)
    {
    case 3:
        nextblock.draw(255,290);
        break;
    case 4:
        nextblock.draw(255,280);
        break;    
    
    default:
        nextblock.draw(270,270);
        break;
    }
}

void game::handleinput()
{
    keypressed = GetKeyPressed();
    if(gameover && keypressed == KEY_R)
    {
       reset();
    }
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
        case KEY_SPACE:
            harddrop();
            break;  
        case KEY_P:
            gamepause=true;    
            break;   
        case KEY_ENTER:
            gameresume=true;    
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

void game::harddrop()
{
    if(!gameover)
    {
        while(!isblockoutside() && blockfits())
        {
            currentblock.move(1, 0);
        }
        currentblock.move(-1, 0);
        lockblock();
    }


}
void game::lockblock()
{
    vector<position> tiles = currentblock.getcellposition();
    for(position item: tiles)
    {
        grid.grid[item.row][item.colums] = currentblock.id;
    }
    if(!gameover){
    currentblock = nextblock;
    }

    if(blockfits() == false)
    { 
        gameover = true;
        bool empty = true;
        for(int i = 0; i < 10; i++) {
            if(!grid.iscellempty(0, i)) {
                empty = false;
                break;
            }
        }
        if(!empty)
        {    
         switch(currentblock.id)
         {
        case 1:
            currentblock.move(-2,0);
            break;
        case 2:
            currentblock.move(-2,0);
            break;
        case 3:
            currentblock.move(-1,0);
            break;
        case 4:
            currentblock.move(-2,0);
            break;
        case 5:
            currentblock.move(-2,0);
            break;
        case 6:
            currentblock.move(-2,0);
            break;
        case 7:
            currentblock.move(-2,0);
            break;
         }
}
else
{
    switch(currentblock.id)
         {
        case 1:
            currentblock.move(-1,0);
            break;
        case 2:
            currentblock.move(-1,0);
            break;
        case 3:
            currentblock.move(0,0);
            break;
        case 4:
            currentblock.move(-1,0);
            break;
        case 5:
            currentblock.move(-1,0);
            break;
        case 6:
            currentblock.move(-1,0);
            break;
        case 7:
            currentblock.move(-1,0);
            break;
         }
}
        return;
    }
        
        nextblock = getrandomblock();
    

    int linescleared = grid.clearfullrows();
    updatescore(linescleared);

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

void game::updatescore(int rowscleared)
{
    switch (rowscleared)
    {
    case 1:
        score += 1;
        break;
    case 2:
        score += 2;
        break;    
    case 3:
        score += 3;
        break;
    case 4:
        score += 4;
        break;    
    default:
        break;
    }
}

void game::reset()
{
    gameover = false;
    grid.initialize();
    currentblock = getrandomblock();
    nextblock = getrandomblock();
    score = 0;
    
}
