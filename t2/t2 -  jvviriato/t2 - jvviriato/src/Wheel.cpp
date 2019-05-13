#include "Piece.h"
#include "Wheel.h"

/*
    Wheel.cpp
    Propósito: Gera Rodas

    @author José Victor Viriato
*/

// Macros para converter ângulos

Wheel::Wheel(double x, double y, double radius, int rims)
{
    this->x = x;
    this->y = y;
    this->rims = rims;
    this->radius = radius;
    this->createRims();
}

Wheel::Wheel(double x, double y)
{
    this->x = x;
    this->y = y;
    this->rims = 8;
    this->radius = 40;
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

double Wheel::calcAngle(int num)
{
    /*
        Função auxiliar para conseguir o ângulo de um número
     */
    return (360.0 / num);
}

void Wheel::createRims()
{
    /*
        Função que cria os aros
    */
    const int inner_border = 5;
    color(1, 0, 0);
    double rims_y_end = y + radius - inner_border;
    double rims_x_end = x;
    double angle = 0;
    double plus_angle = this->calcAngle(rims);

    for (int i = 0; i < this->rims; i++)
    {
        rims_x_end = x + (radius - inner_border) * cos(degreesToRadians(angle));
        rims_y_end = y + (radius - inner_border) * sin(degreesToRadians(angle));
        this->position_rims.push_back(std::make_tuple(rims_x_end, rims_y_end));
        angle += plus_angle;
    }
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

void Wheel::drawRims()
{
    /*
        Função que desenha os aros
    */
    color(0, 0, 0);
    circleFill(this->x, this->y, 5, 50);

    for (int i = 0; i < rims; i++)
    {
        double rims_x_end = std::get<0>(this->position_rims[i]);
        double rims_y_end = std::get<1>(this->position_rims[i]);
        line(this->x, this->y, rims_x_end, rims_y_end);
    }
}

void Wheel::update()
{
    /*
        Função atualiza os aros. É chamada na função keyboard do canvas, para mexer a bicicleta.
        É feito um translado até a origem da roda, e então, utiliza a matriz de rotação para girar
        os aros. Após isso, translada novamente para o ponto correto.
    */

    for (int i = 0; i < rims; i++)
    {
        double rims_x_end = std::get<0>(this->position_rims[i]);
        double rims_y_end = std::get<1>(this->position_rims[i]);
        std::tuple<double, double> coords = std::make_tuple(rims_x_end, rims_y_end);
        // std::cout << std::endl;
        // std::cout << "x: " << std::get<0>(coords) << " y: " << std::get<1>(coords) << " (Antes de transladar)" << std::endl;
        coords = this->translateMatrix(std::get<0>(coords), std::get<1>(coords), -this->x, -this->y);
        coords = this->rotateMatrix(-2, std::get<0>(coords), std::get<1>(coords));
        coords = this->translateMatrix(std::get<0>(coords), std::get<1>(coords), this->x, this->y);
        this->position_rims[i] = coords;
    }
}

std::tuple<double, double> Wheel::translateMatrix(double x, double y, double offset_x, double offset_y)
{
    /*
        Aplica a matriz de translação.
    */
    const double translate_matrix[3][3] = {
        {1, 0, offset_x},
        {0, 1, offset_y},
        {0, 0, 1}};
    double new_x = (x * translate_matrix[0][0]) + (y * translate_matrix[0][1]) + offset_x;
    double new_y = (x * translate_matrix[1][0]) + (y * translate_matrix[1][1]) + offset_y;
    std::tuple<double, double> coords;
    coords = std::make_tuple(new_x, new_y);
    return coords;
}

std::tuple<double, double> Wheel::rotateMatrix(double angle, double x, double y)
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
    double radians_angle = degreesToRadians(angle);

    const double rotation_matrix[3][3] = {
        {cos(radians_angle), -sin(radians_angle), 0},
        {sin(radians_angle), cos(radians_angle), 0},
        {0, 0, 1}};

    // Calcula os novos pontos
    double new_x = ((x * rotation_matrix[0][0]) + (y * rotation_matrix[0][1]));
    double new_y = ((x * rotation_matrix[1][0]) + (y * rotation_matrix[1][1]));

    std::tuple<double, double> coords;
    coords = std::make_tuple(new_x, new_y);
    return coords;
}

void Wheel::render()
{
    this->drawTire();
    this->drawRims();
}

Wheel::~Wheel()
{
}