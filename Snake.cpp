#include "Snake.h"

#define mapsize 21

Snake::Snake()
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

bool Snake::SnakeIsDead(Gate G)
{
    if(body[0][0] == G.getX1() && body[0][1] == G.getY1())
        return 0;

    if(body[0][0] == G.getX2() && body[0][1] == G.getY2())
        return 0;
    
    if(body[0][0] == mapsize-1 || body[0][0] == 0 || body[0][1] == 0 || body[0][1] == mapsize -1)
        return 1;

    for(int i = 1; i < size; i++)
        if(body[0][0] == body[i][0] && body[0][1] == body[i][1])
            return 1;
    if(size < 1)
        return 1;
    
    return 0;
}

void Snake::move(int dir)
{
    direction = dir;
    for(int i = size-1; i > 0; i--)
    {
        body[i][0] = body[i-1][0];
        body[i][1] = body[i-1][1];
    }
    if(direction == 97) // a
        body[0][1]--;
    else if (direction == 119) // w
        body[0][0]--;
    else if (direction == 100) // d
        body[0][1]++;
    else if (direction == 115) // s
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

void Snake::is_enter_gate(Gate G)
{
    
    if(body[0][0] == G.getX1() && body[0][1] == G.getY1())
    {
        if(G.getX2() == 0)
        {
            body[0][0] = G.getX2() + 1;
            body[0][1] = G.getY2();
            direction = 'd';
        }
        else if(G.getY2() == 0)
        {
            body[0][0] = G.getX2();
            body[0][1] = G.getY2() + 1;
            direction = 's';

        }
        else if(G.getX2() == 20)
        {
            body[0][0] = G.getX2() - 1;
            body[0][1] = G.getY2();
            direction = 'a';

        }
        else if(G.getY2() == 20)
        {
            body[0][0] = G.getX2();
            body[0][1] = G.getY2() - 1;
            direction = 'w';
        }
    }

    else if(body[0][0] == G.getX2() && body[0][1] == G.getY2())
    {
        if(G.getX1() == 0)
        {
            body[0][0] = G.getX1() + 1;
            body[0][1] = G.getY1();
            direction = 'd';
        }
        else if(G.getY1() == 0)
        {
            body[0][0] = G.getX1();
            body[0][1] = G.getY1() + 1;
            direction = 's';
        }
        else if(G.getX1() == 20)
        {
            body[0][0] = G.getX1() - 1;
            body[0][1] = G.getY1();
            direction = 'a';
        }
        else if(G.getY1() == 20)
        {
            body[0][0] = G.getX1();
            body[0][1] = G.getY1() - 1;
            direction = 'w';
        }
    }
    
}

