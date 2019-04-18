#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "Interface.h"
#include <string>

using namespace std;
/*  Classe com o propósito de gerar botões.

*/

class Checkbox : public Controller
{
  public:
    Checkbox(int x, int y, string l);
    bool state;

    void drawInactive();
    void drawActive();
    float getArea();
    bool detectCollision(int mouse_x, int mouse_y);
    void render();
    void checkboxActions(int mx, int my, int state);
};

#endif