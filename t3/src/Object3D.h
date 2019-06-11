#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <cmath>
#include <vector>
#include "gl_canvas2d.h"
#include "Point.h"
#include "Bezier.h"
class Object3D
{
protected:
    std::vector<std::vector<Point>> wireframe;
    std::vector<std::vector<Point>> wireframe_perspective;
    Bezier bezier;
    Point origem;
public:
    Object3D(Bezier b, Point o);
    void buildWireframe(Bezier b, double lados);
    void drawWireframe();
    void render(Bezier b);
    void rotateBezier(double angle, Bezier &b);
    void buildWireframePerspective(std::vector<Point> linePointsCamera, double dist);
    void createLines(Point p1, Point p2);
    ~Object3D();
};

#endif