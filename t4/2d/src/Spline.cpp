#include "Spline.h"
#include "CtrlPoint.h"
#include "Point.h"
#include <iostream>
Spline::Spline() {
  ctrlPoints.push_back(CtrlPoint(0, 0));
  ctrlPoints.push_back(CtrlPoint(0, 0));
  ctrlPoints.push_back(CtrlPoint(0, 0));
  ctrlPoints.push_back(CtrlPoint(0, 0));
  num = .1;
}

Spline::Spline(std::vector<CtrlPoint> points) {
  for (CtrlPoint ctrlPoint : points) {
    ctrlPoints.push_back(ctrlPoint);
  }
  num = .1;
}

Point Spline::calculateBorder(Point actual, Point last, double tamanho) {
  Point u = Point(actual.x() - last.x(), actual.y() - last.y());
  u.setX(u.x() / u.norm());
  u.setY(u.y() / u.norm());
  u.rotateZ(90);
  u.setX(u.x() * tamanho);
  u.setY(u.y() * tamanho);
  u.setX(u.x() + actual.x());
  u.setY(u.y() + actual.y());
  return u;
}

// Calcula a Spline
void Spline::calculate() {
  linePoints.clear();
  double t = 0.0;
  int number_of_ctrl_pts = 4;
  for (int i = 0; i <= number_of_ctrl_pts; i++) {
    for (double t = 0.0; t <= 1; t += 0.01) {
      double blending_functions[4] = {
          (pow(t, 3)) / 6, (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1) / 6,
          (3 * pow(t, 3) - 6 * pow(t, 2) + 4) / 6, pow(1 - t, 3) / 6};
      double xt = blending_functions[0] * ctrlPoints[(i + 3) % number_of_ctrl_pts].x() +
                  blending_functions[1] * ctrlPoints[(i + 2) % number_of_ctrl_pts].x() +
                  blending_functions[2] * ctrlPoints[(i + 1) % number_of_ctrl_pts].x() +
                  blending_functions[3] * ctrlPoints[i % number_of_ctrl_pts].x();
      double yt = blending_functions[0] * ctrlPoints[(i + 3) % number_of_ctrl_pts].y() +
                  blending_functions[1] * ctrlPoints[(i + 2) % number_of_ctrl_pts].y() +
                  blending_functions[2] * ctrlPoints[(i + 1) % number_of_ctrl_pts].y() +
                  blending_functions[3] * ctrlPoints[i % number_of_ctrl_pts].y();
      if (linePoints.size() > 1) {
        Point u = calculateBorder(Point(xt, yt), linePoints.back(), 10);
        line(u.x(), u.y(), xt, yt);
        u = calculateBorder(Point(xt, yt), linePoints.back(), -10);
        line(u.x(), u.y(), xt, yt);
      }
      color(0, 1, 0);
      point(xt, yt);
      color(1, 0, 0);
      linePoints.push_back(Point(xt, yt));
    }
  }
}

void Spline::drawControlPoints() {
  for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin();
       it != ctrlPoints.end(); ++it) {
    if (it->getCanEdit()) {
      color(1, 0, 0);
      circleFill(it->x(), it->y(), 5, 50);
    } else {
      color(0, 1, 0);
      circleFill(it->x(), it->y(), 5, 50);
    }
  }
}

void Spline::drawLine() {
  double t = 0.0;
  vector<Point> points;
  for (int i = 0; i < 5; i++) {
    for (t = 0.0; t <= 1; t += 0.01) {
      double blending_functions[4] = {
          (pow(t, 3)) / 6, (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1) / 6,
          (3 * pow(t, 3) - 6 * pow(t, 2) + 4) / 6, pow(1 - t, 3) / 6};
      double xt = blending_functions[0] * ctrlPoints[(i + 3) % 4].x() +
                  blending_functions[1] * ctrlPoints[(i + 2) % 4].x() +
                  blending_functions[2] * ctrlPoints[(i + 1) % 4].x() +
                  blending_functions[3] * ctrlPoints[i % 4].x();
      double yt = blending_functions[0] * ctrlPoints[(i + 3) % 4].y() +
                  blending_functions[1] * ctrlPoints[(i + 2) % 4].y() +
                  blending_functions[2] * ctrlPoints[(i + 1) % 4].y() +
                  blending_functions[3] * ctrlPoints[i % 4].y();
      if (points.size() > 1) {
        Point u = calculateBorder(Point(xt, yt), points.back(), 10);
        line(u.x(), u.y(), xt, yt);
        u = calculateBorder(Point(xt, yt), points.back(), -10);
        line(u.x(), u.y(), xt, yt);
      }
      color(0, 1, 0);
      point(xt, yt);
      color(1, 0, 0);
      points.push_back(Point(xt, yt));
    }
  }
}

void Spline::draw() {
  color(0, 1, 0);
  drawLine();
  color(1, 0, 0);
  drawControlPoints();
}

void Spline::render(int mouse_x, int mouse_y, int button) {
  for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin();
       it != ctrlPoints.end(); ++it) {
    if (it->getCanEdit()) {
      it->setX(mouse_x);
      it->setY(mouse_y);
    }
  }
  calculate();
  draw();
}

void Spline::checkForCollisions(int mouse_x, int mouse_y, int button) {
  for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin();
       it != ctrlPoints.end(); ++it) {
    if (it->detectColision(mouse_x, mouse_y) && button == 0 &&
        !it->getCanEdit()) {
      it->setCanEditToTrue();
    } else if (button == 0 && it->getCanEdit()) {
      it->setCanEditToFalse();
    }
  }
}

void Spline::translate(double offset_x, double offset_y) {
  for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin();
       it != ctrlPoints.end(); ++it) {
    it->translateMatrix2D(-it->x(), -it->y());
  }
}

void Spline::rotateY(double angle) {
  for (std::vector<Point>::iterator it = linePoints.begin();
       it != linePoints.end(); ++it) {
    it->rotateY(angle);
  }

  for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin();
       it != ctrlPoints.end(); ++it) {
    it->rotateY(angle);
  }
}

void Spline::sub(Point point) {
  for (std::vector<Point>::iterator it = linePoints.begin();
       it != linePoints.end(); ++it) {
    it->sub(point);
  }
  for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin();
       it != ctrlPoints.end(); ++it) {
    it->sub(point);
  }
}

void Spline::add(Point point) {
  for (std::vector<Point>::iterator it = linePoints.begin();
       it != linePoints.end(); ++it) {
    it->add(point);
  }
  for (std::vector<CtrlPoint>::iterator it = ctrlPoints.begin();
       it != ctrlPoints.end(); ++it) {
    it->add(point);
  }
}

std::vector<Point> Spline::getLinePoints() { return linePoints; }

std::vector<CtrlPoint> Spline::getCtrlPoints() { return ctrlPoints; }
double Spline::getNumberPoints() { return num; }
void Spline::setNumberPoints(double value) { num = value; }
Spline::~Spline() {}
