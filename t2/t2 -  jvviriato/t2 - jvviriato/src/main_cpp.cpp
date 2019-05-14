#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "gl_canvas2d.h"

// Includes do T2
#include "auxFunc.h"
#include "Person.h"
#include "Bicycle.h"
#include "Tree.h"
#include "Bush.h"


// M_PI é definido pelo GCC mas não pelo MinGW
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")
//#pragma comment(lib, "glut32.lib")

#define WIDTH 1024
#define HEIGHT 600

// Classes globais que utilizarei neste trabalho
Bicycle *b;
Person *p;
Tree *t;
Bush *bush;
// variaveis globais

int mouse_x = 0;
int mouse_y = 0;
int mouse_state = 0;

//  Classe que pinta o fundo.
void buildBackground()
{
   vector<double> rgb = RGBtodouble(86, 111, 163); //cinza
   clear(rgb[0], rgb[1], rgb[2]);
   rgb = RGBtodouble(111, 163, 86);
   color(rgb[0], rgb[1], rgb[2]);
   rectFill(0, 200, WIDTH, 0);

}

// Função onde ocorre a construção dos objetos
void buildScreen()
{
   bush = new Bush();
   t = new Tree();
   b = new Bicycle(206, 138);
   p = new Person(b->frame->getSeatX() - 5, b->frame->getSeatY() + 80);

   p->l1->setPedal(b->pedal->getPedalRightX(), b->pedal->getPedalRightY());
   p->l1->setSeat(b->frame->getSeatX(), b->frame->getSeatY());
   p->l1->setKnee();

   p->l2->setPedal(b->pedal->getPedalLeftX(), b->pedal->getPedalLeftY());
   p->l2->setSeat(b->frame->getSeatX(), b->frame->getSeatY());
   p->l2->setKnee();
}

// Função onde ocorre a renderização dos objetos
void renderScreen()
{
   color(0, 0, 0);
   t->render();
   b->render();
   p->render();
   bush->render();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
   buildBackground();
   renderScreen();
   coordsOfMouse(mouse_x, mouse_y);
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   if (key == 'w')
   {
      b->update();
      color(0, 1, 0);
      p->l1->update(b->pedal->getPedalRightX(), b->pedal->getPedalRightY());
      p->l2->update(b->pedal->getPedalLeftX(), b->pedal->getPedalLeftY());
      t->update();
   }
   bush->update();
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   int click = 0, release_click = 1;
   y = reverseAxis(y, HEIGHT);
   mouse_x = x;
   mouse_y = y;
   mouse_state = state;
}

int main(void)
{
   std::srand(std::time(nullptr));
   initCanvas(WIDTH, HEIGHT, "T2 - Bike");
   buildScreen();
   runCanvas();
}
