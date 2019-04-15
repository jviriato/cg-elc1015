#include "Interface.h"

using namespace std;

// Controller::Controller(){

// }

void Controller::setColor(float red, float green, float blue){
    r = red;
    g = green;
    b = blue;
}

float * Controller::getColor() {
    float *rgb = (float*)malloc(sizeof(float) * 3);
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    return rgb; 
}

int Controller::getX(){
    return x;
}

int Controller::getY(){
    return y;
}

void Controller::setPosition(int pos_x, int pos_y){
    x = pos_x;
    y = pos_y;
}

void Controller::setLabel(string l){
    label = l;
}

void Controller::setSize(float w, float h){
    width  = w;
    height = h;
}

int Controller::getHeight(){
    return height;
}

int Controller::getWidth(){
    return width;
}

char* Controller::getLabel(){
    char* l = (char*)malloc(sizeof(char) * label.size());
    strcpy(l, label.c_str()); 
    return l;
}


Controller::~Controller() {
    
}