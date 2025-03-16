#include <raylib.h>

int main()
{
    InitWindow(800, 600, "TETRIS");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw a rectangle
        DrawRectangle(200, 200, 100, 100, RED);

        // Draw some text
        DrawText("Hello, Tetris!", 300, 50, 20, DARKBLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
