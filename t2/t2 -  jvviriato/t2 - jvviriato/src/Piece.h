#if !defined(PIECE_H)
#define PIECE_H
#include <tuple>
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include "gl_canvas2d.h"

class Piece
{
private:
    float x;
    float y;

public:
    Piece(float x, float y);
    void build();
    void update();
    void draw();
    std::tuple<float, float> translateMatrix(float x, float y, float offset_x, float offset_y);
    std::tuple<float, float> rotateMatrix(float angle, int x, int y);

    ~Piece();
};

#endif
