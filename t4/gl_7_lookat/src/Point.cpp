#include "Point.h"

Point::Point(double x, double y, double z) {
  xval = x;
  yval = y;
  zval = z;
}
// Extratores.
double Point::x() { return xval; }
double Point::y() { return yval; }
double Point::z() { return zval; }
void Point::setX(double x) { xval = x; }
void Point::setY(double y) { yval = y; }
void Point::setZ(double z) { zval = z; }

Point Point::add(Point another) {
  double x = xval + another.xval;
  double y = yval + another.yval;
  double z = zval + another.zval;
  return Point(x, y, z);
}

Point Point::sub(Point another) {
  double x = xval - another.xval;
  double y = yval - another.yval;
  double z = zval - another.zval;
  return Point(x, y, z);
}

double Point::prod_escalar(Point another)
{
  return (xval * another.x()) + (yval * another.y()) + (zval * another.z());
}

double Point::norm() {
  return std::sqrt(pow(x(), 2) + pow(y(), 2) + pow(z(), 2));
}

// Matriz de translação
void Point::translateMatrix2D(double offset_x, double offset_y) {
  const double translate_matrix[3][3] = {
      {1, 0, offset_x}, {0, 1, offset_y}, {0, 0, 1}};
  xval = (xval * translate_matrix[0][0]) + (yval * translate_matrix[0][1]) +
         offset_x;
  yval = (xval * translate_matrix[1][0]) + (yval * translate_matrix[1][1]) +
         offset_y;
}

double Point::distance(Point another) {
  const double x_diff = x() - another.x();
  const double y_diff = y() - another.y();
  const double z_diff = z() - another.z();
  return std::sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
}

void Point::rotateY(double angle) {
  double radians_angle = degreesToRadians(angle);

  const double rotation_matrix[5][5] = {
      {cos(radians_angle), 0, sin(radians_angle), 0},
      {0, 1, 0, 0},
      {-sin(radians_angle), 0, cos(radians_angle), 0},
      {0, 0, 0, 1}};

  double new_x =
      ((xval * rotation_matrix[0][0]) + (yval * rotation_matrix[0][1]) +
       (zval * rotation_matrix[0][2]));
  double new_y =
      ((xval * rotation_matrix[1][0]) + (yval * rotation_matrix[1][1]) +
       (zval * rotation_matrix[1][2]));
  double new_z =
      ((xval * rotation_matrix[2][0]) + (yval * rotation_matrix[2][1]) +
       (zval * rotation_matrix[2][2]));

  xval = new_x;
  yval = new_y;
  zval = new_z;
}

void Point::rotateX(double angle) {
  double radians_angle = degreesToRadians(angle);

  const double rotation_matrix[4][4] = {
      {1, 0, 0, 0},
      {0, cos(radians_angle), -sin(radians_angle), 0},
      {0, sin(radians_angle), cos(radians_angle), 0},
      {0, 0, 0, 1}};

  double new_x =
      ((xval * rotation_matrix[0][0]) + (yval * rotation_matrix[0][1]) +
       (zval * rotation_matrix[0][2]));
  double new_y =
      ((xval * rotation_matrix[1][0]) + (yval * rotation_matrix[1][1]) +
       (zval * rotation_matrix[1][2]));
  double new_z =
      ((xval * rotation_matrix[2][0]) + (yval * rotation_matrix[2][1]) +
       (zval * rotation_matrix[2][2]));

  xval = new_x;
  yval = new_y;
  zval = new_z;
}

void Point::rotateZ(double angle) {
  double radians_angle = degreesToRadians(angle);

  const double rotation_matrix[4][4] = {
      {cos(radians_angle), -sin(radians_angle), 0, 0},
      {sin(radians_angle), cos(radians_angle), 0, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 1}};
  double new_x =
      ((xval * rotation_matrix[0][0]) + (yval * rotation_matrix[0][1]) +
       (zval * rotation_matrix[0][2]));
  double new_y =
      ((xval * rotation_matrix[1][0]) + (yval * rotation_matrix[1][1]) +
       (zval * rotation_matrix[1][2]));
  double new_z =
      ((xval * rotation_matrix[2][0]) + (yval * rotation_matrix[2][1]) +
       (zval * rotation_matrix[2][2]));

  xval = new_x;
  yval = new_y;
  zval = new_z;
}

Point Point::toCamera(double d) {
  return Point(((xval * d) / zval), ((yval * d) / zval));
}

Point::~Point() {}
