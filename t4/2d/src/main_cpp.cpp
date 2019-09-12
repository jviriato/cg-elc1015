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

// Includes do T3
#include "auxFunc.h"
#include "Point.h"
#include "CtrlPoint.h"
#include "Bezier.h"
#include "Spline.h"
#include "Object3D.h"
#include "Scene.h"
#include "Interface.h"
#include "Button.h"

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

// variaveis globais
Bezier *b;
Spline *s;
Object3D *ob;
std::vector<Button *> buttons;
Scene *s1;
Scene *s2;
int mouse_x = 0;
int mouse_y = 0;
int mouse_button = -2;
int mouse_state = 0;

//  Classe que pinta o fundo.
void buildBackground()
{
   vector<double> rgb = {0, 0, 1};
   s1 = new Scene(rgb, Point(0, 0), Point(WIDTH / 2, HEIGHT));
   rgb = RGBtodouble(10, 11, 163);
   s2 = new Scene(rgb, Point(WIDTH / 2, 0), Point(WIDTH, HEIGHT));
}

// Função que cria os botões
void buildButtons()
{
   // int width = 100;
   // int height = 50;
   // int offset = 2;
   // int start_position_x = 0;
   // int start_position_y = 0;
   // vector<double> rgb = RGBtodouble(107, 185, 240);
   // Button *b;
   // b = new Button(start_position_x, start_position_y, width - 20, height, "+Faces", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);
   // b = new Button(start_position_x + width - 20 + offset, start_position_y, width - 20, height, "-Faces", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);

   // rgb = RGBtodouble(46, 204, 113);
   // b = new Button(start_position_x + (width * 2 - 20) + offset, start_position_y, width + 30, height, "+Pts Objeto", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);
   // b = new Button(start_position_x + width * 3 + offset + 15, start_position_y, width + 30, height, "-Pts Objeto", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);

   // b = new Button(0 + offset, HEIGHT - height, width, height, "Aproximar", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);
   // rgb = RGBtodouble(46, 204, 0);
   // b = new Button(offset + width, HEIGHT - height, width, height, "Afastar", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);

   // rgb = RGBtodouble(129, 207, 224);
   // b = new Button(start_position_x + (width * 2) + (offset * 2), start_position_y, width, height, "+ Pts de Controle", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);
   // b = new Button(start_position_x + (width * 2) + (offset * 2), start_position_y, width, height, "- Pts de Controle", rgb[0], rgb[1], rgb[2]);
   // buttons.push_back(b);
}

void trataButtons(Button *button, int mouse_x, int mouse_y, int state)
{

   // button->buttonActions(mouse_x, mouse_y, state);
   // if (strcmp(button->getLabel(), "+Faces") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       double lados = ob->getLados();
   //       ob->setLados(lados + 10);
   //       button->reset();
   //    }
   // }
   // if (strcmp(button->getLabel(), "-Faces") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       double lados = ob->getLados();
   //       std::cout << ob->getLados();
   //       if (lados - 5 > 0)
   //          ob->setLados(lados - 5);
   //       button->reset();
   //    }
   // }
   // if (strcmp(button->getLabel(), "+Pts Objeto") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       double value = b->getNumberPoints();
   //       b->setNumberPoints(value - 0.01);
   //       button->reset();
   //    }
   // }
   // if (strcmp(button->getLabel(), "-Pts Objeto") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       double value = b->getNumberPoints();
   //       if (value < .85)
   //          b->setNumberPoints(value + 0.05);
   //       std::cout << b->getNumberPoints() << " ";
   //       button->reset();
   //    }
   // }
   // if (strcmp(button->getLabel(), "+ Pts de Controle") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       button->reset();
   //    }
   // }
   // if (strcmp(button->getLabel(), "- Pts de Controle") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       button->reset();
   //    }
   // }
   // if (strcmp(button->getLabel(), "Aproximar") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       double z = ob->getZ();
   //       ob->setZ(z - 10);
   //       button->reset();
   //    }
   // }
   // if (strcmp(button->getLabel(), "Afastar") == 0)
   // {
   //    if (button->isPressed)
   //    {
   //       double z = ob->getZ();
   //       ob->setZ(z + 10);
   //       button->reset();
   //    }
   // }
}

// Função onde ocorre a construção dos objetos
void buildScreen()
{
   Point middle = s1->getMiddleOfScene();
   std::vector<CtrlPoint> ctrlpoints{
      CtrlPoint(192, 217),
      CtrlPoint(233, 429),
      CtrlPoint(446, 394),
      CtrlPoint(460, 186)};
   b = new Bezier(ctrlpoints);
   s = new Spline(ctrlpoints);
   ob = new Object3D(*b, middle);
   buildButtons();
}
// Função onde ocorre a renderização dos objetos
void renderScreen()
{

   color(1, 1, 1);
   // s1->draw();
   color(0.7, 0.7, 0.7);
   s2->draw();
   // b->render(mouse_x, mouse_y, mouse_state);
   s->render(mouse_x, mouse_y, mouse_state);
   ob->render(*b);
   color(1, 0, 0);
}
//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
   buildBackground();
   renderScreen();
   coordsOfMouse(mouse_x, mouse_y);
   for (auto &button : buttons)
   {
      button->render();
   }
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{

   for (Button *button : buttons)
   {
      trataButtons(button, mouse_x, mouse_y, state);
   }

   int click = 0, release_click = 1;
   y = reverseAxis(y, HEIGHT);
   mouse_x = x;
   mouse_y = y;
   mouse_button = button;
   mouse_state = state;
   // b->checkForCollisions(mouse_x, mouse_y, button);
   s->checkForCollisions(mouse_x, mouse_y, button);
}

int main(void)
{
   std::srand(std::time(nullptr));
   initCanvas(WIDTH, HEIGHT, "T3 - 2D -> 3D");
   buildBackground();
   buildScreen();
   runCanvas();
}
