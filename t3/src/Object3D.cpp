#include "Bezier.h"
#include "Object3D.h"
#include "auxFunc.h"
#include <iostream>

// origem é por onde a bezier é rotacionada
Object3D::Object3D(Bezier b, Point o)
{
    bezier = b;
    origem = o;
    lados = 10;
    z = 150;
    distance = 200;
}

void Object3D::rotateBezier(double angle, Bezier &b)
{
    b.sub(origem);
    b.rotateY(angle);
    b.add(Point(origem));
}

void Object3D::buildWireframe(Bezier b)
{
    wireframe.clear();
    wireframe_perspective.clear();
    double angle = 360 / lados;
    for (double i = 0; i < lados; i++)
    {
        rotateBezier(angle, b);
        std::vector<Point> linePoints = b.getLinePoints();
        wireframe.push_back(linePoints);
        buildWireframePerspective(linePoints);
    }
}
double x = 0.0;
void Object3D::buildWireframePerspective(std::vector<Point> linePoints)
{
    std::vector<Point> linePointsCamera;
    for (unsigned long i = 0; i < linePoints.size(); i++)
    {

        linePoints[i].sub(origem);
        linePoints[i].rotateX(x * 0.001);
        linePoints[i].rotateY(x * 0.001);
        linePoints[i].add(origem);
        x+=0.1;
        linePoints[i].sub(origem);
        linePoints[i].setZ(linePoints[i].z() + z);
        Point c = linePoints[i].toCamera(distance);
        linePointsCamera.push_back(c);
    }
    wireframe_perspective.push_back(linePointsCamera);
}

void Object3D::drawWireframe()
{
    color(0, 1, 0);
    for (unsigned long i = 0; i < wireframe_perspective.size(); i++)
    {
        for (unsigned long j = 0; j < wireframe_perspective[i].size(); j++)
        {
            //linha vertical
            if (j > 0)
                createLines(wireframe_perspective[i][j], wireframe_perspective[i][(j - 1)]);
            //linha horizontal
            createLines(wireframe_perspective[i][j], wireframe_perspective[(i + 1) % wireframe_perspective.size()][j]);
        }
    }
}

void Object3D::createLines(Point p1, Point p2)
{
    color(1, 0, 0);
    line(p1.x() + 760, p1.y() + 300, p2.x() + 760, p2.y() + 300);
}

void Object3D::render(Bezier b)
{
    buildWireframe(b);
    drawWireframe();
}

double Object3D::getZ()
{
    return z;
}
void Object3D::setZ(double value)
{
    z = value;
}
double Object3D::getLados()
{
    return lados;
}
void Object3D::setLados(double value)
{
    lados = value;
}

double Object3D::getDistance()
{
    return distance;
}
void Object3D::setDistance(double value)
{
    distance = value;
}

void Object3D::setNumberPoints(double value, Bezier &b)
{
    b.setNumberPoints(value);
}

Object3D::~Object3D()
{
}