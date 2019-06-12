#ifndef SLIDER_H
#define SLIDER_H
#include "CtrlPoint.h"
#include "Point.h"
#include "gl_canvas2d.h"
class Slider
{
private:
    Point init;
    Point end;
    CtrlPoint p;

public:
    Slider(Point i, Point e);
    void draw();
    void build(int mouse_x, int mouse_y, int button);
    void render(int mouse_x, int mouse_y, int button);
    ~Slider();
};

#endif