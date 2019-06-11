#include "Scene.h"
#include "Point.h"
#include "gl_canvas2d.h"
Scene::Scene(std::vector<double> rgb, Point i, Point e)
{
    init = i;
    end = e;
    rgb = rgb;
    center = Point((init.x() + end.x())/2, (init.y() + end.y())/2);
}

void Scene::draw()
{
    rectFill(init.x(), init.y(), end.x(), end.y());
    color(1,0,0);
    circleFill(center.x(), center.y(), 5, 10);
}

Point Scene::getMiddleOfScene()
{

}

Scene::~Scene()
{
}


