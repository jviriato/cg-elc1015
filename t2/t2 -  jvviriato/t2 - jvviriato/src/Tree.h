#ifndef TREE_H
#define TREE_H
#include "gl_canvas2d.h"
#include "auxFunc.h"
#include <vector>
#include <tuple>
class Tree
{
private:
    double head[2];
    double tronco_x[2];
    double tronco_y[2];
    double speed;
    double size;
    double radius;
    int z_index;

public:
    Tree(double head[2],
         double tronco_x[2],
         double tronco_y[2],
         int z_index,
         double speed);
    Tree();
    void render();
    void update();
    void updateTronco();
    ~Tree();
};

Tree::Tree()
{
    size = .6;
    speed = 5;
    radius = 50;
    this->head[0] = 600;
    this->head[1] = 250 + radius * 0.5;
    this->tronco_x[0] = double(this->head[0] - (10 * size));
    this->tronco_x[1] = double(this->head[0] + (10 * size));
    this->tronco_y[0] = double(this->head[1] - (100 * size));
    this->tronco_y[1] = double(this->head[1]);
    int z_index = -1;
    double speed = z_index * 2;
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

#endif // !TREE_H
