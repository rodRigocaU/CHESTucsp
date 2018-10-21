#include <iostream>
#include <cstdlib>
#include <graphics.h>

using namespace std;
bool colision(int wx, int wy, int bx, int by )
{
    if(wx == bx || wy == by)
    {
        return true;
    }
    return false;
}
class Point{
public:
    int posx,posy;
};
class Tablero{
public:
    int i=8, j=8;
void draw(){
    for(int x=0;x<i;x++){
        cout << '\n';
        cout << '\t';
        cout << "|" << " ";
        for(int y=0;y<j;y++){
            if((x%2==0 && y%2==0) || (x%2==1 && y%2==1))
                cout << "N" << " ";
            else
                cout << "B" << " ";
        }
        cout << "|";
    }
}
};

//-------------------------------------------------
class piece{
public:
    Point xy;
    bool ismove = false, islive = true;
    bool b1n0;
    int i,j;
};

class Peon:public piece{
void MoverPeon(){
    if(b1n0 == false){
        if(ismove == false)
            ismove = true;
    }
}
};

//--------------------------------------------------

int main()
{   system("color f3");
    Tablero tablero;
    tablero.draw();
    Point a0,b0,c0,d0,e0,f0,g0,h0;
    Point a1,b1,c1,d1,e1,f1,g1,h1;
    Point a2,b2,c2,d2,e2,f2,g2,h2;
    Point a3,b3,c3,d3,e3,f3,g3,h3;
    Point a4,b4,c4,d4,e4,f4,g4,h4;
    Point a5,b5,c5,d5,e5,f5,g5,h5;
    Point a6,b6,c6,d6,e6,f6,g6,h6;
    Point a7,b7,c7,d7,e7,f7,g7,h7;
    Point arr[8][8]={{a0,a1,a2,a3,a4,a5,a6,a7}
                    ,{b0,b1,b2,b3,b4,b5,b6,b7}
                    ,{c0,c1,c2,c3,c4,c5,c6,c7}
                    ,{d0,d1,d2,d3,d4,d5,d6,d7}
                    ,{e0,e1,e2,e3,e4,e5,e6,e7}
                    ,{f0,f1,f2,f3,f4,f5,f6,f7}
                    ,{g0,g1,g2,g3,g4,g5,g6,g7}
                    ,{h0,h1,h2,h3,h4,h5,h6,h7}};
    piece caballoW1;
    piece caballoW2;
    piece alfilW1;
    piece alfilW2;
    piece torreW1;
    piece torreW2;
    piece reyW;
    piece reinaW;
    piece peonW1;
    piece peonW2;
    piece peonW3;
    piece peonW4;
    piece peonW5;
    piece peonW6;
    piece peonW7;
    piece peonW8;
    piece piezaw[16] = {peonW1,peonW2,peonW3,peonW4,peonW5,peonW6,peonW7,peonW8, alfilW1,alfilW2, torreW1,torreW2,reinaW,reyW, caballoW1,caballoW2};
    piece caballoB1;
    piece caballoB2;
    piece alfilB1;
    piece alfilB2;
    piece torreB1;
    piece torreB2;
    piece reyB;
    piece reinaB;
    piece peonB1;
    piece peonB2;
    piece peonB3;
    piece peonB4;
    piece peonB5;
    piece peonB6;
    piece peonB7;
    piece peonB8;
    piece piezab[16] = {peonB1,peonB2,peonB3,peonB4,peonB5,peonB6,peonB7,peonB8, alfilB1,alfilB2, torreB1,torreB2,reinaB,reyB, caballoB1,caballoB2};
    system("pause");
    return 0;
}
