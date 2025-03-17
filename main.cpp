#include <raylib.h>
#include "game.h"
#include <iostream>

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
        DrawRectangleRounded((Rectangle){320, 55, 170, 60}, 0.3, 6, lightskyblue);
        char Text[10];
        snprintf(Text, sizeof(Text), "%d", Game.score);
        Vector2 textsize = MeasureTextEx(font, Text, 38, 2);
        DrawTextEx(font, Text, {310 + (170 - textsize.x)/2, 65}, 38, 2, WHITE);

        

        DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);
        DrawRectangleRounded((Rectangle){320, 215, 170, 180}, 0.3, 6, lightskyblue);

        if(Game.gameover==true)
        {
            DrawTextEx(font, "GameOver", {320, 450}, 38, 2, WHITE);
            DrawTextEx(font, "Presh R to Restart", {317, 500}, 17, 2, WHITE);
        }

        Game.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
