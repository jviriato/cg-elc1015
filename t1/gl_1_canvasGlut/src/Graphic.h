#ifndef GRAPHIC_H
#define GRAPHIC_H
#include "Interface.h"
#include <string>

using namespace std;
/*  Classe com o propósito de gerar Gráficos.

*/

class Graphic : public Controller
{
  public:
    Graphic(int x, int y, int height, string label);
    void  render();
    float getArea();
    void setSize(int height);
    void createRectangle();
    void createTitleBar();
    void createMiddleLine();
    void createBackgroundRectangle();
    int size_canvas;
};

#endif