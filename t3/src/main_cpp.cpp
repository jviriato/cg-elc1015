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
#include "Object3D.h"
#include "Scene.h"

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
Object3D *ob;
Scene *s1;
Scene *s2;
int mouse_x = 0;
int mouse_y = 0;
int mouse_button = -2;
int mouse_state = 0;

//  Classe que pinta o fundo.
void buildBackground()
{
   vector<double> rgb = {0,0,1};
   s1 = new Scene(rgb, Point(0,0), Point(WIDTH/2, HEIGHT));
   rgb = RGBtodouble(10, 11, 163); //cinza
   s2 = new Scene(rgb, Point(WIDTH/2, 0), Point(WIDTH, HEIGHT));
}

// Função onde ocorre a construção dos objetos
void buildScreen()
{
   b = new Bezier(CtrlPoint(WIDTH/4, HEIGHT/2),
                  CtrlPoint(WIDTH/4 + 10, HEIGHT/2 + 40),
                  CtrlPoint(WIDTH/4 + 20, HEIGHT/2 + 80),
                  CtrlPoint(WIDTH/4 + 30, HEIGHT/2 + 120));
   ob = new Object3D(*b, Point(197,355));
}
// Função onde ocorre a renderização dos objetos
void renderScreen()
{
   color(0,0.1, 0);
   s1->draw();
   color(0.7,0.7,0.7);
   s2->draw();
   b->render(mouse_x, mouse_y, mouse_state);
   ob->render(*b);
   color(1,0,0);
   circleFill(197,355, 5, 10);
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
   mouse_button = button;
   mouse_state = state;
   b->checkForCollisions(mouse_x, mouse_y, button);
}

int main(void)
{
   std::srand(std::time(nullptr));
   initCanvas(WIDTH, HEIGHT, "T3 - 2D -> 3D");
   buildScreen();
   runCanvas();
}
