#include "Slider.h"
#include "CtrlPoint.h"
Slider::Slider(Point i, Point e)
{
    init = i;
    end = e;
    p = CtrlPoint(i.x(), i.y());
}

void Slider::draw()
{
    color(0.8,0.8,0.8);
    rectFill(init.x(), init.y(), end.x(), end.y());
    
    if(p.getCanEdit()){
        color(1,0,0);
    }else{
        color(0,1,0);
    }
    circleFill(p.x(), p.y()+4, 8, 10);
}

void Slider::build(int mouse_x, int mouse_y, int button)
{
    if(p.detectColision(mouse_x, mouse_y) && button == 0 && !p.getCanEdit()){
        p.setCanEditToTrue();
    }

    if(p.getCanEdit())
    {
        p.setX(mouse_x);
    }

}

void Slider::render(int mouse_x, int mouse_y, int button)
{
    build(mouse_x, mouse_y, button);
    draw();
}

Slider::~Slider()
{
}