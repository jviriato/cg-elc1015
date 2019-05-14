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



    
    // double a = (seat_coords[0] - knee_coords[0]) * (seat_coords[0] - knee_coords[0]);
    // double b = (seat_coords[1] - knee_coords[1]) * (seat_coords[1] - knee_coords[1]);
    // double c = 81;
    // do
    // {
    //     knee_x = pedal_x + 80 * cos(ang * M_PI / 180);
    //     knee_y = pedal_y + 80 * sin(ang * M_PI / 180);
    //     double a = (seat_coords[0] - knee_x) * (seat_coords[0] - knee_x);
    //     double b = (seat_coords[1] - knee_y) * (seat_coords[1] - knee_y);
    //     double c = sqrt(a + b);
    //     ang += 0.01;
    //     this->knee_coords[0] = knee_x;
    //     this->knee_coords[1] = knee_y;
    //     this->pedal_coords[0] = pedal_x;
    //     this->pedal_coords[1] = pedal_y;

    // } while (c > 80);

    // std::cout << std::endl;
    // std::cout << "seatx: " << seat_coords[0] << std::endl;
    // std::cout << "seaty: " << seat_coords[1] << std::endl;

    // std::cout << "pedalx: " << pedal_coords[0] << std::endl;
    // std::cout << "pedaly: " << pedal_coords[1] << std::endl;

    // // distância do pedal ao banco
    // double dist_pedal_seat = pythagoreanTheorem((seat_coords[0] - pedal_coords[0]),
    //                                             (seat_coords[1] - pedal_coords[1]));
    // std::cout << "dist_pedal_seat: " << dist_pedal_seat << " (apos aplicar pitagoras)" << std::endl;

    // // vetor do pedal ao banco
    // double vec_seat_to_pedal[2] = {(this->seat_coords[0] - this->pedal_coords[0]),
    //                                this->seat_coords[1] - this->pedal_coords[1]};

    // // vetor perpendicular ao do pedal e banco
    // double versor[2] = {1, 0};

    // // pega o ângulo pedal-banco através do cosseno
    // std::cout << "size: " << size << std::endl;
    // double cos_angle = findCos(size, dist_pedal_seat, size);
    // std::cout << "cos angle: " << cos_angle << std::endl;

    // double angle_triangle = acos(cos_angle);
    // std::cout << "angle_triangle: " << angle_triangle << std::endl;

    // // pega o ângulo vetor banco-pedal e vetor perpendicular através do cosseno
    // double cos_vect = (pedal_x - seat_coords[0]) * 1 + (pedal_y - seat_coords[1]) * 0;
    // double aux = sqrt((pedal_x - seat_coords[0]) * (pedal_x - seat_coords[0]) + (pedal_y - seat_coords[1]) * (pedal_y - seat_coords[1])) * sqrt(1*1 + 0*0);
    // cos_vect = cos_vect / aux;

    // double angle_vector = acos(cos_vect);
    // std::cout << "angle_vector: " << angle_vector << std::endl;

    // double inclinacao = angle_vector - angle_triangle;
    // std::cout << "inclinacao: " << inclinacao << std::endl;
    // std::tuple<double, double> new_knee_coords = translateMatrix(this->knee_coords[0], this->knee_coords[1], -this->pedal_coords[0], -this->pedal_coords[1]);
    // new_knee_coords = rotateMatrix(inclinacao, std::get<0>(new_knee_coords), std::get<1>(new_knee_coords));
    // new_knee_coords = translateMatrix(std::get<0>(new_knee_coords), std::get<1>(new_knee_coords), this->pedal_coords[0], this->pedal_coords[1]);
    // this->knee_coords[0] = std::get<0>(new_knee_coords);
    // this->knee_coords[1] = std::get<1>(new_knee_coords);
    // this->pedal_coords[0] = pedal_x;
    // this->pedal_coords[1] = pedal_y;
}

Leg::~Leg()
{
}