#include "Graphic.h"
#include "auxFunc.h"

Graphic::Graphic(int x, int y, int height, string label)
{
    setPosition(x, y);
    setLabel(label);
    setSize(height);
    size_canvas = width/2;
}

void Graphic::setSize(int height)
{
    height = height;
    width = height;
}

void Graphic::render()
{
    createBackgroundRectangle();
    createRectangle();
    createTitleBar();
    createMiddleLine();
}

void Graphic::createTitleBar()
{
    int top = getY() + size_canvas;
    int offset = 2;
    vector<float> rgb = RGBtoFloat(46, 49, 49);
    color(rgb[0], rgb[1], rgb[2]);
    text(getX() + offset, top + offset, getLabel());
}

void Graphic::createMiddleLine()
{
    float middle = ((getY() + (getY() + size_canvas) )) / 2;
    vector<float> rgb = RGBtoFloat(46, 49, 49);
    color(rgb[0], rgb[1], rgb[2]);
    line(getX(), middle, getX() + getWidth(), middle);
}

void Graphic::createBackgroundRectangle()
{
    vector<float> rgb = RGBtoFloat(242, 241, 239);
    color(rgb[0], rgb[1], rgb[2]);
    // rect(getX(), getY(), getX() + (getWidth() * 2), getX() + getWidth());
    rectFill(getX(), getY(), getX() + getWidth() - 1, getY() + size_canvas -1);
}

void Graphic::createRectangle()
{
    vector<float> rgb = RGBtoFloat(46, 49, 49);
    color(rgb[0], rgb[1], rgb[2]);
    // rect(getX(), getY(), getX() + (getWidth() * 2), getX() + getWidth());
    rect(getX(), getY(), getX() + getWidth(), getY() + size_canvas);
    // printf("x: %d y: %d\nx2: %d, y2: %d\n", getX(), getY(), getX() + getWidth(), getY() + size_canvas);
}

float Graphic::getArea()
{
    return (width * height);
}
