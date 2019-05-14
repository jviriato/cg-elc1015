#ifndef BUSH_H
#define BUSH_H
#include "gl_canvas2d.h"
#include "auxFunc.h"
#include <vector>
#include <tuple>
class Bush
{
private:
    double x;
    double y;
    double size;
    double speed;

public:
    Bush();
    void update();
    void render();
    ~Bush();
};

Bush::Bush()
{
    x = 600;
    y = 450;
    size = 1;
    speed = 1;
}

void Bush::render()
{
    color(1, 1, 1);
    circleFill(x, y, 30 * size, 10);
    circleFill(x - 20, y - 10, 30 * size, 10);
    circleFill(x + 20, y - 10, 30 * size, 10);
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

#endif // BUSH_H
