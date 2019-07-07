#include "CtrlPoint.h"

CtrlPoint::CtrlPoint()
{
    xval = 0;
    yval = 0;
    zval = 0;
}


CtrlPoint::CtrlPoint(double x, double y, double z)
{
    xval = x;
    yval = y;
    zval = z;
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