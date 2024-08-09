#include <iostream>
#include "raylib.h"
#include "Line.h"
#include "BrenshamLines.h"

int main()
{
    Color bgColor = Color{ 255, 255, 255, 255 };

    InitWindow(800, 600, "Swirly Circles Algorithms");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(bgColor);

        // Círculo usando DDA
        double radius = 150.0;
        double circumference = 36;
        int centerX = 400;
        int centerY = 300;
        float x2, y2;
        double angleIncrement = 2 * PI / circumference;
        float xbres = 5;
        float ybres = 5;

        //Este for es Brensenham
        for (int i = 0; i < 9; i++)
        {
            xbres += 16;
            ybres += 16;
           BresenhamLine(centerX, centerY, xbres, ybres);
        }

        //Este for es DDA
        for (int i = 0; i < circumference; i++)
        {
            x2 = radius * cos(i * angleIncrement) + centerX;
            y2 = radius * sin(i * angleIncrement) + centerY;
            //Line(centerX, x2, centerY, y2);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

