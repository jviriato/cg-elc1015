#ifndef CTRLPOINT_H
#define CTRLPOINT_H

#include "Point.h"

// É uma classe filha de Ponto, que contém checagens para 
// colisões.

class CtrlPoint : public Point
{
private:
    bool canEdit = false;
public:
    CtrlPoint();
    CtrlPoint(double x = 0.0, double y = 0.0, double z = 0.0);
    //Getters e Setters
    void setCanEditToTrue();
    void setCanEditToFalse();
    bool getCanEdit();
    // Detecção de colisão com o mouse
    bool detectColision(int mouse_x, int mouse_y);
};

#endif