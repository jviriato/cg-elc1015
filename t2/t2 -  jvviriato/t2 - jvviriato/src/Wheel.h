#ifndef WHEEL_H
#define WHEEL_H
#include <tuple>
#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include "gl_canvas2d.h"
#include "auxFunc.h"
/**
    Wheel.h
    Propósito: Gera Rodas

    @author José Victor Viriato
    @version 0.1 2019
*/

/**
    * @class Wheel
    * Gera rodas.
    * @param x, y: Coordenadas do centro da roda
    * @param radius: Raio da roda
    * @param rims: Aros da roda
*/
class Wheel
{
private:
    double x;
    double y;
    int rims;
    std::vector<std::tuple<double, double>> position_rims;
    int radius;
public:
    Wheel(double x, double y, double radius, int rims);
    Wheel(double x, double y);
    int getX();
    int getY();
    int getRims();
    int getRadius();
    double calcAngle(int num);
    void drawRims();
    void drawTire();
    void createRims();
    void update();
    void render();
    std::tuple <double, double> translateMatrix(double x, double y, double offset_x, double offset_y);
    std::tuple <double, double> rotateMatrix(double angle, double x, double y);
    ~Wheel();
};

#endif
