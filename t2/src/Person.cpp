#include "Person.h"

Person::Person(double x, double y)
{
    this->x = x;
    this->y = y;
    head = new Head(this->x, this->y);
    body = new Body(this->x, this->y);

    l1 = new Leg(55);
    l2 = new Leg (55);

}

void Person::render()
{
    color(0,0,0);
    head->render();
    body->render();

    l1->render();
    l2->render();
}

Person::~Person()
{
}