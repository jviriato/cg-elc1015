#include "Bush.h"

Bush::Bush(double size)
{
    this->size = size;
    // size  = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    if (size < 0.4)
    {
        z_index = 1;
    }
    else if (size < 0.7)
    {
        z_index = 2;
    }
    else if (size <= 1)
    {
        z_index = 3;
    }

    speed = .3 * z_index * z_index;
    this->x = (rand() % 400) + 400;
    this->y = (rand() % 250) + 350;
}

void Bush::render()
{
    double radius = 15 * z_index;
    color(1, 1, 1);
    circleFill(x, y, radius, 10);
    circleFill(x - 20, y - 5, radius, 10);
    circleFill(x + 20, y - 5, radius, 10);
}

void Bush::update()
{
    std::tuple<double, double> coords_cloud = std::make_tuple(x, y);
    coords_cloud = translateMatrix(std::get<0>(coords_cloud), std::get<1>(coords_cloud), speed * -.2, 0);
    this->x = std::get<0>(coords_cloud);
    this->y = std::get<1>(coords_cloud);
}

Bush::~Bush()
{
}
