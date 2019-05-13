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
*/

class Pedal
{
private:
    double x;
    double y;
    double x_pedal1;
    double x_pedal2;
    double y_pedal1;
    double y_pedal2;
public:
    Pedal(double x, double y);
    Pedal();
    void createPedal();
    void update();
    void render();
    ~Pedal();
};
