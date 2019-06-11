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
    Point(double x, double y);
    Point();

    // Extratores.
    double x();
    double y();
    double z();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void sub(Point another);
    void add(Point another);

    // Matriz de translação
    void translateMatrix2D(double offset_x, double offset_y);

    Point toCamera(double d);
    void rotateY(double angle);
    double distance(Point another);

    ~Point();
};
#endif // MACRO
