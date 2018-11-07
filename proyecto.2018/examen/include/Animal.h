#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
using namespace std;


class Animal
{
    public:
        Animal(string,int);
        virtual void habla(void);
        void hacerHablar();

    protected:
        string nombre;
        int nroPatas;
};

#endif // ANIMAL_H
