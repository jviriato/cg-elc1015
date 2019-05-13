#ifndef __AUXFUNC_H__
#define __AUXFUNC_H__
#include <vector>
#include <tuple>

#define degreesToRadians(angleDegrees) ((angleDegrees)*M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians)*180.0 / M_PI)

using namespace std;
/*
Funções auxiliares para facilitar o desenvolvimento.
*/
int reverseAxis(int axis, int height_of_canvas);
double __calcRGB(double x);
vector<double> RGBtodouble(int r, int g, int b);
void coordsOfMouse(int mouse_x, int mouse_y);
std::tuple<double, double> translateMatrix(double x, double y, double offset_x, double offset_y);
std::tuple<double, double> rotateMatrix(double angle, double x, double y);
void bezier(std::vector<std::tuple<double, double> > coords);

#endif