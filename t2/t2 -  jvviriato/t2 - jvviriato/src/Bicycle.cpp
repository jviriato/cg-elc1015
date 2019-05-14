#include "Bicycle.h"

Bicycle::Bicycle(double x, double y)
{
    this->x = x;
    this->y = y;
    double x_wheel_left = x - 50;
    double x_wheel_right = x + 150;
    double x_pedal = x + 70;
    Wheel w1 = Wheel(x_wheel_left, y);
    wheels.push_back(w1);
    Wheel w2 = Wheel(x_wheel_right, y);
    wheels.push_back(w2);
    pedal = new Pedal(x_pedal, y);

    // cria o frame baseado nas rodas da bicicleta
    // dois pontos são apenas para gerar a curva de bezier
    double frames_x[4] = {
        (x_wheel_left),
        (x_pedal),
        (x_pedal),
        (x_wheel_right)};

    double frames_y[4] = {
        (this->y),
        (this->y + 50),
        (this->y + 140),
        (this->y)};

    frame = new Frame(frames_x, frames_y);
}

double Bicycle::getX()
{
    return this->x;
}
double Bicycle::getY()
{
    return this->y;
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
