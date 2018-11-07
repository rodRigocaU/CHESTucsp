#include "Dinero.h"
using namespace std;
#include<iostream>

Dinero::Dinero()
{
    x = 0;
    y = 0;
    num = new int;
    num = 0;
}

Dinero::Dinero(int x)
{
    this -> x = x;
    y = x / 2;
}

Dinero::Dinero(Dinero &o)
{
    this->x = x;
    this->y = y;
}

Dinero::~Dinero()
{
        delete num;
        cout << "Destruct call" << '\n';
}

void Dinero::setnum(int x)
{
        num = new int;
        *num = x;
}

void Dinero::sety(int y)
{
    this->y = y;
}

void Dinero::setx(int x)
{
    this->x = x;
}
int Dinero::getx()
{
    return x;
}

int Dinero::gety()
{
    return y;
}
void Dinero::print()
{
    cout << getx() << "->" << gety() << '\n';
}
