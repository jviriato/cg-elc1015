#include "Piece.h"
#include "Wheel.h"

/*
    Wheel.cpp
    Propósito: Gera Rodas

    @author José Victor Viriato
*/

// Macros para converter ângulos
#define degreesToRadians(angleDegrees) ((angleDegrees)*M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians)*180.0 / M_PI)

Wheel::Wheel(float x, float y, int radius, int rims)
{
    this->x = x;
    this->y = y;
    this->rims = rims;
    this->radius = radius;
    this->createRims();
}

int Wheel::getX()
{
    return x;
}

int Wheel::getY()
{
    return y;
}

int Wheel::getRims()
{
    return rims;
}

int Wheel::getRadius()
{
    return radius;
}

float Wheel::calcAngle(int num)
{
    /*
        Função auxiliar para conseguir o ângulo de um número
     */
    return (360.0 / num);
}

void Wheel::drawTire()
{
    /*
        Função que desenha o pneu da bicicleta
    */
    const int inner_border = 5;
    // Parte externa da roda
    color(0, 0, 0);
    circleFill(x, y, radius, 50);
    // Parte interna da roda
    color(1, 1, 1);
    circleFill(x, y, radius - inner_border, 50);
}

void Wheel::createRims()
{
    /*
        Função que cria os aros, utilizando funções matemáticas para posicioná-los corretamente
    */
    const int inner_border = 5;
    color(1, 0, 0);
    int rims_y_end = y + radius - inner_border;
    int rims_x_end = x;
    int angle = 0;
    int plus_angle = this->calcAngle(rims);

    for (int i = 0; i < this->rims; i++)
    {
        rims_x_end = x + (radius - inner_border) * cos(angle * M_PI / 180.0);
        rims_y_end = y + (radius - inner_border) * sin(angle * M_PI / 180.0);
        this->position_rims.push_back(std::make_tuple(rims_x_end, rims_y_end));
        angle += plus_angle;
    }
}

void Wheel::drawRims()
{
    /*
        Função que desenha os aros
    */
    color(0, 0, 1);
    circleFill(this->x, this->y, 5, 50);

    for (int i = 0; i < rims; i++)
    {
        float rims_x_end = std::get<0>(this->position_rims[i]);
        float rims_y_end = std::get<1>(this->position_rims[i]);
        line(this->x, this->y, rims_x_end, rims_y_end);
    }
}

void Wheel::updateRims()
{
    /*
        Função atualiza os aros. É chamada na função keyboard do canvas, para mexer a bicicleta.
        É feito um translado até a origem da roda, e então, utiliza a matriz de rotação para girar
        os aros. Após isso, translada novamente para o ponto correto.
    */

    for (int i = 0; i < this->position_rims.size(); i++)
    {
        float rims_x_end = std::get<0>(this->position_rims[i]);
        float rims_y_end = std::get<1>(this->position_rims[i]);
        std::cout << "aro "<< i << ": " << rims_x_end << ", " << rims_y_end << std::endl;
        std::tuple<float, float> coords = std::make_tuple(rims_x_end, rims_y_end);
        coords = this->translateMatrix(std::get<0>(coords), std::get<1>(coords), -this->x, -this->y);
        coords = this->rotateMatrix(30, std::get<0>(coords), std::get<1>(coords));
        coords = this->translateMatrix(std::get<0>(coords), std::get<1>(coords), this->x, this->y);
        this->position_rims[i] = coords;
    }
    std::cout << std::endl;
}

std::tuple<float, float> Wheel::translateMatrix(float x, float y, float offset_x, float offset_y)
{
    /*
        Aplica a matriz de translação.
    */
    const float translate_matrix[3][3] = {
        {1, 0, offset_x},
        {0, 1, offset_y},
        {0, 0, 1}};
    
        float new_x = (x * translate_matrix[0][0]) + (y * translate_matrix[0][1]) + offset_x;
        float new_y = (x * translate_matrix[1][0]) + (y * translate_matrix[1][1]) + offset_y;
        std::tuple<float, float> coords;
        coords = std::make_tuple(new_x, new_y);
        return coords;
}

std::tuple<float, float> Wheel::rotateMatrix(float angle, int x, int y)
{
    /* 
        Aplica a matriz de rotação num ângulo θ
        ____________________
        | cosθ | -sinθ |  0  |
        | sinθ |  cosθ |  0  |
        |  0   |   0   |  1  |
        ----------------------
    */
    // Recebe o ângulo em graus, transforma em radianos
    float radians_angle = degreesToRadians(angle);

    const float rotation_matrix[3][3] = {
        {cos(radians_angle), -sin(radians_angle), 0},
        {sin(radians_angle), cos(radians_angle), 0},
        {0, 0, 1}};

    // Calcula os novos pontos
    float new_x = ((x * rotation_matrix[0][0]) + (y * rotation_matrix[0][1]));
    float new_y = ((x * rotation_matrix[1][0]) + (y * rotation_matrix[1][1]));

    std::tuple<float, float> coords;
    coords = std::make_tuple(new_x, new_y);
    return coords;
}

void Wheel::render()
{
    this->drawTire();
    this->drawRims();
}
