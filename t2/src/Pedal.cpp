#include "Pedal.h"
#include "auxFunc.h"

Pedal::Pedal(double x, double y)
{
    this->x = x;
    this->y = y;

    double distance_from_center = 20;
    double offset_y = 2.5;
    this->x_pedal_esq = this->x + distance_from_center;
    this->y_pedal_esq = this->y - offset_y;
    this->x_pedal_dir = this->x - distance_from_center;
    this->y_pedal_dir = this->y - offset_y;
}


double Pedal::getPedalLeftX()
{
    return this->x_pedal_esq;
}

double Pedal::getPedalLeftY()
{
    return this->y_pedal_esq;
}

double Pedal::getPedalRightX()
{
    return this->x_pedal_dir;
}

double Pedal::getPedalRightY()
{
    return this->y_pedal_dir;
}

void Pedal::update()
{
    double pedal_x1 = this->x_pedal_esq;
    double pedal_y1 = this->y_pedal_esq;
    std::tuple<double, double> coords = std::make_tuple(pedal_x1, pedal_y1);
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), -this->x, -this->y);
    coords = rotateMatrix(-2, std::get<0>(coords), std::get<1>(coords));
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), this->x, this->y);
    x_pedal_esq = std::get<0>(coords);
    y_pedal_esq = std::get<1>(coords);

    double pedal_x2 = this->x_pedal_dir;
    double pedal_y2 = this->y_pedal_dir;
    coords = std::make_tuple(pedal_x2, pedal_y2);
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), -this->x, -this->y);
    coords = rotateMatrix(-2, std::get<0>(coords), std::get<1>(coords));
    coords = translateMatrix(std::get<0>(coords), std::get<1>(coords), this->x, this->y);
    x_pedal_dir = std::get<0>(coords);
    y_pedal_dir = std::get<1>(coords);
}

void Pedal::render()
{
    color(0.1, .2, .2);
    circleFill(x, y, 15, 50);
    circleFill(this->x_pedal_esq, this->y_pedal_esq, 5, 50);
    circleFill(this->x_pedal_dir, this->y_pedal_dir, 5, 50);
}

Pedal::~Pedal()
{
}
