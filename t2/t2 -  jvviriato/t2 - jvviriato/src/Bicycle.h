#ifndef BICYCLE_H
#define BICYCLE_H
#include "auxFunc.h"
#include "Wheel.h"
#include "Pedal.h"
#include "Frame.h"
class Bicycle
{
private:
    double x;
    double y;
    std::vector<Wheel> wheels;
    Pedal *pedal;
    Frame *frame;
public:
    Bicycle(double x, double y);
    void createBicycle();
    void render();
    void update();
    ~Bicycle();
};

#endif
