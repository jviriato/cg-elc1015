#include "Button.h"
#include <string>
#include "auxFunc.h"
using namespace std;

Button::Button(int x, int y, int width, int height, string l, float r, float g, float b)
{
    setColor(r, g, b);
    setPosition(x, y);
    setSize(width, height);
    setLabel(l);
}

void Button::render()
{
    float middle_of_the_box = getY() + (getHeight() / 2);
    // drawCollisionBox();
    if (isInside)
    {
        color(1, 0, 0);
        rectFill(getX(), getY(), getX() + getWidth(), getY() + getHeight());
        color(0, 0, 0); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    }
    else
    {
        color(r, g, b);
        rect(getX(), getY(), getX() + getWidth(), getY() + getHeight());
        color(0, 0, 0); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    }
    if (isPressed)
    {
        vector<float> rgb = RGBtoFloat(115, 101, 152);
        color(rgb[0], rgb[1], rgb[2]); // cor do texto
        rectFill(getX(), getY(), getX() + getWidth(), getY() + getHeight());
        color(1, 1, 1); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    }
    else
    {
        color(r, g, b);
        rectFill(getX(), getY(), getX() + getWidth(), getY() + getHeight());
        color(0, 0, 0); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    }
    drawCollisionBox();
}

void Button::drawCollisionBox()
{
    color(0, 0, 0);
    rect(getX(), getY(), getX() + getWidth(), getY() + getHeight());
}

bool Button::detectCollision(int mouse_x, int mouse_y)
{
    if ((mouse_x > getX() && mouse_x < (getX() + getWidth())) &&
        (mouse_y > getY() && mouse_y < (getY() + getHeight())))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Button::reset()
{
    isInside  = false;
    isPressed = false;
}

void Button::buttonActions(int mouse_x, int mouse_y, int state)
{
    isInside = false;
    int click = 0;

    if (detectCollision(mouse_x, mouse_y))
    {
        isInside = true;
        // Verifica se o botão foi clicado
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

float Button::getArea()
{
    return (width * height);
}

Button::~Button()
{
}