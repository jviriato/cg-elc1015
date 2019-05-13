#include "Pedal.h"
#include "auxFunc.h"

Pedal::Pedal(double x, double y)
{
    this->x = x;
    this->y = y;

    double distance_from_center = 20;
    double offset_y = 2.5;
    this->x_pedal1 = this->x + distance_from_center;
    this->y_pedal1 = this->y - offset_y;
    this->x_pedal2 = this->x - distance_from_center;
    this->y_pedal2 = this->y - offset_y;
}

void Pedal::update()
{
    double pedal_x1 = this->x_pedal1;
    double pedal_y1 = this->y_pedal1;
    std::tuple<double, double> coords = std::make_tuple(pedal_x1, pedal_y1);
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), -this->x, -this->y);
    coords = rotateMatrix(-2, std::get<0>(coords), std::get<1>(coords));
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), this->x, this->y);
    x_pedal1 = std::get<0>(coords);
    y_pedal1 = std::get<1>(coords);

    double pedal_x2 = this->x_pedal2;
    double pedal_y2 = this->y_pedal2;
    coords = std::make_tuple(pedal_x2, pedal_y2);
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), -this->x, -this->y);
    coords = rotateMatrix(-2, std::get<0>(coords), std::get<1>(coords));
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), this->x, this->y);
    x_pedal2 = std::get<0>(coords);
    y_pedal2 = std::get<1>(coords);
}

void Pedal::render()
{
    color(0.1, .2, .2);
    circleFill(x, y, 15, 50);

    color(0, 0.2, 0.4);
    rectFill(x, y - 5, x + 30, y);
    color(.8, 0, 0);
    circleFill(this->x_pedal1, this->y_pedal1, 5, 50);

    color(.8, 0, 0);
    circleFill(this->x_pedal2, this->y_pedal2, 5, 50);
}

Pedal::~Pedal()
{
}
