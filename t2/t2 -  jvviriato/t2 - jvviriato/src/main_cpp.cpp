#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>

#include "gl_canvas2d.h"

// Includes do T2
#include "auxFunc.h"
#include "Person.h"
#include "Bicycle.h"

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

// variaveis globais

int mouse_x = 0;
int mouse_y = 0;
int mouse_state = 0;


//  Classe que pinta o fundo.
void buildBackground()
{
   vector<double> rgb = RGBtodouble(228, 233, 237); //cinza
   clear(rgb[0], rgb[1], rgb[2]);
   color(1, 0, 0);
}

// Função onde ocorre a construção dos objetos
void buildScreen()
{
   // w = new Wheel(WIDTH / 2.00, HEIGHT / 2.0, 40.00, 10);
   // p = new Pedal(WIDTH / 2.0 + 100, HEIGHT / 2.0);
   b = new Bicycle(WIDTH / 2.00, HEIGHT / 2.0);
   p = new Person(550, 428);
}

// Função onde ocorre a renderização dos objetos
void renderScreen()
{
   color(0, 0, 0);
   b->render();
   p->render();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
   renderScreen();
   coordsOfMouse(mouse_x, mouse_y);
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   if (key == 'd')
   {
      b->update();
   }
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
   initCanvas(WIDTH, HEIGHT, "T2 - Bike");
   buildScreen();
   runCanvas();
}
