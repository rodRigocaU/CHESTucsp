#include <iostream>
#include <cstdlib>
using namespace std;
class piece
{
public:
    int posxy;
};
void draw(int tam)
{
    cout << '\n';
    cout << '\n';
    cout << '\n';
    for(int x  = 0; x < tam ; x ++)
    {
        cout << '\t';
        cout << '\t';
        if(x < 2)
        {
            cout << " | 1 " << " 1 " << " 1 " << " 1 " << " 1 " << " 1 " << " 1 " <<  " 1 |" << '\n';
        }
        else if(x > 5)
        {
            cout << " | 2 " << " 2 " << " 2 " << " 2 " << " 2 " << " 2 " << " 2 " <<  " 2 |" << '\n';
        }
        else
            cout << " | 0 " << " 0 " << " 0 " << " 0 " << " 0 " << " 0 " << " 0 " <<  " 0 |" << '\n';
    }
}
int main()
{
    system("color f2");
    int table[64] = {11,12,13,14,15,16,17,18,21,22,23,24,25,26,27,28,31,32,33,34,35,36,37,38,41,42,43,44,45,46,47,48,51,52,53,54,55,56,57,58,61,62,63,64,65,67,68,71,72,73,74,75,76,77,78,81,82,83,84,85,86,87,88};
    int tam = 8;
    draw(tam);
    int nump = 32;

    piece caballoW1;     caballoW1.posxy = table[1];
    piece caballoW2;     caballoW2.posxy = table[6];
    piece alfilW1;       alfilW1.posxy = table[2];
    piece alfilW2;       alfilW2.posxy = table[5];
    piece torreW1;       torreW1.posxy = table[0];
    piece torreW2;       torreW2.posxy = table[7];
    piece reyW;          reyW.posxy = table[4];
    piece reinaW;        reinaW.posxy = table[3];
    piece peonW1;        peonW1.posxy = table[8];
    piece peonW2;        peonW2.posxy = table[9];
    piece peonW3;        peonW3.posxy = table[10];
    piece peonW4;        peonW4.posxy = table[11];
    piece peonW5;        peonW5.posxy = table[12];
    piece peonW6;        peonW6.posxy = table[13];
    piece peonW7;        peonW7.posxy = table[14];
    piece peonW8;        peonW8.posxy = table[15];

    //piezas blancas


    piece caballoB1;     caballoB1.posxy = table[57];
    piece caballoB2;     caballoB2.posxy = table[62];
    piece alfilB1;       alfilB1.posxy = table[58];
    piece alfilB2;       alfilB2.posxy = table[61];
    piece torreB1;       torreB1.posxy = table[56];
    piece torreB2;       torreB2.posxy = table[63];
    piece reyB;          reyB.posxy = table[60];
    piece reinaB;        reinaB.posxy = table[59];
    piece peonB1;        peonB1.posxy = table[55];
    piece peonB2;        peonB2.posxy = table[54];
    piece peonB3;        peonB3.posxy = table[53];
    piece peonB4;        peonB4.posxy = table[52];
    piece peonB5;        peonB5.posxy = table[51];
    piece peonB6;        peonB6.posxy = table[50];
    piece peonB7;        peonB7.posxy = table[49];
    piece peonB8;        peonB8.posxy = table[48];

    system("pause");
    return 0;
}
