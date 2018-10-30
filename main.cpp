#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

//VARIABLES DE LAS QUE CONSTA LA PISTA
using namespace std;
int const widthscreen = 1024;
int const heightscreen = 768;
int width_seg = 200;
int pista = 2000;

//DISEÑO

float camd = 0.84;

/*class pos {
public:
    float x, y ,z;
};
class screenpos {
public:

    //PANTALLA
    int x, y ,w;
    //EJEH
    float x1, y1, w1;

};*/
class ejeH {
public:
    float x, y, z;
    float x1,y1,w;
    float scale;
    ejeH()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    void cordenates_Scre(int camx , int camy , int camz)
    {
        scale = camd/(z - camz);
        x1 = (1 + scale*(x - camx)) * widthscreen/2;
        y1 = (1 - scale*(y - camy)) * heightscreen/2;
        w =  scale * pista * widthscreen/2;
    }

};


void draw_race(sf::RenderWindow &w,  sf::Color c, int x1, int y1, int wid1, int x2, int y2, int wid2)
{
    sf::ConvexShape shape(4);
    shape.setFillColor(c);
    shape.setPoint(0, sf::Vector2f(x1 - wid1, y1));
    shape.setPoint(1, sf::Vector2f(x2 - wid2, y2));
    shape.setPoint(2, sf::Vector2f(x2 + wid2, y2));
    shape.setPoint(3, sf::Vector2f(x1 + wid1, y1));
    w.draw(shape);
}
int main()
{
    sf::RenderWindow app(sf::VideoMode(widthscreen, heightscreen), "POOL POSITION");
    app.setFramerateLimit(60);



    vector<ejeH> lines;

    for(int i = 0; i < 1600; i++)
    {
        ejeH line;
        line.z = i * width_seg;
        lines.push_back(line);
    }

    int N = lines.size();



    while(app.isOpen())
    {
        sf::Event e;
        while(app.pollEvent(e))
        {
            if(e.type == sf::Event:: Closed)
                app.close();
        }


        app.clear();
       // draw_race(app, sf::Color::White,500,500,200,500,300,100);


        for( int n = 0; n < 300; n++ )
        {
            ejeH &l = lines[n%N];
            l.cordenates_Scre(0,1500,0);

            sf::Color grass = (n/3)%2 ? sf::Color(16,200,16) : sf::Color (0,154,0);
            sf::Color rumble = (n/3)%2 ? sf::Color(255,255,255) : sf::Color  (0,0,0);
            sf::Color road = (n/3)%2 ? sf::Color(107,107,107) : sf::Color (44,34,43);

            ejeH p = lines[(n - 1)% N];

            draw_race(app, grass,0,p.y1,widthscreen,0, l.y1,widthscreen);
            draw_race(app, rumble, p.x1,p.y1,p.w*1.2,l.x1,l.y1,l.w*1.2);
            draw_race(app, road,p.x1,p.y1 , p.w , l.x1,l.y1,l.w);

        }



        app.display();
    }



    return 0;
}
