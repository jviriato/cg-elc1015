#ifndef __AUXFUNC_H__
#define __AUXFUNC_H__
#include <vector>
#include <tuple>

// macros que convertem graus e radianos para utilização mais eficiente
#define degreesToRadians(angleDegrees) ((angleDegrees)*M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians)*180.0 / M_PI)

using namespace std;
/*
Funções auxiliares para facilitar o desenvolvimento.
*/

// Inverte o eixo de algo
int reverseAxis(int axis, int height_of_canvas);

// Teorema de pitágoras
double pythagoreanTheorem(double a, double b);

// Função auxilidar da RGBtodouble
double __calcRGB(double x);
// Calcula o double dado três pontos. Utilizado para a função color
vector<double> RGBtodouble(int r, int g, int b);

// Mostra as coordenadas do mouse na tela
void coordsOfMouse(int mouse_x, int mouse_y);

// Funções matriciais
std::tuple<double, double> translateMatrix(double x, double y, double offset_x, double offset_y);
std::tuple<double, double> rotateMatrix(double angle, double x, double y);

// Funções de curvas
void bezier(std::vector<std::tuple<double, double>> coords);

double findCos(double a, double b, double c);
double angleBetweenVectors(double x1, double y1, double x2, double y2);


#endif
