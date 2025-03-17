#include <raylib.h>
#include "grid.h"
int main()
{
    Color darkblue = { 111,133,151, 255 };
    InitWindow(300, 600, "TETRIS");
    SetTargetFPS(60);

    Grid grid=Grid();
    grid.print();
    while (!WindowShouldClose())

    {
        BeginDrawing();
        ClearBackground(darkblue);
        grid.draw();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
