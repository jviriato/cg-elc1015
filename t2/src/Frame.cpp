#include "Frame.h"

Frame::Frame(double coords_x[4], double coords_y[4])
{
    for (int i = 0; i < 4; i++)
    {
        this->coords_x[i] = coords_x[i];
        this->coords_y[i] = coords_y[i];
    }
    this->coords_seat[0] = this->coords_x[1] - 25;
    this->coords_seat[1] = this->coords_y[1] + 20;
}

double Frame::getSeatX()
{
    return this->coords_seat[0];
}

double Frame::getSeatY()
{
    return this->coords_seat[1];
}

void Frame::render()
{
    double x_pedal = this->coords_x[0] + 120;
    // frame
    std::vector<std::tuple<double, double>> coords;
    for (auto i = 0; i < 3; i++)
    {
        coords.push_back(std::make_tuple(this->coords_x[i], this->coords_y[i]));
    }
    // offset para que o fim da bezier não fique na roda, e sim no guidão
    coords.push_back(std::make_tuple(this->coords_x[3], this->coords_y[3] + 80));

    color(1, 0, 0);
    bezier(coords);
    coords.clear();

    // roda direita até o guidao
    color(1, 0, 0);
    line(this->coords_x[3], this->coords_y[3], this->coords_x[3] - 50, this->coords_y[3] + 100);
    line(this->coords_x[0], this->coords_y[0], x_pedal, this->coords_y[0]);
    line(x_pedal, this->coords_y[0], this->coords_seat[0] - 10, this->coords_seat[1]);
    line(x_pedal, this->coords_y[0], this->coords_x[3] - 30, this->coords_y[3] + 60);

    // seat
    color(0, 0, 0);
    rectFill(this->coords_seat[0], this->coords_seat[1], this->coords_seat[0] - 20, this->coords_seat[1] - 15);
}

Frame::~Frame()
{
}
