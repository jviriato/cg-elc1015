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

#include "CtrlPoint.h"
#include "Point.h"
#include "Spline.h"
#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_X 500
#define SCREEN_Y 500

int polygonMode = 1;
float rx = 0, rz = 0;

float abertura = 44.0;
float znear = 1;
float zfar = 20;
float aspect = 1;

Spline *s;

void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ,
              GLfloat edgeLength) {
  GLfloat halfSideLength = edgeLength * 0.5f;

  GLfloat vertices[] = {
      // front face
      centerPosX - halfSideLength, centerPosY + halfSideLength,
      centerPosZ + halfSideLength, // top left
      centerPosX + halfSideLength, centerPosY + halfSideLength,
      centerPosZ + halfSideLength, // top right
      centerPosX + halfSideLength, centerPosY - halfSideLength,
      centerPosZ + halfSideLength, // bottom right
      centerPosX - halfSideLength, centerPosY - halfSideLength,
      centerPosZ + halfSideLength, // bottom left

      // back face
      centerPosX - halfSideLength, centerPosY + halfSideLength,
      centerPosZ - halfSideLength, // top left
      centerPosX + halfSideLength, centerPosY + halfSideLength,
      centerPosZ - halfSideLength, // top right
      centerPosX + halfSideLength, centerPosY - halfSideLength,
      centerPosZ - halfSideLength, // bottom right
      centerPosX - halfSideLength, centerPosY - halfSideLength,
      centerPosZ - halfSideLength, // bottom left

      // left face
      centerPosX - halfSideLength, centerPosY + halfSideLength,
      centerPosZ + halfSideLength, // top left
      centerPosX - halfSideLength, centerPosY + halfSideLength,
      centerPosZ - halfSideLength, // top right
      centerPosX - halfSideLength, centerPosY - halfSideLength,
      centerPosZ - halfSideLength, // bottom right
      centerPosX - halfSideLength, centerPosY - halfSideLength,
      centerPosZ + halfSideLength, // bottom left

      // right face
      centerPosX + halfSideLength, centerPosY + halfSideLength,
      centerPosZ + halfSideLength, // top left
      centerPosX + halfSideLength, centerPosY + halfSideLength,
      centerPosZ - halfSideLength, // top right
      centerPosX + halfSideLength, centerPosY - halfSideLength,
      centerPosZ - halfSideLength, // bottom right
      centerPosX + halfSideLength, centerPosY - halfSideLength,
      centerPosZ + halfSideLength, // bottom left

      // top face
      centerPosX - halfSideLength, centerPosY + halfSideLength,
      centerPosZ + halfSideLength, // top left
      centerPosX - halfSideLength, centerPosY + halfSideLength,
      centerPosZ - halfSideLength, // top right
      centerPosX + halfSideLength, centerPosY + halfSideLength,
      centerPosZ - halfSideLength, // bottom right
      centerPosX + halfSideLength, centerPosY + halfSideLength,
      centerPosZ + halfSideLength, // bottom left

      // top face
      centerPosX - halfSideLength, centerPosY - halfSideLength,
      centerPosZ + halfSideLength, // top left
      centerPosX - halfSideLength, centerPosY - halfSideLength,
      centerPosZ - halfSideLength, // top right
      centerPosX + halfSideLength, centerPosY - halfSideLength,
      centerPosZ - halfSideLength, // bottom right
      centerPosX + halfSideLength, centerPosY - halfSideLength,
      centerPosZ + halfSideLength // bottom left
  };
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(vertices[0], vertices[1], vertices[2]); // P1 é vermelho
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(vertices[3], vertices[4], vertices[5]); // P2 é verde
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(vertices[6], vertices[7], vertices[8]); // P3 é azul
  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(vertices[9], vertices[10], vertices[11]); // P4 é roxo
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3d(vertices[12], vertices[13], vertices[14]);
  glVertex3f(vertices[15], vertices[16], vertices[17]);
  glVertex3f(vertices[18], vertices[19], vertices[20]);
  glVertex3f(vertices[21], vertices[22], vertices[23]);
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(vertices[24],vertices[25],vertices[26]);
  glVertex3f(vertices[27],vertices[28], vertices[29]);
  glVertex3f(vertices[30],vertices[31], vertices[32]);
  glVertex3f(vertices[33],vertices[34],vertices[35]);
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glVertex3f(vertices[36], vertices[37], vertices[38]);
  glVertex3f(vertices[39], vertices[40], vertices[41]);
  glVertex3f(vertices[42], vertices[43], vertices[44]);
  glVertex3f(vertices[45], vertices[46], vertices[47]);
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
    glVertex3f(vertices[48], vertices[49], vertices[50]);
  glVertex3f(vertices[51], vertices[52], vertices[53]);
  glVertex3f(vertices[54], vertices[55], vertices[56]);
  glVertex3f(vertices[57], vertices[58], vertices[59]);
  glEnd();

  glFlush();
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glDrawArrays(GL_QUADS, 0, 24);
  // glDisableClientState(GL_VERTEX_ARRAY);
}

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

////////////////////////////////////////////////////////////////////////////////////////
void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  printf("\n%f", abertura);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluPerspective(abertura, aspect, znear, 9000);
  s->calculate();
  vector<Point> pts = s->getLinePoints();
  gluLookAt(408.138, 100,
            369.887 - 30,           // from. Posicao onde a camera esta posicionada
            408.138, 0, 380.7, // to. Posicao absoluta onde a camera esta vendo
            0, 1, 0);          // up. Vetor Up.
  s->draw();
  DrawCube(408.138, 0, 380.7, 20);
  glutSwapBuffers();
}

// faz a leitura da entrada do usuario
void keyboard(unsigned char key, int x, int y) {
  // printf("%c", key);
  key = tolower(key);
  switch (key) {
  case 27:
    exit(0);
    break;

  case 'w': // wireframe
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
  }
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
  std::vector<CtrlPoint> ctrlpoints{
      CtrlPoint(192, 0, 217), CtrlPoint(233, 0, 429), CtrlPoint(446, 0, 394),
      CtrlPoint(460, 0, 186)};
  s = new Spline(ctrlpoints);

  // char *argv[1] = {"teste"};
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

  glutMainLoop();
  return 0;
}
