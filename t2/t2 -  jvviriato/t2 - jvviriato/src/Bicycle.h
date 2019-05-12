#ifndef PEDAL_H
#define PEDAL_H
#include "Wheel.h"
#include "Pedal.h"

class Bicycle
{
private:
    std::vector<Wheel> Wheels;
    Pedal pedal;

public:
    Bicycle(/* args */);
    ~Bicycle();
};

Bicycle::Bicycle(/* args */)
{
}

Bicycle::~Bicycle()
{
}


#endif
