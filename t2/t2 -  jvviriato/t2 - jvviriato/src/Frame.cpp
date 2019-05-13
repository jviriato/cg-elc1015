#include "Frame.h"

Frame::Frame(double coords_x[4], double coords_y[4])
{
    for (int i = 0; i < 4; i++)
    {
        this->coords_x[i] = coords_x[i];
        this->coords_y[i] = coords_y[i];
    }
}

void Frame::render()
{
    std::vector<std::tuple<double, double>> coords;
    for (auto i = 0; i < 4; i++)
    {
        coords.push_back(std::make_tuple(this->coords_x[i], this->coords_y[i]));
    }
    color(1, 0, 0);
    bezier(coords);
    rectFill(this->coords_x[0], this->coords_y[0] - 5, this->coords_x[3], this->coords_y[0]);
    color(0, 0, 0);
    double seat_x = coords_x[1] - 10;
    double seat_y = coords_y[1];
    rectFill(seat_x, seat_y, seat_x - 20, seat_y - 10);
}

Frame::~Frame()
{
}
