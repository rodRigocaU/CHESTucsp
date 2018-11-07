#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
    setx(12);
    sety(7);
}

void Vector::setw(int x)
{
    w = x;
}

int Vector::getx()
{
    return w;
}

