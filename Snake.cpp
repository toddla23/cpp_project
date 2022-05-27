#include "Snake.h"

#define mapsize 21

void Snake::init()
{
    size = 5;
    body[0][0] = 11;
    body[0][1] = 11;

    body[1][0] = 11;
    body[1][1] = 12;

    body[2][0] = 11;
    body[2][1] = 13;

    body[3][0] = 11;
    body[3][1] = 14;

    body[4][0] = 11;
    body[4][1] = 15;
}

int Snake::getSize()
{
    return size;
}

int Snake::getBody_X(int n)
{
    return body[n][0];
}

int Snake::getBody_Y(int n)
{
    return body[n][1];
}

bool Snake::SnakeIsDead()
{
    if(body[0][0] == mapsize-1 || body[0][0] == 0 || body[0][1] == 0 || body[0][1] == mapsize -1)
        return 1;

    for(int i = 1; i < size; i++)
        if(body[0][0] == body[i][0] && body[0][1] == body[i][1])
            return 1;
    
    return 0;
}

void Snake::move(char direction)
{
    for(int i = size-1; i > 0; i--)
    {
        body[i][0] = body[i-1][0];
        body[i][1] = body[i-1][1];
    }
    if(direction == 'a')
        body[0][1]--;
    else if (direction == 'w')
        body[0][0]--;
    else if (direction == 'd')
        body[0][1]++;
    else if (direction == 's')
        body[0][0]++;
}


void Snake::iseatG(Growth G)
{
    if(body[0][0] == G.getX() && body[0][1] == G.getY())
    {
        body[size][0]= body[size -1][0] + (body[size-1][0]- body[size-2][0]);
        body[size][0]= body[size -1][0] + (body[size-1][0]- body[size-2][0]);
        size++;
    }
}

void Snake::iseatP(Poison P)
{
    if(body[0][0] == P.getX() && body[0][1] == P.getY())
        size--;
}

