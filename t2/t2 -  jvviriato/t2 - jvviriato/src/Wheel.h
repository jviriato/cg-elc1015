#ifndef WHEEL_H
#define WHEEL_H
#include "gl_canvas2d.h"
#include "Piece.h"


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
    float x;
    float y;
    int rims;
    std::vector<std::tuple<int, int>> position_rims;
    int radius;
public:
    Wheel(float x, float y, int radius, int rims);
    int getX();
    int getY();
    int getRims();
    int getRadius();
    float calcAngle(int num);
    void drawRims();
    void drawTire();
    void createRims();
    void updateRims();
    std::tuple <float, float> translateMatrix(float x, float y, float offset_x, float offset_y);
    std::tuple <float, float> rotateMatrix(float angle, int x, int y);
    void render();
    ~Wheel();
};

#endif
