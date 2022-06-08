#ifndef __Growth_h__
#define __Growth_h__

#include "Snake.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Snake;

class Growth
{
private:
    int X;
    int Y;

public:
    Growth();
    int getX();
    int getY();
    void set(Snake s);

};

#endif