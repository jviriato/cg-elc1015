#include "Tree.h"
#include <iostream>

Tree::Tree(double size)
{
    this->size = size;
    // size  = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    if(size < 0.4){
        z_index = 1;
    } else if (size < 0.7) {
        z_index = 2;
    } else if (size <= 1) {
        z_index = 3;
    }
    speed = 1.5 * z_index * z_index;
    std::cout << speed << ' ' << size << std::endl;
    radius = 50;
    this->head[0] = (rand() % 800) + 400;
    this->head[1] = (200) + radius * 0.5;
    this->tronco_x[0] = double(this->head[0] - (10 * size));
    this->tronco_x[1] = double(this->head[0] + (10 * size));
    this->tronco_y[0] = double(this->head[1] - (100 * size));
    this->tronco_y[1] = double(this->head[1]);
}
Tree::Tree(double head[2],
           double tronco_x[2],
           double tronco_y[2],
           int z_index,
           double speed)
{
}

void Tree::render()
{
    std::vector<double> rgb = RGBtodouble(106, 65, 45);
    color(rgb[0], rgb[1], rgb[2]);

    rectFill(tronco_x[0], tronco_y[0], tronco_x[1], tronco_y[1]);
    rgb.clear();
    rgb = RGBtodouble(61, 95, 58);
    color(rgb[0], rgb[1], rgb[2]);
    circleFill(head[0], head[1], (size * radius), 30);
}

void Tree::update()
{
    double y_horizonte = 200;

    std::tuple<double, double> coords_tree = std::make_tuple(head[0], head[1]);
    // coords_tree = translateMatrix(std::get<0>(coords_tree), std::get<1>(coords_tree), 0, 0);

    coords_tree = translateMatrix(std::get<0>(coords_tree), std::get<1>(coords_tree), speed * -.2, 0);

    this->head[0] = std::get<0>(coords_tree);
    this->head[1] = std::get<1>(coords_tree);
    this->updateTronco();
}

void Tree::updateTronco()
{
    this->tronco_x[0] = double(this->head[0] - (10 * size));
    this->tronco_x[1] = double(this->head[0] + (10 * size));
    this->tronco_y[0] = double(this->head[1] - (100 * size));
    this->tronco_y[1] = double(this->head[1]);
}

Tree::~Tree()
{
}