#ifndef VECTOR_H
#define VECTOR_H
#include<Dinero.h>


class Vector : public Dinero
{
    public:
        Vector();
        void setw(int);
        int getx();
    private:
        int w;
};

#endif // VECTOR_H
