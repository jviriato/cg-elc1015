/**
    interface.h
    Propósito: Gerar componentes para o canvas2d.

    @author jvviriato
**/


#ifndef __INTERFACE_H__
#define __INTERFACE_H__


#include "gl_canvas2d.h"
#include "Interface.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

/*  Classe abstrata para gerar componentes
    
    @param x: Representa o eixo x no axis.
    @param y: Representa o eixo y no axis.
    @param r, g, b: As cores do componente.
    @param width, height: Determinam o tamanho do componente.
    @param label: O texto que acompanhará o componente.
    @param hover: Aplicar transformações no componente caso o mouse esteja em 
    cima do botão.

*/
class Controller {
    public:
        void setColor(float red, float green, float blue);
        void setPosition(int pos_x, int pos_y);
        void setLabel(string l);
        void setSize(float w, float h);
        bool detectCollision(int x, int y);
        virtual float getArea() = 0;
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        float* getColor();
        char* getLabel();
        bool isInside  = false;
        bool isPressed = false;
        // Controller();
        ~Controller();
        float r, g, b;
    private:
        int x, y;     
        bool hover;
        string label;
    
    protected:
        int width, height;

};

#endif
