#define PEDAL_H
#include <tuple>
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include "gl_canvas2d.h"
#include "auxFunc.h"
/**
    Pedal.h
    Propósito: Gerar Pedais

    @author José Victor Viriato
    @version 0.1 2019
**/

class Pedal
{
private:
    double x;
    double y;
    double x_pedal_esq;
    double x_pedal_dir;
    double y_pedal_esq;
    double y_pedal_dir;
public:
    Pedal(double x, double y);
    Pedal();
    void createPedal();
    void update();
    void render();
    ~Pedal();
};
