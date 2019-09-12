/**
*   Programa para ilustrar:
*   - Uso da gluLookAt
*   - Pilha de transformacoes
*   - Projecao pespectiva
*   - Interacao com o mouse/teclado
*   - cullFace, frontFace

*   Autor: Cesar Tadeu Pozzer
*   UFSM - 15/06/2007
*
*   pozzer@inf.ufsm.br
*   pozzer3@gmail.com
*
**/

#include <GL/glut.h>
//#include <GL/freeglut_ext.h> //callback da wheel do mouse.
#include "Car.h"
#include "CtrlPoint.h"
#include "Point.h"
#include "Spline.h"
#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#ifdef defined(_WIN32) || defined(WIN32)
#define OS_Windows 1
#include <windows.h>
#else
#define OS_Windows 0
#endif
#define FPS 60
timeval start, fim;
using namespace std;
#define SCREEN_X 500
#define SCREEN_Y 500
int polygonMode = 1;
float rx = 0, rz = 0;
bool buffer[256];
double y = 0;
float abertura = 44.0;
float znear = 1;
float zfar = 20;
float aspect = 1;

Spline *s;
Car *c;
Point *eye;
Point *looking;
bool car_vision = 0;
void init() {

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(abertura, aspect, znear, zfar);
  glMatrixMode(GL_MODELVIEW);

  glClearColor(0, 0, 0, 1);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glEnable(GL_DEPTH_TEST);
}

// imprime as matrizes da pilha do opengl
void printMatrix(GLenum pname) {
  GLfloat m[16]; // usado para leitura das matrizes
  glGetFloatv(pname, m);
  int l, c;
  printf("\n\n Matriz = %d", pname);
  for (l = 0; l < 4; l++) {
    printf("\n");
    for (c = 0; c < 4; c++) {
      int pos = l * 4 + c;
      printf(" %.2f", m[pos]);
    }
  }
}

void fps() {
  double runtime = fim.tv_sec + fim.tv_usec / 1000000.0 - start.tv_sec -
                   start.tv_usec / 1000000.0;
  double duration = 1000 / FPS - runtime * 1000;
  if (duration > 0)
    if (OS_Windows) {
      sleep(duration);
    } else {
      usleep(duration);
    }
  // cout << 60 - duration << endl;
}

void display(void) {
  gettimeofday(&start, NULL);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // printf("\n%f", abertura);

  // // cout << "pos cubo: [" << c->position_vector.x() << ", "
  //      << c->position_vector.y() << ", " << c->position_vector.z() << "]"
  //      << endl;

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluPerspective(abertura, aspect, znear, 9000);
  s->calculate();
  vector<Point> pts = s->getLinePoints();

  if (car_vision) {
    eye->setX(c->position_vector.x());
    eye->setY(c->position_vector.y());
    eye->setZ(c->position_vector.z());
    looking->setX(c->position_vector.x() - 10);
    looking->setY(c->position_vector.y());
    looking->setZ(c->position_vector.z());

  } else {
    eye->setX(c->position_vector.x() + 120);
    eye->setY(c->position_vector.y() + 80);
    eye->setZ(c->position_vector.z());
    looking->setX(c->position_vector.x());
    looking->setY(c->position_vector.y());
    looking->setZ(c->position_vector.z());
  }
  gluLookAt(eye->x(), eye->y(), eye->z(), looking->x(), looking->y(),
            looking->z(), 0, 1, 0); // up. Vetor Up.
  s->draw();
  if (!car_vision) {
    c->draw();
  }
  c->drawFoward_vector();
  gettimeofday(&fim, NULL);
  glutSwapBuffers();
  fps();

  if (buffer[119]) { // w
    c->forward_vector = Point(-1, 0, 0);
    if (buffer[100]) { // wd
      c->forward_vector = Point(-1, 0, -1);
      c->drawFoward_vector();
      c->moving();
      c->steer_angle -= 45;
    } else if (buffer[97]) { // wa
      c->forward_vector = Point(-1, 0, 1);
      c->drawFoward_vector();
      c->moving();
    }
    c->moving();
    c->drawFoward_vector();
  } else if (buffer[115]) { // s
    c->forward_vector = Point(1, 0, 0);
    if (buffer[100]) { // sd
      c->forward_vector = Point(1, 0, -1);
      c->drawFoward_vector();
      c->moving();
    } else if (buffer[97]) {
      c->forward_vector = Point(1, 0, 1);
      c->drawFoward_vector();
      c->moving();
    }
    c->moving();
    c->drawFoward_vector();
  }
}

unsigned char last_key;
// faz a leitura da entrada do usuario
void keyboard(unsigned char key, int x, int y) {
  // printf("%c", key);
  key = tolower(key);
  buffer[key] = true;
  switch (key) {
  case 27:
    exit(0);
    break;

  case 'z': // wireframe
    if (polygonMode == 1) {
      polygonMode = 0;
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    } else {
      polygonMode = 1;
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    break;
  case '+':
    abertura += 1;

  case 'w':
    break;

  case 'a':
    if (last_key != 'a')
      c->anterior_forward_vector = c->forward_vector;
    last_key = 'a';
    break;

  case 's':
      c->anterior_forward_vector = c->forward_vector;
    last_key = 's';
    break;

  case 'd':
    if (last_key != 'd')
      c->anterior_forward_vector = c->forward_vector;
    last_key = 'd';
    break;

  case 'c':
    car_vision = !car_vision;
    break;

  case 'q':
    c->steer_angle = 45;
    break;
  case 'e':
    c->steer_angle -= 45 % 360;
    break;
  }
}

void keyboardUp(unsigned char key, int x, int y) {
  key = tolower(key);
  buffer[key] = false;
}

void MotionFunc(int x, int y) {
  //   float dx, dy;
  // printf("\nX = %d Y = %d", x, y);
  rx = x;
  rz = y;
}

void MouseFunc(int botao, int estado, int x, int y) {
  // printf("\n%d %d %d %d", botao, estado, x, y);
}

////////////////////////////////////////////////////////////////////////////////////////
int main() {
  int argc = 0;
  eye = new Point(0, 0, 0);
  looking = new Point(0, 0, 0);
  std::vector<CtrlPoint> ctrlpoints{
      CtrlPoint(192, 0, 217), CtrlPoint(233, 0, 429), CtrlPoint(446, 0, 394),
      CtrlPoint(460, 0, 186)};
  s = new Spline(ctrlpoints);
  c = new Car(Point(408.138, 10, 360.7));
  glutInit(&argc, NULL);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowSize(SCREEN_X, SCREEN_Y);
  glutInitWindowPosition(450, 10);
  /* create window */
  glutCreateWindow("GluLookAt Demo");
  // init();
  printf("Digite W para mudar o modo de visualizacao: wireframe/fill");

  glutDisplayFunc(display);
  glutMotionFunc(MotionFunc);
  glutMouseFunc(MouseFunc);
  glutIdleFunc(display);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);

  glutMainLoop();
  return 0;
}
