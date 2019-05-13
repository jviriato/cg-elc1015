#ifndef FRAME_H
#define FRAME_H
#include "auxFunc.h"
#include "gl_canvas2d.h"

class Frame
{
private:
    double coords_x[4];
    double coords_y[4];


public:
    Frame(double coords_x[4], double coords_y[4]);
    void render();
    ~Frame();
};

#endif
