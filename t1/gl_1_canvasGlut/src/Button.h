#ifndef BUTTON_H
#define BUTTON_H
#include "Interface.h"
#include <string>

using namespace std;
/*  Classe com o propósito de gerar botões.

*/

class Button : public Controller {
    public:
        Button(int x, int y, int w, int h, string l, float r, float g, float b);
        Button(int x, int y, int w, int h, string l);
        float getArea();
        bool detectCollision(int x, int y);
        float *getColor();
        void render();
        virtual ~Button();
};

#endif