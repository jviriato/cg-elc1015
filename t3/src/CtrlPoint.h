#ifndef CTRLPOINT_H
#define CTRLPOINT_H

#include "Point.h"

class CtrlPoint : public Point
{
private:
    bool canEdit = false;
public:
    CtrlPoint(double x, double y);
    void setCanEditToTrue();
    void setCanEditToFalse();
    bool getCanEdit();
    bool detectColision(int mouse_x, int mouse_y);
};

#endif