#ifndef DINERO_H
#define DINERO_H


class Dinero
{
    public:
        Dinero();
        Dinero(int);
        Dinero(Dinero &o);
        virtual int getx();
        int gety();
        void setx(int);
        void setnum(int);
        void sety(int);
        void print();
        ~Dinero();
    private:
        int x;
        int y;
        int *num;
};

#endif // DINERO_H
