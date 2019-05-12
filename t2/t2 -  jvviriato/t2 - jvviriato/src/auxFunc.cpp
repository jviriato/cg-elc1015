#include "auxFunc.h"
#include <string>
#include "gl_canvas2d.h"
using namespace std;

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

   color(0, 0, 0);
   text(mouse_x, mouse_y + 5, x_char.c_str());
   text(mouse_x + 35, mouse_y + 5, y_char.c_str());
   color(1, 0, 0);
   circleFill(mouse_x, mouse_y, 2, 50); //mouse
}

float __calcRGB(float x)
{
   float maxRGB = 255;
   return (x / maxRGB);
}

vector<float> RGBtoFloat(int r, int g, int b)
{
   vector<float> rgb;
   rgb.push_back(__calcRGB(r));
   rgb.push_back(__calcRGB(g));
   rgb.push_back(__calcRGB(b));
   return rgb;
}