#include "Bicycle.h"

Bicycle::Bicycle(double x, double y)
{
    this->x = x;
    this->y = y;
    Wheel w1 = Wheel(x - 50, y);
    wheels.push_back(w1);
    Wheel w2 = Wheel(x + 150, y);
    wheels.push_back(w2);
    pedal = new Pedal(x + 50.00, y);

    double frames_x[4] = {
        (this->x - 50.00),
        (this->x + 50),
        (this->x + 50),
        (this->x + 150.00)};

    double frames_y[4] = {
        (this->y),
        (this->y + 50),
        (this->y + 50),
        (this->y)};

    frame = new Frame(frames_x, frames_y);
}

void Bicycle::createBicycle()
{
}

void Bicycle::update()
{
    for (Wheel &w : wheels)
    {
        w.update();
    }
    pedal->update();
}

void Bicycle::render()
{
    for (Wheel &w : wheels)
    {
        w.render();
    }
    frame->render();
    pedal->render();
}
