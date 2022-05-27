#include "Poison.h"

void Poison::init()
{
    srand(time(NULL));
    X = 1;
    Y = 1;
}

int Poison::getX()
{
    return X;
}

int Poison::getY()
{
    return Y;
}

void Poison::set(Snake s)
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