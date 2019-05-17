#include "Leg.h"
#include "auxFunc.h"
#include "gl_canvas2d.h"
#include <iostream>
#include <cmath>

Leg::Leg(double size)
{
    this->size = size;
}

void Leg::setPedal(double x, double y)
{
    this->pedal_coords[0] = x;
    this->pedal_coords[1] = y;
}

void Leg::setSeat(double x, double y)
{
    this->seat_coords[0] = x;
    this->seat_coords[1] = y;
}

void Leg::setKnee()
{
    // gera um vetor que vai da bacia ate metade do caminho
    double x = (pedal_coords[0] - seat_coords[0]) / 2;
    double y = (pedal_coords[1] - seat_coords[1]) / 2;

    // pega os valores que correspondem a metade do caminho entre a bacia e o pe
    double metade_x = seat_coords[0] + x;
    double metade_y = seat_coords[1] + y;

    // pega a norma desse vetor
    double norma_metade = pythagoreanTheorem(x, y);

    // calcula pitagoras entre a norma e o tamanho das pernas
    double h = sqrt((50 * 50) - (norma_metade * norma_metade));

    // calculo produto vetorial para pegar o vetor perpendicular
    // multiplica o vetor gerado acima por [0,0,1]
    // o valor do z do vetor acima é 0
    double vet_x = (-1) * y;
    double vet_y = x;

    double norma_vet = sqrt((vet_x * vet_x) + (vet_y * vet_y));
    vet_x /= norma_vet;
    vet_y /= norma_vet;

    vet_x = (vet_x * h) + metade_x;
    vet_y = (vet_y * h) + metade_y;

    this->knee_coords[0] = vet_x;
    this->knee_coords[1] = vet_y;
}

void Leg::render()
{
    color(0, 0, 0);
    line(seat_coords[0], seat_coords[1], knee_coords[0], knee_coords[1]);
    line(knee_coords[0], knee_coords[1], pedal_coords[0], pedal_coords[1]);
    color(1, 0, 0);
    circleFill(knee_coords[0], knee_coords[1], 3, 10);
}

void Leg::update(double pedal_x, double pedal_y)
{
    // gera um vetor que vai da bacia ate metade do caminho
    double x = (pedal_coords[0] - seat_coords[0]) / 2;
    double y = (pedal_coords[1] - seat_coords[1]) / 2;

    // pega os valores que correspondem a metade do caminho entre a bacia e o pe
    double metade_x = seat_coords[0] + x;
    double metade_y = seat_coords[1] + y;

    // pega a norma desse vetor
    double norma_metade = pythagoreanTheorem(x, y);

    // calcula pitagoras entre a norma e o tamanho das pernas
    double h = sqrt((50 * 50) - (norma_metade * norma_metade));

    // calculo produto vetorial para pegar o vetor perpendicular
    // multiplica o vetor gerado acima por [0,0,1]
    // o valor do z do vetor acima é 0
    double vet_x = (-1) * y;
    double vet_y = x;

    double norma_vet = sqrt((vet_x * vet_x) + (vet_y * vet_y));
    vet_x /= norma_vet;
    vet_y /= norma_vet;

    vet_x = (vet_x * h) + metade_x;
    vet_y = (vet_y * h) + metade_y;


    this->knee_coords[0] = vet_x;
    this->knee_coords[1] = vet_y;
    this->pedal_coords[0] = pedal_x;
    this->pedal_coords[1] = pedal_y;

}

Leg::~Leg()
{
}
