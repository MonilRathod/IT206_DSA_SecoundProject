#include <raylib.h>
#include "game.h"

double lastupdatetime = 0;

bool eventtriggered(double interval)
{
    double currenttime = GetTime();
    if(currenttime - lastupdatetime >= interval)
    {
        lastupdatetime = currenttime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "TETRIS");
    SetTargetFPS(60);

    Font font = LoadFontEx("resources/ARCADECLASSIC.TTF", 64, 0, 0);


    game Game = game();


    while (!WindowShouldClose())

    {
        BeginDrawing();
        ClearBackground(getcellcolors()[8]);
        Game.handleinput();
        if(eventtriggered(0.5))
        {
            Game.moveblockdown();
        }

        Game.draw();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
