#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace std;
//VARIABLES DE LAS QUE CONSTA LA PISTA
int const widthscreen = 1024;
int const heightscreen = 768;
int width_seg = 200;
int pista = 2000;
//DISEÑO
float camd = 0.84;

class ejeH {

public:
    float x, y, z;
    float x1,y1,w;
    float scale,curve;
    ejeH()
    {
        curve = 0;
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

class Objects{
public:
    int posx=90,posy=230;
    void Draw(char *ruta,sf::RenderWindow &app){
        sf::Texture texture;
        texture.loadFromFile(ruta);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(posx, posy);
        if(posy>200 && posy<250)sprite.setScale(2.5,2.5);
        if(posy>=250)sprite.setScale(5.5,5.5);
        app.draw(sprite);
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

class Game{
public:
        int pos = 0,FPS = 70;
        int posx = 0;
        int aceleracion = 0;
        int freno = 1;
        int cont = -1;

    int posxmove(vector<ejeH> lines){
        if(pos!=0 && aceleracion!=0){
            cont ++;
            if(lines[cont].curve > 0.0)return -10;
            if(lines[cont].curve < 0.0)return 10;
            return 0;
        }
    }
    void Controls(sf::RenderWindow &app){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) app.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) aceleracion-=freno;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) posx+=22;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) posx -= 22;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) aceleracion = 200;
    }

    void Run(sf::RenderWindow &app,int N,vector<ejeH> lines){



        while(app.isOpen())
        {
            app.setFramerateLimit(FPS);

            if (aceleracion <= 0)freno = 0;
            else freno = 2;
            pos += aceleracion; posx += posxmove(lines);

            sf::Event e;
            while(app.pollEvent(e))
            {
                if(e.type == sf::Event:: Closed)
                    app.close();
            }

            while(pos >= N*width_seg) pos -= N*width_seg;
            while(pos < 0) pos += N*width_seg;

            Controls(app);
            app.clear();
            int star_pos = pos/width_seg;
            int camH = 1500 + lines[star_pos].y;
            float x = 0,dx=0;
            int maxy;

            //LOAD CAR
            sf::Texture sprite_car;
            sprite_car.create(200,90);
            sprite_car.loadFromFile("sprite.png");
            sprite_car.setSmooth(true);
            sf::Sprite sprite_Car;
            sprite_Car.setTexture(sprite_car);



            app.clear(sf::Color(0, 185, 179));

            for( int n = star_pos;n  < star_pos + 300; n++ )
            {
                ejeH &l = lines[n%N];
                l.cordenates_Scre(posx - x,camH,pos /*- (n >= N?N*width_seg:0))*/);
                x+=dx;
                dx+=l.curve;


                sf::Color grass = (n/3)%2 ? sf::Color(16,200,16) : sf::Color (0,154,0);
                sf::Color rumble = (n/3)%2 ? sf::Color(255,255,255) : sf::Color  (255,0,0);
                sf::Color road = (n/3)%2 ? sf::Color(93,93,93) : sf::Color (78,78,78);
                sf::Color lad = (n/3)%2 ? sf::Color(255,255,255) : sf::Color (78,78,78);
                sprite_Car.setPosition(widthscreen/2 - 70.f,heightscreen - 200.f);
                app.draw(sprite_Car);


                //if(l.y1 < maxy) maxy = l.y1;
                if(l.y1 >= maxy){ maxy = heightscreen; continue;}
                else maxy = l.y1;



                ejeH p = lines[(n - 1)% N];

                draw_race(app, grass,0,p.y1,widthscreen,0, l.y1,widthscreen);
                draw_race(app, rumble, p.x1,p.y1,p.w*1.2,l.x1,l.y1,l.w*1.2);
                draw_race(app, road,p.x1,p.y1 , p.w , l.x1,l.y1,l.w);
                draw_race(app, lad,p.x1,p.y1 , p.w/18 , l.x1,l.y1,l.w/18);

            }
            //for(int i=0;i<7;i++){Objects.Draw("Imagenes/ar.png",app);}

            app.display();
        }
    }
};
int main()
{
    sf::RenderWindow app(sf::VideoMode(widthscreen, heightscreen), "POOL POSITION");

    vector<ejeH> lines;
    for(int i = 0; i < 4000; i++)
    {
        ejeH line;
        line.z = i * width_seg;

        if(i > 500 && i < 700) line.curve = 1.5;
        if(i > 1000 && i < 1400) line.curve = -2.5;
        if(i>1600)line.curve = 0.7;
        if(i > 2000 && i < 2900)line.y = sin((i/40.0))* 545;


        lines.push_back(line);
    }
    int N = lines.size();
    Game Poly;
    Poly.Run(app,N,lines);
    return 0;
}
