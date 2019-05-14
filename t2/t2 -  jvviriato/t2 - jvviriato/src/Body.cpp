#include "Body.h"

Body::Body(double head_x,
           double head_y)
{
    this->head_x = head_x;
    this->head_y = head_y;
}

void Body::render()
{
    color(0, 0, 0);
    line(head_x, head_y, head_x - 5, head_y - 80);
    color(1, 0, 0);
    circleFill(head_x - 5, head_y - 80, 2, 5);
    color(0,0,0);
    line(head_x, head_y - 40, head_x + 60, head_y - 50);
}

Body::~Body()
{
}