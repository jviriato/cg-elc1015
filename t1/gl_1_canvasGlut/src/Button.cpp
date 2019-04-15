#include "Button.h"
#include <string>

using namespace std;


Button::Button(int x, int y, int width, int height, string l, float r, float g, float b){
    setColor(r, g, b);
    setPosition(x, y);
    setSize(width, height);
    setLabel(l);
}

void Button::render(){
    float middle_of_the_box = getY() + (getHeight()/2);

    if(isInside){
        color(1,0,0);
        rectFill(getX(), getY(), getX() + getWidth(), getY() + getHeight());        
        color(0,0,0); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    } else{
        color(r,g,b);
        rect(getX(), getY(), getX() + getWidth(), getY() + getHeight());        
        color(0,0,0); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    }
    if(isPressed){
        color(0,0,0);
        rectFill(getX(), getY(), getX() + getWidth(), getY() + getHeight());        
        color(1,1,1); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    } else{
        color(r,g,b);
        rectFill(getX(), getY(), getX() + getWidth(), getY() + getHeight());        
        color(0,0,0); // cor do texto
        text(getX() + 5, middle_of_the_box, getLabel());
    }

}

bool Button::detectCollision(int mouse_x, int mouse_y){
    if( (mouse_x > getX() && mouse_x < (getX() +  width)) &&
        (mouse_y > getY() && mouse_y < (getY() + height)) ){
        printf(" x: %d y :%d h: %d w: %d\n", getX(), getY(), height, width);
        return true;
    } else {
        return false;
    }
}

float Button::getArea() {
    return (width * height); 
}

Button::~Button() {

}