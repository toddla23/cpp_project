#include "Growth.h"

Growth::Growth()
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
        X = rand() % 19 + 1;
        Y = rand() % 19 + 1;

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