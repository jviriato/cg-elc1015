#ifndef BODY_H
#define BODY_H
#include <vector>
#include <tuple>
#include "gl_canvas2d.h"

/**
    Body.h
    Propósito: Gera o tronco de uma Pessoa

    @author José Victor Viriato
    @version 0.1 2019
**/

class Body
{
private:
    double head_x;
    double head_y;

public:
    Body(double head_x,
         double head_y);
    void render();
    ~Body();
};

#endif
