#include "snake.h"

#define mapsize 21

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
    ㅑㄹ (body[0][0] == mapsize-1 || body[0][0] == 0 || body[0][1] == 0 || body[0][1] == mapsize -1)? true : false
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

