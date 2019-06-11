#include "Bezier.h"
#include "Object3D.h"
#include "auxFunc.h"
#include <iostream>

// origem é por onde a bezier é rotacionada
Object3D::Object3D(Bezier b, Point o)
{
    bezier = b;
    origem = o;
}

void Object3D::rotateBezier(double angle, Bezier &b)
{
    b.sub(origem);
    b.rotateY(angle);
    b.add(Point(origem));
}

void Object3D::buildWireframe(Bezier b, double lados)
{
    wireframe.clear();
    wireframe_perspective.clear();
    double angle = 360 / lados;
    for (double i = 0; i < lados; i++)
    {
        rotateBezier(angle, b);
        std::vector<Point> linePoints = b.getLinePoints();
        wireframe.push_back(linePoints);
        buildWireframePerspective(linePoints, 100);
    }
}

void Object3D::buildWireframePerspective(std::vector<Point> linePoints, double dist)
{
    std::vector<Point> linePointsCamera;
    for (unsigned long i = 0; i < linePoints.size(); i++)
    {
        linePoints[i].sub(origem);
        linePoints[i].setZ(linePoints[i].z() + 150);
        Point c = linePoints[i].toCamera(100);
        linePointsCamera.push_back(c);
    }
    wireframe_perspective.push_back(linePointsCamera);
}

void Object3D::drawWireframe()
{
    color(0, 1, 0);
    for (unsigned long i = 0; i < wireframe.size(); i++)
    {
        for (unsigned long j = 0; j < wireframe[i].size(); j++)
        {
            // std::cout << "x[" <<i<<"]["<<j<<"]: " << wireframe[i][j].x() << std::endl;
            // std::cout << "y[" <<i<<"]["<<j<<"]: " << wireframe[i][j].y() << std::endl;

            color(0,1,0);
            point(wireframe[i][j].x(), wireframe[i][j].y());
            color(1,0,0);
            point(wireframe_perspective[i][j].x() + 300, wireframe_perspective[i][j].y() + 100);
            
            //linha vertical
            if (j > 0)
                createLines(wireframe_perspective[i][j], wireframe_perspective[i][(j - 1)]);
            //linha horizontal
            createLines(wireframe_perspective[i][j], wireframe_perspective[(i+1) % wireframe_perspective.size()][j]);
        }
    }
}

void Object3D::createLines(Point p1, Point p2)
{
    color(1,0,0);
    line(p1.x() + 300, p1.y() + 100, p2.x() + 300 , p2.y() + 100);
}

void Object3D::render(Bezier b)
{
    buildWireframe(b, 50);
    drawWireframe();
}

Object3D::~Object3D()
{
}