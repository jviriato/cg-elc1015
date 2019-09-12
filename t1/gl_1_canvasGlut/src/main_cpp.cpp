#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.
#include <math.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "dct.h"
#include "Button.h"
#include "Checkbox.h"
#include "auxFunc.h"
#include "Graphic.h"
#include "gl_canvas2d.h"
using namespace std;

//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")
//#pragma comment(lib, "glut32.lib")

#define WIDTH 1024
#define HEIGHT 600

//variaveis globais
vector<Button *> buttons;
vector<Checkbox *> checkboxes;
vector<Graphic *> graphics;
vector<Graphic *> baseGraphics;
int opcao = 50;
float global = 0;

int mouse_x = 0;
int mouse_y = 0;
int mouse_state = 0;

bool f_load = false;

vector<int> amostras_d;
vector<double> dct;
vector<double> idct;
vector<double> diff;

void buildBackground()
{
   vector<float> rgb = RGBtoFloat(228, 233, 237); //cinza
   clear(rgb[0], rgb[1], rgb[2]);
   color(1, 0, 0);
}

void buildBaseFunctions(int M)
{
   double y = 0;
   vector<double> amostras_base;
   vector<vector<double>> matrix_base;
   for (int u = 0; u < M; u++)
   {
      for (int i = 0; i < M; i++)
      {
         y = cos(((2 * i + 1) * u * M_PI) / (M * 2));
         amostras_base.push_back(y);
      }
      matrix_base.push_back(amostras_base);
      amostras_base.erase(amostras_base.begin(), amostras_base.end());
   }

   color(1, 0, 0);
   int start_position_x = 80;
   int start_position_y = 400;
   int size = 200;
   int offset = size;
   int offset_y = 30;

   for (auto i = 0; i < M; i++)
   {
      int position_x = (start_position_x + ((i % 4) * size));
      if (i == 4)
         start_position_y -= size;
      Graphic *base;
      base = new Graphic(position_x, start_position_y, size, "");
      base->loadVector(matrix_base[i]);
      base->graphic_visible = true;
      base->canvas_visible = true;
      baseGraphics.push_back(base);
   }
}

void buildButtons()
{
   int box = 55;
   int offset = 10;
   int start_position_x = 80;
   int start_position_y = 540;
   vector<float> rgb = RGBtoFloat(107, 185, 240);
   Button *b;
   b = new Button(start_position_x, start_position_y, box, box, "Load", rgb[0], rgb[1], rgb[2]);
   buttons.push_back(b);
   rgb = RGBtoFloat(46, 204, 113);
   b = new Button(start_position_x + box + offset, start_position_y, box, box, "Save", rgb[0], rgb[1], rgb[2]);
   buttons.push_back(b);
   rgb = RGBtoFloat(129, 207, 224);
   b = new Button(start_position_x + (box * 2) + (offset * 2), start_position_y, box, box, "Bases", rgb[0], rgb[1], rgb[2]);
   buttons.push_back(b);
}

void buildCheckboxes()
{
   Checkbox *c;
   color(1, 0, 0);
   c = new Checkbox(290, 570, "Input");
   checkboxes.push_back(c);
   c = new Checkbox(290 + 90, 570, "DCT");
   checkboxes.push_back(c);
   c = new Checkbox(290 + 180, 570, "IDCT");
   checkboxes.push_back(c);
   c = new Checkbox(290 + 270, 570, "Diff");
   checkboxes.push_back(c);
}

void buildGraphics()
{
   int start_position_x = 80;
   int size = 400;
   int offset = size + 30;
   int offset_y = 30;
   int start_position_y = 300;

   Graphic *g;
   g = new Graphic(start_position_x, start_position_y, size, "Input");
   vector<int> input = readFile("input.dct");
   vector<double> aux(input.begin() + 1, input.end());
   g->loadVector(aux);
   g->graphic_visible = false;
   graphics.push_back(g);
   g = new Graphic(start_position_x + offset, start_position_y, size, "DCT");
   vector<double> dct = DCT(input);
   g->loadVector(dct);
   g->graphic_visible = false;
   graphics.push_back(g);
   g = new Graphic(start_position_x, start_position_y - (size / 2) - offset_y, size, "IDCT");
   vector<double> idct = IDCT(dct);
   g->loadVector(idct);
   g->graphic_visible = false;
   graphics.push_back(g);
   g = new Graphic(start_position_x + offset, start_position_y - (size / 2) - offset_y, size, "Diff");
   vector<double> diff = Diff(aux, idct);
   g->loadVector(diff);
   g->graphic_visible = false;
   graphics.push_back(g);
}

