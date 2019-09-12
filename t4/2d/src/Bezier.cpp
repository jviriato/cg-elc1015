#include "Bezier.h"
#include "Point.h"
#include "CtrlPoint.h"
#include <iostream>
Bezier::Bezier()
{
    ctrlPoints.push_back(CtrlPoint(0, 0));
    ctrlPoints.push_back(CtrlPoint(0, 0));
    ctrlPoints.push_back(CtrlPoint(0, 0));
    ctrlPoints.push_back(CtrlPoint(0, 0));
    num = .1;
}

Bezier::Bezier(std::vector<CtrlPoint> points)
{
    for (CtrlPoint ctrlPoint : points)
    {
        ctrlPoints.push_back(ctrlPoint);
    }
    num = .1;
}

// Calcula a Bezier
void Bezier::calculate()
{
    linePoints.clear();
    double t = 0.0;
    int n = 4;
    for (t = 0.0; t <= 1.0; t += num)
    {
        double blending_functions[4] = {
            (pow((1 - t), 3)),
            (3 * t * (pow((1 - t), 2))),
            (3 * t * t * (1 - t)),
            (t * t * t)};
        double xt = blending_functions[0] * ctrlPoints[0].x() +
                    blending_functions[1] * ctrlPoints[1].x() +
                    blending_functions[2] * ctrlPoints[2].x() +
                    blending_functions[3] * ctrlPoints[3].x();

        double yt = blending_functions[0] * ctrlPoints[0].y() +
                    blending_functions[1] * ctrlPoints[1].y() +
                    blending_functions[2] * ctrlPoints[2].y() +
                    blending_functions[3] * ctrlPoints[3].y();
        linePoints.push_back(Point(xt, yt));
    }
}

void Bezier::drawControlPoints()
{
    for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin(); it != ctrlPoints.end(); ++it)
    {
        if (it->getCanEdit())
        {
            color(1, 0, 0);
            circleFill(it->x(), it->y(), 5, 50);
        }
        else
        {
            color(0, 1, 0);
            circleFill(it->x(), it->y(), 5, 50);
        }
    }
}

void Bezier::drawLine()
{
    double t = 0.0;
    for (t = 0.0; t <= 1.0; t += 0.001)
    {
        double blending_functions[4] = {
            (pow((1 - t), 3)),
            (3 * t * (pow((1 - t), 2))),
            (3 * t * t * (1 - t)),
            (t * t * t)};
        double xt = blending_functions[0] * ctrlPoints[0].x() +
                    blending_functions[1] * ctrlPoints[1].x() +
                    blending_functions[2] * ctrlPoints[2].x() +
                    blending_functions[3] * ctrlPoints[3].x();

        double yt = blending_functions[0] * ctrlPoints[0].y() +
                    blending_functions[1] * ctrlPoints[1].y() +
                    blending_functions[2] * ctrlPoints[2].y() +
                    blending_functions[3] * ctrlPoints[3].y();
        point(xt, yt);
    }
}

void Bezier::draw()
{
    color(0, 1, 0);
    drawLine();
    color(1, 0, 0);
    drawControlPoints();
}

void Bezier::render(int mouse_x, int mouse_y, int button)
{
    for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin(); it != ctrlPoints.end(); ++it)
    {
        if (it->getCanEdit())
        {
            it->setX(mouse_x);
            it->setY(mouse_y);
        }
    }
    calculate();
    draw();
}

void Bezier::checkForCollisions(int mouse_x, int mouse_y, int button)
{
    for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin(); it != ctrlPoints.end(); ++it)
    {
        if (it->detectColision(mouse_x, mouse_y) && button == 0 && !it->getCanEdit())
        {
            it->setCanEditToTrue();
        }
        else if (button == 0 && it->getCanEdit())
        {
            it->setCanEditToFalse();
        }
    }
}

void Bezier::translate(double offset_x, double offset_y)
{
    for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin(); it != ctrlPoints.end(); ++it)
    {
        it->translateMatrix2D(-it->x(), -it->y());
    }
}

void Bezier::rotateY(double angle)
{
    for (std::vector<Point>::iterator it = linePoints.begin(); it != linePoints.end(); ++it)
    {
        it->rotateY(angle);
    }

    for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin(); it != ctrlPoints.end(); ++it)
    {
        it->rotateY(angle);
    }
}

void Bezier::sub(Point point)
{
    for (std::vector<Point>::iterator it = linePoints.begin(); it != linePoints.end(); ++it)
    {
        it->sub(point);
    }
    for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin(); it != ctrlPoints.end(); ++it)
    {
        it->sub(point);
    }
}

void Bezier::add(Point point)
{
    for (std::vector<Point>::iterator it = linePoints.begin(); it != linePoints.end(); ++it)
    {
        it->add(point);
    }
    for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin(); it != ctrlPoints.end(); ++it)
    {
        it->add(point);
    }
}

std::vector<Point> Bezier::getLinePoints()
{
    return linePoints;
}

std::vector<CtrlPoint> Bezier::getCtrlPoints()
{
    return ctrlPoints;
}
double Bezier::getNumberPoints()
{
    return num;
}
void Bezier::setNumberPoints(double value)
{
    num = value;
}
void Bezier::drawRepresentationBezier()
{
}

Bezier::~Bezier() {}
