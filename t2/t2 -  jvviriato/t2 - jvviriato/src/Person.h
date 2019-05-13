#ifndef PERSON_H
#define PERSON_H
#include "Head.h"
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
public:
    Person(double x, double y);
    void render();
    ~Person();
};

#endif