void visibleGraphics()
{
   for (Graphic *graphic : graphics)
   {
      graphic->graphic_visible = true;
      graphic->canvas_visible = true;
   }
}

void buildScreen()
{
   buildBackground();
   buildButtons();
}

void renderScreen()
{
}

void setCheckboxes()
{
   for (Checkbox *checkbox : checkboxes)
   {
      checkbox->isPressed = true;
   }
}

void hideGraphics(vector<Graphic *> graphics)
{
   for (Graphic *graphic : graphics)
   {
      graphic->graphic_visible = false;
      graphic->canvas_visible = false;
   }
   for (Checkbox *checkbox : checkboxes)
   {
      checkbox->isPressed = false;
      checkbox->hide = true;
   }
}

void trataButtons(Button *button, int mouse_x, int mouse_y, int state)
{

   button->buttonActions(mouse_x, mouse_y, state);
   if (strcmp(button->getLabel(), "Load") == 0)
   {
      if (button->isPressed)
      {
         hideGraphics(baseGraphics);
         renderScreen();
         buildGraphics();
         visibleGraphics();
         buildCheckboxes();
         setCheckboxes();
         button->reset();
      }
   }
   if (strcmp(button->getLabel(), "Save") == 0)
   {
      if (button->isPressed)
      {
         writeFile(idct);
         button->reset();
      }
   }

   if (strcmp(button->getLabel(), "Bases") == 0)
   {
      if (button->isPressed)
      {
         hideGraphics(graphics);
         buildBaseFunctions(8);
         button->reset();
      }
   }
}

void trataGraphics(Graphic *graphic, bool flag, const char *label)
{
   if (strcmp(graphic->getLabel(), label) == 0 && flag == 1)
   {
      graphic->graphic_visible = true;
   }
   else if (strcmp(graphic->getLabel(), label) == 0 && flag == 0)
   {
      graphic->graphic_visible = false;
   }
}

void trataCheckboxes(Checkbox *checkbox, int mouse_x, int mouse_y, int state)
{
   checkbox->checkboxActions(mouse_x, mouse_y, state);
   int size_array = 4;
   const char *options[4] = {"Input", "DCT", "IDCT", "Diff"};

   for (auto i = 0; i < size_array; i++)
   {
      if (strcmp(checkbox->getLabel(), options[i]) == 0)
      {
         if (checkbox->isPressed)
         {
            for (Graphic *graphic : graphics)
            {
               trataGraphics(graphic, true, options[i]);
            }
         }
         else if (!checkbox->isPressed)
         {
            for (Graphic *graphic : graphics)
            {
               trataGraphics(graphic, false, options[i]);
            }
         }
      }
   }
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
   renderScreen();

   float x = 0;
   float y = 0;
   float angle = 0.0f;
   x++;
   for (int i = 0; i < 10000; i++)
   {
      angle = 0.01 * i;
      x = 300 + angle * cos(angle);
      y = 300 + angle * sin(angle);

      point(x, y);
   }

   for (auto &button : buttons)
   {
      button->render();
   }

   for (auto &graphic : graphics)
   {
      graphic->render();
   }

   for (auto &graphic : baseGraphics)
   {
      graphic->render();
   }

   for (auto &checkbox : checkboxes)
   {
      checkbox->render();
   }
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
   mouse_state = state;

   for (Button *button : buttons)
   {
      trataButtons(button, mouse_x, mouse_y, state);
   }

   for (Checkbox *checkbox : checkboxes)
   {
      trataCheckboxes(checkbox, mouse_x, mouse_y, state);
   }
}

int main(void)
{

   vector<int> amostras;
   amostras = readFile("input.dct");
   amostras.erase(amostras.begin());
   dct = DCT(amostras);
   idct = IDCT(dct);
   vector<double> amostras_d(amostras.begin(), amostras.end());
   diff = Diff(amostras_d, idct);

   initCanvas(WIDTH, HEIGHT, "T1 - Transformada do Cosseno");
   buildScreen();
   runCanvas();
}
