#include "Animal.h"

Animal::Animal(std::string n, int p)
{
    nombre = n;
    nroPatas = p;
}

void Animal::habla(void) {}

void Animal::hacerHablar()
{
     this->habla();

}



