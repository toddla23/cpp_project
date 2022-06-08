#ifndef __Gate_h__
#define __Gate_h__

#include "Snake.h"
#include "Wall.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Snake;
class Wall;

class Gate
{
private:
    int X1, X2, Y1, Y2;

public:
    Gate();
    int getX1();
    int getY1();
    int getX2();
    int getY2();
    void set(Wall& w);

};

#endif