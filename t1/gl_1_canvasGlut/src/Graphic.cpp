#include "Graphic.h"
#include "auxFunc.h"

Graphic::Graphic(int x, int y, int height, string label)
{
    setPosition(x, y);
    setLabel(label);
    setSize(height);
    size_canvas = width / 2;
    vector<double> pontos;
}

void Graphic::setSize(int height)
{
    width = height;
    height = width / 2;
}

void Graphic::render()
{
    createBackgroundRectangle();
    createRectangle();
    createTitleBar();
    createMiddleLine();
    putDots();
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
    float middle = ((getY() + (getY() + size_canvas))) / 2;
    vector<float> rgb = RGBtoFloat(46, 49, 49);
    color(rgb[0], rgb[1], rgb[2]);
    line(getX(), middle, getX() + getWidth(), middle);
}

void Graphic::createBackgroundRectangle()
{
    vector<float> rgb = RGBtoFloat(242, 241, 239);
    color(rgb[0], rgb[1], rgb[2]);
    rectFill(getX(), getY(), getX() + getWidth() - 1, getY() + size_canvas - 1);
}

void Graphic::createRectangle()
{
    vector<float> rgb = RGBtoFloat(46, 49, 49);
    color(rgb[0], rgb[1], rgb[2]);
    rect(getX(), getY(), getX() + getWidth(), getY() + size_canvas);
}

void Graphic::loadVector(vector<double> pts)
{
    this->pontos = pts;
}

void Graphic::putDots()
{
    double top    = getY() + size_canvas;
    double middle = ((getY() + (getY() + size_canvas))) / 2;
    double bottom = getY() ;// + getX();
    double offset = 25;
    double space_x = (width - offset) / (pontos.size());
    double space_y = (size_canvas/2) - 10; // pra nunca chegar no topo
    vector<float> rgb = RGBtoFloat(210, 77, 87);
    color(rgb[0], rgb[1], rgb[2]);
    for(auto i = 0; i < pontos.size(); i++){
        double number_scaled = pontos[i] / getBiggest();
        printf("[%d] %f\n", i, pontos[i]);
        circleFill(getX() + offset + (i * space_x), (middle + (number_scaled * space_y)), 5, 100);
    }
}

double Graphic::getBiggest()
{
    double biggest = abs(pontos[0]);
    for(auto i = 0; i < pontos.size(); i++){
        if( abs(pontos[i]) > biggest )
            biggest = abs(pontos[i]);
    }
    return biggest;
}

float Graphic::getArea()
{
    return (width * height);
}
