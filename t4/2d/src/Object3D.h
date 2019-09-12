#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <cmath>
#include <vector>
#include "gl_canvas2d.h"
#include "Point.h"
#include "Bezier.h"

// Propósito: Criar um objeto 3D

class Object3D
{
protected:
    // O Wireframe da aplicação
    std::vector<std::vector<Point>> wireframe;
    // O Wireframe em perspectiva
    std::vector<std::vector<Point>> wireframe_perspective;
    Bezier bezier;
    // O ponto de origem da Bezier
    Point origem;
    // A coordenada z
    double z;
    // qtd. de lados
    double lados;
    // distância da câmera
    double distance;

public:
    Object3D(Bezier b, Point o);
    // Constrói o wireframe
    void buildWireframe(Bezier b);
    // Desenha o wireframe
    void drawWireframe();
    void buildWireframePerspective(std::vector<Point> linePoints);
    // cria as linhas do objeto
    void createLines(Point p1, Point p2);
    // Getters e Setters
    double getZ();
    void setZ(double value);
    double getDistance();
    void setDistance(double value);
    double getLados();
    void setLados(double value);
    // renderização do objeto
    void render(Bezier b);
    // rotaciona a bezier
    void rotateBezier(double angle, Bezier &b);
    void setNumberPoints(double value, Bezier &b);

    ~Object3D();
};

#endif