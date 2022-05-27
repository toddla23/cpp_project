#include "Growth.h"

void Growth::init()
{
    srand(time(NULL));
    X = 1;
    Y = 1;
}

int Growth::getX()
{
    return X;
}

int Growth::getY()
{
    return Y;
}

void Growth::set(Snake s)
{
    int n = 0;

    do
    {
        n = 0;
        X = rand() % 21;
        Y = rand() % 21;

        for(int i = 0; i < s.getSize(); i++)
        {
            if(X == s.getBody_X(i) && Y == s.getBody_Y(i))
            {
                n++;
                break;
            }
        }

    }while(n != 0);

}