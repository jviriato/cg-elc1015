#ifndef BICYCLE_H
#define BICYCLE_H
#include "auxFunc.h"
#include "Wheel.h"
#include "Pedal.h"
#include "Frame.h"

/**
    Bicycle.h
    Propósito: Gera e renderiza uma bicicleta

    @author José Victor Viriato
    @version 0.1 2019
**/

class Bicycle
{
    /**
     *  class Bicycle
     *  @param x, y coordenadas do centro da bicicleta
     *  @param pedal Pedal da bicicleta
     *  @param frame Esquadro da bicicleta
     *  @param wheels Vetor com duas rodas da bicicleta
     *  @param x_wheel_* A coordenada x das rodas
     *  @param x_pedal A coordenada x do pedal
     * **/
private:
    double x;
    double y;
    double x_wheel_left;
    double x_wheel_right;
    double x_pedal;
    std::vector<Wheel> wheels;
public:
    Pedal *pedal;
    Frame *frame;
    Bicycle(double x, double y);
    // renderiza a bicicleta
    void render();
    // atualiza as propriedades da bicicleta
    void update();

    double getY();
    double getX();
    ~Bicycle();
};

#endif
