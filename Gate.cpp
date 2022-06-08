#include "Gate.h"

Gate::Gate()
{
    srand(time(NULL));
}

int Gate::getX1()
{
    return X1;
}

int Gate::getY1()
{
    return Y1;
}

int Gate::getX2()
{
    return X2;
}

int Gate::getY2()
{
    return Y2;
}

void Gate::set(Wall& w)
{
    
    int n1 = rand()% w.size;
    int n2 = rand()% w.size;
    while(n2 == n1)
        n2 = rand()% w.size;

    X1 = w.wall[n1][0];
    Y2 = w.wall[n1][1];

    X2 = w.wall[n2][0];
    Y2 = w.wall[n2][1];


}