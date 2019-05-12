#include "Pedal.h"

Pedal::Pedal(float x, float y)
{
    this->x = x;
    this->y = y;

    float distance_from_center = 30;
    float offset_y = 2.5;
    this->x_pedal1 = this->x + distance_from_center;
    this->y_pedal1 = this->y - offset_y;

    this->x_pedal2 = this->x - distance_from_center; 
    this->y_pedal2 = this->y - offset_y;
}

void Pedal::createPedal()
{
    // color(0, 0, 0);
    // circleFill(x, y, 15, 50);
}

void Pedal::update()
{
    
}

void Pedal::render()
{
    color(0.1, .2, .2);
    circleFill(x, y, 15, 50);

    color(0, 0.2, 0.4);
    rectFill(x, y-5, x+30, y);
    color(.8,0,0);
    circleFill(this->x_pedal1, this->y_pedal1,5,50);

    color(.8,0,0);
    circleFill(this->x_pedal2, this->y_pedal2,5,50);
}