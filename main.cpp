#include <raylib.h>
#include "colors.h"
#include "game.h"
int main()
{
    InitWindow(300, 600, "TETRIS");
    SetTargetFPS(60);

    game Game = game();


    while (!WindowShouldClose())

    {
        BeginDrawing();
        ClearBackground(getcellcolors()[8]);
        Game.handleinput();
        Game.moveblockdown();

        Game.draw();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
