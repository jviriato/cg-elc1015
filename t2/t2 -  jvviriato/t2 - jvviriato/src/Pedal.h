#define PEDAL_H
#include "Piece.h"

/**
    Pedal.h
    Propósito: Gerar Pedais

    @author José Victor Viriato
    @version 0.1 2019
*/

class Pedal : public Piece
{
private:
    float x;
    float y;

    float x_pedal1;
    float y_pedal1;
    float x_pedal2;
    float y_pedal2;

public:
    Pedal(float x, float y);
    void createPedal();
    void update();
    void render();
    std::tuple<float, float> translateMatrix(float x, float y, float offset_x, float offset_y);
    std::tuple<float, float> rotateMatrix(float angle, int x, int y);
    ~Pedal();
};
