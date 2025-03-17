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
        Game.handleinput();
        if(eventtriggered(0.5))
        {
            Game.moveblockdown();
        }
        BeginDrawing();
        ClearBackground(getcellcolors()[8]);
        DrawTextEx(font, "Score", {350, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {350, 175}, 38, 2, WHITE);
        DrawRectangleRounded((Rectangle){320, 55, 170, 60}, 0.3, 6, lightskyblue);
        DrawRectangleRounded((Rectangle){320, 215, 170, 180}, 0.3, 6, lightskyblue);

        Game.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
