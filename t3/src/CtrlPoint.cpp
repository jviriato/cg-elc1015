#include "CtrlPoint.h"

CtrlPoint::CtrlPoint(double x, double y)
{
    xval = x;
    yval = y;
}

void CtrlPoint::setCanEditToTrue()
{
    canEdit = true;
}

void CtrlPoint::setCanEditToFalse()
{
    canEdit = false;
}

bool CtrlPoint::getCanEdit()
{
    return canEdit;
}

bool CtrlPoint::detectColision(int mouse_x, int mouse_y)
{
    double radius = 5;
    return (mouse_x - xval) * (mouse_x - xval) +
           (mouse_y - yval) * (mouse_y - yval) <
           radius*radius;
}