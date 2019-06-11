#ifndef BEZIER_H
#define BEZIER_H
#include <cmath>
#include <vector>
#include "gl_canvas2d.h"

#include "auxFunc.h"
#include "Point.h"
#include "CtrlPoint.h"

// Propósito: Criar uma Bézier

class Bezier

{
private:
    // Pontos de controle
    std::vector<CtrlPoint> ctrlPoints;
    std::vector<Point> linePoints;

public:
    Bezier();
    Bezier(CtrlPoint p1, CtrlPoint p2, CtrlPoint p3, CtrlPoint p4);

    // Calcula a Bezier
    void calculate();
    // Desenha a Bezier
    void draw();
    // Desenha os pontos de controle da Bezier
    void drawControlPoints();
    // Translada a Bezier
    void translate();
    // Desenha a linha
    void drawLine();
    // Renderiza a Bezier
    void render(int mouse_x, int mouse_y, int button);
    void sub(Point point);
    void add(Point point);
    std::vector<Point> getLinePoints();
    void translate(double offset_x, double offset_y);
    void rotateY(double angle);
    void checkForCollisions(int mouse_x, int mouse_y, int button);
    ~Bezier();
};

#endif