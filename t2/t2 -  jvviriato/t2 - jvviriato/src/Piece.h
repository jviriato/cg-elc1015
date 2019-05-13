#if !defined(PIECE_H)
#define PIECE_H
#include <tuple>
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include "gl_canvas2d.h"
#include "auxFunc.h"

class Piece
{
private:
    double x;
    double y;

public:
    Piece(double x, double y);
    void build();
    void update();
    void draw();
    std::tuple<double, double> translateMatrix(double x, double y, double offset_x, double offset_y);
    std::tuple<double, double> rotateMatrix(double angle, int x, int y);
};

#endif
