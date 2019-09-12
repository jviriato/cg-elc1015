#ifndef BUTTON_H
#define BUTTON_H
#include "Interface.h"
#include <string>

using namespace std;
/*  Classe com o propósito de gerar botões.

*/

class Button : public Controller
{
  public:
    Button(int x, int y, int w, int h, string l, double r, double g, double b);
    Button(int x, int y, int w, int h, string l);
    double getArea();
    bool detectCollision(int x, int y);
    double *getColor();
    void render();
    void buttonActions(int mouse_x, int mouse_y, int state);
    void drawCollisionBox();
    virtual ~Button();
    void reset();
};

#endif