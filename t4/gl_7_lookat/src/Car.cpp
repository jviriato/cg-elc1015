#include "Car.h"
#include <iostream>
#define radiansToDegrees(angleRadians) ((angleRadians)*180.0 / M_PI)

Car::Car(Point initial_position) {
  position_vector = initial_position;
  acceleration_vector = initial_position;
  forward_vector = Point(-1, 0, 0);
  anterior_forward_vector = Point(-1, 0, 0);
  acceleration_input = .2;
  acceleration_factor = 5;
  current_speed = 0.0;
  steer_angle = 0.0;
  steer_factor = 5;
  steer_input = 0.5;
}

Car::~Car() {}

void Car::draw() {
  GLfloat centerPosX = position_vector.x();
  GLfloat centerPosY = position_vector.y();
  GLfloat centerPosZ = position_vector.z();
  GLfloat edgeLength = 10;
  GLfloat halfSideLength = edgeLength * 0.5f;
  glEnable(GL_DEPTH_TEST);

  // steer_angle = 45;
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

  // lado esq
    cout << radiansToDegrees(steer_angle) << endl;

  glPushMatrix();
  glTranslatef(position_vector.x(), position_vector.y(), position_vector.z());
  glRotatef((GLfloat)-steer_angle, 0.0, 1.0, 0.0);
  glTranslatef(-position_vector.x(), -position_vector.y(), -position_vector.z());

  glBegin(GL_POLYGON);
  glColor3f(1.0, 0, 0);
  glVertex3d(vertices[0], vertices[1], vertices[2]);
  glVertex3f(vertices[3], vertices[4], vertices[5]);
  glVertex3f(vertices[6], vertices[7], vertices[8]);
  glVertex3f(vertices[9], vertices[10], vertices[11]);
  glEnd();

  glPopMatrix();

  // lado dir
  glPushMatrix();
  glTranslatef(position_vector.x(), position_vector.y(), position_vector.z());
  glRotatef((GLfloat)-steer_angle, 0.0, 1.0, 0.0);
  glTranslatef(-position_vector.x(), -position_vector.y(), -position_vector.z());

  glBegin(GL_POLYGON);
  glColor3f(1.0, 0, 1.0);
  glVertex3d(vertices[12], vertices[13], vertices[14]);
  glVertex3f(vertices[15], vertices[16], vertices[17]);
  glVertex3f(vertices[18], vertices[19], vertices[20]);
  glVertex3f(vertices[21], vertices[22], vertices[23]);
  glEnd();
  glPopMatrix();

  // frent
  glPushMatrix();
  glTranslatef(position_vector.x(), position_vector.y(), position_vector.z());
  glRotatef((GLfloat)-steer_angle, 0.0, 1.0, 0.0);
  glTranslatef(-position_vector.x(), -position_vector.y(), -position_vector.z());

  glBegin(GL_POLYGON);
  glColor3f(0, 1.0, 0);
  glVertex3f(vertices[24], vertices[25], vertices[26]);
  glVertex3f(vertices[27], vertices[28], vertices[29]);
  glVertex3f(vertices[30], vertices[31], vertices[32]);
  glVertex3f(vertices[33], vertices[34], vertices[35]);
  glEnd();

  glPopMatrix();

  // atras
  glPushMatrix();
  glTranslatef(position_vector.x(), position_vector.y(), position_vector.z());
  glRotatef((GLfloat)-steer_angle, 0.0, 1.0, 0.0);
  glTranslatef(-position_vector.x(), -position_vector.y(), -position_vector.z());

  glBegin(GL_POLYGON);
  glColor3f(0, 1.0, 0);
  glVertex3f(vertices[36], vertices[37], vertices[38]);
  glVertex3f(vertices[39], vertices[40], vertices[41]);
  glVertex3f(vertices[42], vertices[43], vertices[44]);
  glVertex3f(vertices[45], vertices[46], vertices[47]);
  glEnd();

  glPopMatrix();

  // top
  glPushMatrix();
  glTranslatef(position_vector.x(), position_vector.y(), position_vector.z());
  glRotatef((GLfloat)-steer_angle, 0.0, 1.0, 0.0);
  glTranslatef(-position_vector.x(), -position_vector.y(), -position_vector.z());

  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 0);
  glVertex3f(vertices[48], vertices[49], vertices[50]);
  glVertex3f(vertices[51], vertices[52], vertices[53]);
  glVertex3f(vertices[54], vertices[55], vertices[56]);
  glVertex3f(vertices[57], vertices[58], vertices[59]);
  glEnd();

  glPopMatrix();

  //  BOTTOM
  glPushMatrix();
  glTranslatef(position_vector.x(), position_vector.y(), position_vector.z());
  glRotatef((GLfloat)-steer_angle, 0.0, 1.0, 0.0);
  glTranslatef(-position_vector.x(), -position_vector.y(), -position_vector.z());

  glBegin(GL_POLYGON);
  glColor3f(1.0, 0, 1.0);
  glVertex3f(vertices[60], vertices[61], vertices[62]);
  glVertex3f(vertices[63], vertices[64], vertices[65]);
  glVertex3f(vertices[66], vertices[67], vertices[68]);
  glVertex3f(vertices[69], vertices[70], vertices[71]);
  glEnd();

  glPopMatrix();

  glFlush();
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glDrawArrays(GL_QUADS, 0, 24);
}

void Car::updateAccelerationVector() {
  acceleration_vector.setX(forward_vector.x() * acceleration_input *
                           acceleration_factor);
  acceleration_vector.setY(forward_vector.y() * acceleration_input *
                           acceleration_factor);
  acceleration_vector.setZ(forward_vector.z() * acceleration_input *
                           acceleration_factor);
}

void Car::steerAngle() {
  Point v1 = forward_vector;
  Point v2 = anterior_forward_vector;
  steer_angle = acos(v1.prod_escalar(v2) / (v1.norm() * v2.norm()));
}

void Car::drawFoward_vector() {
  glColor3f(1, 0, 0);
  glBegin(GL_LINES);
  Point fim = Point(0, 0, 0);
  fim.setX(position_vector.x() + (forward_vector.x() * 100));
  fim.setY(position_vector.y() + (forward_vector.y() * 100));
  fim.setZ(position_vector.z() + (forward_vector.z() * 100));
  glVertex3d(position_vector.x(), position_vector.y(), position_vector.z());
  glVertex3d(fim.x(), fim.y(), fim.z());
  glEnd();
}

void Car::moving() {
  updateAccelerationVector();
  current_speed = velocity_vector.norm();
  double max_speed = 10;
  double time_since_last_frame = 0.4;
  steerAngle();
  if (current_speed < max_speed) {
    velocity_vector.setX(acceleration_vector.x() * time_since_last_frame);
    velocity_vector.setY(acceleration_vector.y() * time_since_last_frame);
    velocity_vector.setZ(acceleration_vector.z() * time_since_last_frame);
  }
  position_vector.setX(position_vector.x() +
                       (velocity_vector.x() * time_since_last_frame));
  position_vector.setY(position_vector.y() +
                       (velocity_vector.y() * time_since_last_frame));
  position_vector.setZ(position_vector.z() +
                       (velocity_vector.z() * time_since_last_frame));
}