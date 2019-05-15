#ifndef FRAME_H
#define FRAME_H
#include "auxFunc.h"
#include "gl_canvas2d.h"

/**
    Frame.h
    Propósito: Gera o esquadro da bicicleta

    @author José Victor Viriato
    @version 0.1 2019
**/

class Frame
{
    /**
     *  class Frame
     *  @param coords_x, coords_y coordenadas do esquadro da bicicleta
     *  @param coords_seat coordenadas do banco
     * 
     * **/
private:
    double coords_x[4];
    double coords_y[4];
    double coords_seat[2];

public:
    Frame(double coords_x[4], double coords_y[4]);
    double getSeatY();
    double getSeatX();

    // renderiza o esquadro da bicicleta
    void render();
    ~Frame();
};

#endif
