#ifndef POINT_H
#define POINT_H
#include <cmath>
#include "auxFunc.h"

// Propósito: Um ponto no plano cartesiano
class Point
{
protected:
    double xval;
    double yval;
    double zval;

public:
    Point(double x = 0.0, double y = 0.0, double z = 1.0);

    // Getters e Setters
    double x();
    double y();
    double z();
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    // Operações com pontos
    Point sub(Point another);
    Point add(Point another);

    // Norma do vetor
    double norm();

    // Matriz de translação
    void translateMatrix2D(double offset_x, double offset_y);

    // Transforma o ponto para a perspectiva da câmera
    Point toCamera(double d);

    // Rotaciona nos eixos X, Y e Z
    void rotateY(double angle);
    void rotateX(double angle);
    void rotateZ(double angle);
    // Distância até outro ponto
    double distance(Point another);

    ~Point();
};
#endif // MACRO
