#ifndef PERRO_H
#define PERRO_H
#include <iostream>
#include "Animal.h"

using namespace std;


class Perro : public Animal
{
    public:
        Perro(string n,int p): Animal(n,p){}
        virtual ~Perro();
    private:
};

#endif // PERRO_H
