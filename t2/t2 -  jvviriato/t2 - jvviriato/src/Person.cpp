#include "Person.h"

Person::Person(double x, double y)
{
    this->x = x;
    this->y = y;
    head = new Head(this->x, this->y);
}

void Person::render()
{
    color(0,0,0);
    head->render();
}

Person::~Person()
{
}