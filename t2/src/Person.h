#ifndef PERSON_H
#define PERSON_H
#include "Head.h"
#include "Body.h"
#include "Leg.h"

/**
    Person.h
    Propósito: Gera uma Pessoa

    @author José Victor Viriato
    @version 0.1 2019
**/

class Person
{
private:
    double x;
    double y;
    Head *head;
    Body *body;

public:
    Leg *l1;
    Leg *l2;
    Person(double x, double y);
    void render();
    ~Person();
};

#endif
