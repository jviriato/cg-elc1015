#ifndef __AUXFUNC_H__
#define __AUXFUNC_H__
#include <vector>

using namespace std;
/*
Funções auxiliares para facilitar o desenvolvimento.
*/
int reverseAxis(int axis, int height_of_canvas);
float __calcRGB(float x);
vector<float> RGBtoFloat(int r, int g, int b);
void coordsOfMouse(int mouse_x, int mouse_y);
#endif