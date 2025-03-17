#include <raylib.h>
#include "grid.h"
#include "colors.h"
#include "blocks.cpp"
int main()
{
    InitWindow(300, 600, "TETRIS");
    SetTargetFPS(60);

    Grid grid=Grid();
    grid.print();
    Tblock block =Tblock();


    while (!WindowShouldClose())

    {
        BeginDrawing();
        ClearBackground(getcellcolors()[8]);
        grid.draw();
        block.draw();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
