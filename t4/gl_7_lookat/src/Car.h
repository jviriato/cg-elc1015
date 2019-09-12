#include <GL/glut.h>
#include "Point.h"

class Car {
private:

public:
  Point position_vector; // Onde o carro está posicionado no mundo
  Point forward_vector;  // O vetor apontando para a mesma direção do carro.
  Point anterior_forward_vector;
  Point acceleration_vector;  // vetor de aceleração
  Point velocity_vector;      // vetor de velocidade
  double acceleration_input;  // intervalo: [-1, 1].
  double acceleration_factor; // fator de aceleração
  double steer_input;
  double steer_factor;
  double steer_angle;
  double current_speed;
  void updateAccelerationVector();
  void steerAngle();
  void moving();
  void draw();
  void drawFoward_vector();
  Car(Point initial_position);
  ~Car();
};
