#include "Point.h"

class Car {
private:
  Point position_vector; // Onde o carro está posicionado no mundo
  Point forward_vector;  // O vetor apontando para a mesma direção do carro.
  Point acceleration_vector;  // vetor de aceleração
  Point velocity_vector;      // vetor de velocidade
  double acceleration_input;  // intervalo: [-1, 1].
  double acceleration_factor; // fator de aceleração
  double steer_input;
  double steer_factor;
  double steer_angle;
  double current_speed;

public:
  void updateAccelerationVector();
  void steerAngle();
  void moving();
  void draw();
  Car(Point initial_position);
  ~Car();
};

Car::Car(Point initial_position) {
  position_vector = initial_position;
  acceleration_input = .5;
  acceleration_factor = 10;
  current_speed = 0.0;
  steer_angle = 0.0;
  steer_factor = 0.0;
  steer_input = 0.0;
}

Car::~Car() {}

void Car::draw() {}

void Car::updateAccelerationVector() {
  acceleration_vector.setX(forward_vector.x() * acceleration_input *
                           acceleration_factor);
  acceleration_vector.setY(forward_vector.y() * acceleration_input *
                           acceleration_factor);
}

void Car::steerAngle() {
  steer_angle = steer_input * steer_factor;
  forward_vector.rotateY(steer_angle);
}

void Car::moving() {
  current_speed = velocity_vector.norm();
  double max_speed = 999999999;
  double time_since_last_frame = 1;
  if (current_speed < max_speed) {
    velocity_vector.setX(acceleration_vector.x() * time_since_last_frame);
    velocity_vector.setY(acceleration_vector.y() * time_since_last_frame);
  }
  position_vector.setX(velocity_vector.x() * time_since_last_frame);
  position_vector.setY(velocity_vector.y() * time_since_last_frame);
}