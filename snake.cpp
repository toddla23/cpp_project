#include "snake.h"

void Snake::init()
{
    size = 3;
    body[0][0] = 11;
    body[0][1] = 11;

    body[1][0] = 11;
    body[1][1] = 12;

    body[2][0] = 11;
    body[2][1] = 13;
}

void Snake::move(char direction)
{
    if(direction == 'w')
        body[0][1]--;
    else if (direction == 'a')
        body[0][0]--;
    else if (direction == 's')
        body[0][1]++;
    else if (direction == 'd')
        body[0][0]++;
    
    for(int i = 1; i <size; i++)
    {
        body[i][0] = body[i-1][0];
        body[i][1] = body[i-1][0];
    }
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