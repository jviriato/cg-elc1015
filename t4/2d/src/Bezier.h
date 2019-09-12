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
    double num;
public:
    Bezier();
    Bezier(std::vector<CtrlPoint> points);

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
    // Operações aritméticas com os pontos
    void sub(Point point);
    void add(Point point);
    
    // Retorna os pontos da linha da Bezier
    std::vector<Point> getLinePoints();
    std::vector<CtrlPoint> getCtrlPoints();
    double getNumberPoints();
    void setNumberPoints(double value);
    void drawRepresentationBezier();
    // Translada a Bezier
    void translate(double offset_x, double offset_y);

    // Rotaciona a Bezier
    void rotateY(double angle);
    
    // Verfica por colisões nos pontos de controle
    void checkForCollisions(int mouse_x, int mouse_y, int button);
    ~Bezier();
};

#endif