#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.
using namespace std;
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "gl_canvas2d.h"
#include "Bola.h"
#include "Relogio.h"
#include "Button.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")
//#pragma comment(lib, "glut32.lib")

// vector<Button> buttons;

Button *bu = NULL;

//variaveis globais
int opcao = 50;
float global = 0;

#define WIDTH 680
#define HEIGHT 480

/* Função para inverter o eixo do canvas
   @param axis: o eixo a ser invertido
   @param height_of_canvas: o tamanho da tela
*/
int reverseAxis(int axis, int height_of_canvas)
{
   return (axis - height_of_canvas) * -1;
}

/* Função que lê o input.dct
   @param filename: arquivo.dct
*/
vector<int> readFile(std::string filename)
{
   unsigned int size;
   const int size_of_header = 4;
   char amostra;
   vector<int> amostras;

   ifstream input(filename, std::ios::binary);
   input.read(reinterpret_cast<char *>(&size), size_of_header);
   amostras.push_back(size);

   for (auto i = 0; i < size; i++)
   {
      input.read(reinterpret_cast<char *>(&amostra), 1);
      cout << "amostra[" << i << "]: " << int(amostra) << endl;
      amostras.push_back(int(amostra));
   }
   return amostras;
}

/* Função auxiliar presente na fórmula da DCT
*/
double __calcC_DCT(double u)
{
   return (u == 0) ? 1 / sqrt(2) : 1.0;
}

vector<double> DCT(const vector<int> &intVec)
{
   vector<double> result;
   vector<double> amostras(intVec.begin(), intVec.end());
   int num_amostras = amostras.front();
   // retira o tamanho total do vetor de amostras
   amostras.erase(amostras.begin());

   for (int u = 0; u < num_amostras; u++)
   {
      double sum = 0;
      int i = 0;
      for (auto const &amostra : amostras)
      {
         sum += __calcC_DCT(u) * amostra * cos((u * M_PI) / (2 * num_amostras) * (2 * i + 1));
         i++;
      }
      double amostra_dct = sqrt(2.0 / double(num_amostras)) * sum;
      result.push_back(amostra_dct);
   }

   cout << "dct" << endl;
   for (auto &value : result)
   {
      cout << value << endl;
   }

   return result;
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
   if (opcao == 'a')
   {
      clear(1, 1, 1);
      bu->render();
   }

   if (opcao == 's')
   {
      clear(1, 1, 1);
      color(1, 0, 0);
      double y = 0;
      int M = 8;
      for (int u = 1; u < 9; u++)
      {
         for (int x = 0; x < M; x += 1)
         {
            y = cos(((2 * x + 1) * u * M_PI) / (M * 2));
            // point(10 * x + 100, y*10  + HEIGHT-10 - ((u + 1) * 50));
            // point(10 * x + 100, y*10  + HEIGHT-10 - ((u * 50)));
            circleFill(5 + (10 * x), (10 * y) + HEIGHT - 10 - ((u * 50 /*50 = espaçamento*/)), 2, 100);
         }
      }
   }
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   printf("\nTecla: %d", key);
   if (key < 200)
   {
      opcao = key;
   }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d", key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   int click = 0, release_click = 1;
   y = reverseAxis(y, HEIGHT);
   // printf("\nmouse %d %d state: %d", x, y, state);

   //TODO: Encapsular isso numa função para tratar o mouse
   // Verifica se o mouse está dentro da área do botão.
   // if (bu->detectCollision(x, y))
   // {
   //    bu->isInside = true;

   //    // Verifica se o botão foi clicado
   //    if (state == click && bu->isPressed == false)
   //    {
   //       bu->isPressed = true;
   //    }
   //    else if (state == click && bu->isPressed == true)
   //    {
   //       bu->isPressed = false;
   //    }
   // }
   // else
   // {
   //    bu->isInside = false;
   // }
}

int main(void)
{
   // readFile("input.dct");
   vector<double> dDCT;
   dDCT = DCT(readFile("input.dct"));
   printf("ok");
   initCanvas(WIDTH, HEIGHT, "T1 - Transformada do Cosseno");
   // bu = new Button(WIDTH/2, HEIGHT/2, 50, 50, "ay", 1, 1, 0);

   runCanvas();
}
