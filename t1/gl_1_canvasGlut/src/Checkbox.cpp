#include "Checkbox.h"
#include <math.h>
using namespace std;

Checkbox::Checkbox(int x, int y, string l)
{
    setPosition(x, y);
    setLabel(l);
}

void Checkbox::checkboxActions(int mx, int my, int state)
{
    isInside = false;
    int click = 0;

    if (detectCollision(mx, my))
    {
        isInside = true;
        if (state == click && isPressed == false)
        {
            isPressed = true;
        }
        else if (state == click && isPressed == true)
        {
            isPressed = false;
        }
    }
    else
    {
        isInside = false;
    }
}

void Checkbox::drawInactive()
{
    color(1, 1, 1);
    circleFill(getX(), getY(), 15, 50);
    color(0, 0, 0);
    circle(getX(), getY(), 15, 50);
}

void Checkbox::drawActive()
{
    color(1, 1, 1);
    circleFill(getX(), getY(), 15, 50);
    color(0, 0, 0);
    circle(getX(), getY(), 15, 50);
    circleFill(getX(), getY(), 10, 50);
}

bool Checkbox::detectCollision(int mouse_x, int mouse_y)
{
    int x = pow(mouse_x - getX(), 2);
    int y = pow(mouse_y - getY(), 2);
    int f = pow(15, 2);
    if (x + y <= f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Checkbox::render()
{
    if (isPressed)
    {
        drawActive();
    }
    else
    {
        drawInactive();
    }
    text(getX() + 20, getY() - 5, getLabel());
}

float Checkbox::getArea()
{
    return (M_PI * 5) / 2;
}