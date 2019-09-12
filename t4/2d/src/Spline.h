#ifndef SPLINE_H
#define SPLINE_H
#include <cmath>
#include <vector>
#include "gl_canvas2d.h"

#include "auxFunc.h"
#include "Point.h"
#include "CtrlPoint.h"

// Propósito: Criar uma Bézier

class Spline

{
private:
    // Pontos de controle
    std::vector<CtrlPoint> ctrlPoints;
    std::vector<Point> linePoints;
    double num;
public:
    Spline();
    Spline(std::vector<CtrlPoint> points);

    // Calcula a Spline
    void calculate();
    // Desenha a Spline
    void draw();
    // Desenha os pontos de controle da Spline
    void drawControlPoints();
    // Translada a Spline
    void translate();
    // Desenha a linha
    void drawLine();
    // Renderiza a Spline
    void render(int mouse_x, int mouse_y, int button);
    // Operações aritméticas com os pontos
    void sub(Point point);
    void add(Point point);
    
    // Retorna os pontos da linha da Spline
    std::vector<Point> getLinePoints();
    std::vector<CtrlPoint> getCtrlPoints();
    double getNumberPoints();
    void setNumberPoints(double value);
    void drawRepresentationSpline();
    // Translada a Spline
    void translate(double offset_x, double offset_y);

    // Rotaciona a Spline
    void rotateY(double angle);
    
    // Verfica por colisões nos pontos de controle
    void checkForCollisions(int mouse_x, int mouse_y, int button);
    Point calculateBorder(Point actual, Point last, double tamanho);
    ~Spline();
};

#endif