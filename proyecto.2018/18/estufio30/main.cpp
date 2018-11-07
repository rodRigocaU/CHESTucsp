#include <iostream>
#include <Dinero.h>
#include <Vector.h>
using namespace std;

int main()
{
    Dinero rodrigo;
    rodrigo.setx(2055);
    rodrigo.sety(15);
    rodrigo.print();

    Dinero roberto;
    roberto.print();

    Dinero luna(8);
    luna.print();

    Dinero copo;
    copo = rodrigo;
    copo.print();

    cout << '\n' << '\n';
    Vector prro;
    Dinero *er = &prro;
    prro.setx(10);
    prro.setw(10);
    prro.getx();
    return 0;
}
