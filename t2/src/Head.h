#ifndef HEAD_H
#define HEAD_H
#include "gl_canvas2d.h"

/**
    Head.h
    Propósito: Gera a cabeça do personagem

    @author José Victor Viriato
    @version 0.1 2019
**/

class Head
{
private:
    double x;
    double y;

public:
    Head(double x, double y);
    void render();
    ~Head();
};

#endif
