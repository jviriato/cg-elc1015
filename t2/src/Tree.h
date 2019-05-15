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
    Tree(double size);
    void render();
    void update();
    void updateTronco();
    ~Tree();
};

#endif // !TREE_H
