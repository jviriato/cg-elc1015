#include "auxFunc.h"
#include <string>
#include <cmath>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

// M_PI é definido pelo GCC mas não pelo MinGW
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* Função para inverter o eixo do canvas
   @param axis: o eixo a ser invertido
   @param height_of_canvas: o tamanho da tela
*/
int reverseAxis(int axis, int height_of_canvas)
{
    return (height_of_canvas - axis);
}

void coordsOfMouse(int mouse_x, int mouse_y)
{
    string x_char = to_string(mouse_x);
    x_char.c_str();
    string y_char = to_string(mouse_y);
    y_char.c_str();

    // color(0, 0, 0);
    // text(mouse_x, mouse_y + 5, x_char.c_str());
    // text(mouse_x + 35, mouse_y + 5, y_char.c_str());
    // color(1, 0, 0);
    // circleFill(mouse_x, mouse_y, 2, 50); //mouse
}

double __calcRGB(double x)
{
    double maxRGB = 255;
    return (x / maxRGB);
}

vector<double> RGBtodouble(int r, int g, int b)
{
    vector<double> rgb;
    rgb.push_back(__calcRGB(r));
    rgb.push_back(__calcRGB(g));
    rgb.push_back(__calcRGB(b));
    return rgb;
}

std::tuple<double, double> translateMatrix(double x, double y, double offset_x, double offset_y)
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

std::tuple<double, double> rotateMatrix(double angle, double x, double y)
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

// Bezier deve receber 4 pts de controle
void bezier(std::vector<std::tuple<double, double>> coords)
{
    double x1 = std::get<0>(coords[0]);
    double x2 = std::get<0>(coords[1]);
    double x3 = std::get<0>(coords[2]);
    double x4 = std::get<0>(coords[3]);
    double y1 = std::get<1>(coords[0]);
    double y2 = std::get<1>(coords[1]);
    double y3 = std::get<1>(coords[2]);
    double y4 = std::get<1>(coords[3]);

    double t = 0.0;
    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double blending_functions[4] = {
            (pow((1 - t), 3)),
            (3 * t * (pow((1 - t), 2))),
            (3 * t * t * (1 - t)),
            (t * t * t)};
        double xt = blending_functions[0] * x1 +
                    blending_functions[1] * x2 +
                    blending_functions[2] * x3 +
                    blending_functions[3] * x4;

        double yt = blending_functions[0] * y1 +
                    blending_functions[1] * y2 +
                    blending_functions[2] * y3 +
                    blending_functions[3] * y4;
        // point(xt, yt);
    }

    // Para mostrar os pontos de controle
    // color(0, 0, 1);
    // for (auto i = 0; i < 4; i++)
    // {
    //     circleFill(std::get<0>(coords[i]), std::get<1>(coords[i]), 5, 50);
    // }
}

double pythagoreanTheorem(double a, double b)
{
    return sqrt(a * a + b * b);
}

double findCos(double a, double b, double c)
{
    std::cout << "findcos" << std::endl;
    double cima = -1 * ((a * a) + (b * b) - (c * c));
    double baixo = (-2 * a * b);
    std::cout << "cima: " << cima << " baixo: " << baixo << std::endl;
    double divisao = cima / baixo;
    std::cout << "divisao: " << divisao << std::endl;
    return divisao;
}

// retorna um cosseno
double angleBetweenVectors(double x1, double y1, double x2, double y2)
{
    std::cout << "findcos" << std::endl;

    double cima = (x1 * x1) + (y1 * y2);
    double baixo = sqrt((x1 * x1) + (y1 * y1)) * sqrt((x2 * x2) + (y2 * y2));
    std::cout << "cima: " << cima << " baixo: " << baixo << std::endl;
    double divisao = cima / baixo;
    std::cout << "divisao: " << divisao << std::endl;
    return divisao;
}
