#pragma once
#include <iostream>
#include "raylib.h"
#include "Line.h"
#include <vector>
#include <algorithm>

class BresenhamLine
{
public:
    //Las variables
    float posX1, posX2, posY1, posY2, deltaX, deltaY, pNext, step;
    Color color;
    
    BresenhamLine(float x1, float y1, float x2, float y2, Color color = BLACK)
        : posX1(x1), posX2(x2), posY1(y1), posY2(y2), color(color)
    {
        circleBres(posX1,posY1, posX2);

    }
    //Con esto se dibuja los pixeles de las lineas.
    void drawCircle(int xc, int yc, int x, int y)
    {
        DrawPixel(xc + x, yc + y, BLACK);
        DrawPixel(xc - x, yc + y, BLACK);
        DrawPixel(xc + x, yc - y, BLACK);
        DrawPixel(xc - x, yc - y, BLACK);
        DrawPixel(xc + y, yc + x, BLACK);
        DrawPixel(xc - y, yc + x, BLACK);
        DrawPixel(xc + y, yc - x, BLACK);
        DrawPixel(xc - y, yc - x, BLACK);
    }

    //Aqui se uso el algortimo de brensenham
    void circleBres(int xc, int yc, int r)
    {
        int x = 0, y = r;
        int d = 3 - 2 * r;
        drawCircle(xc, yc, x, y);
        while (y >= x)
        {
            //Se dibujo por pixeles las lineas
            x++;


            //Aqui checa el parametro por cada posicion y actualiza en d, x, y.
            if (d > 0)
            {
                y--;
                d = d + 4 * (x - y) + 10;
            }
            else
                d = d + 4 * x + 6;
            drawCircle(xc, yc, x, y);

        }
    }
};