#ifndef __Poison_h__
#define __Poison_h__

#include "Snake.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Snake;

class Poison
{
private:
    int X;
    int Y;

public:
    Poison();
    void init();
    int getX();
    int getY();
    void set(Snake s);

};

#endif