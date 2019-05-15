#include "Head.h"

Head::Head(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Head::render()
{
    color(0,0,0);
    circleFill(this->x, this->y, 20, 50);
}

Head::~Head()
{
}
