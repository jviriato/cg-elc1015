#ifndef BUSH_H
#define BUSH_H
#include "gl_canvas2d.h"
#include "auxFunc.h"
#include <vector>
#include <tuple>
class Bush
{
private:
    double x;
    double y;
    double size;
    double speed;
    int z_index;

public:
    Bush(double size);
    void update();
    void render();
    ~Bush();
};

#endif // BUSH_H
