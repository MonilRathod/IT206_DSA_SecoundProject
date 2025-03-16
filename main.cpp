#include <raylib.h>

int main()
{
   InitWindow(800, 600, "TETRIS");
   SetTargetFPS(60);
   while(WindowShouldClose() == false)
   {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      EndDrawing();
   }
   CloseWindow();
    
}
