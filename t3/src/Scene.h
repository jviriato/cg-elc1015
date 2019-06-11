#ifndef SCENE_H
#define SCENE_H
#include "Point.h"
#include "auxFunc.h"
#include "gl_canvas2d.h"
#include <vector>
class Scene
{
private:
    std::vector<double> rgb;
    Point init;
    Point end;
    Point center;

public:
    Scene(std::vector<double> rgb, Point i, Point e);
    Point getMiddleOfScene();
    void draw();
    ~Scene();
};

#endif
