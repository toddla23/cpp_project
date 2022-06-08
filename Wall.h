#ifndef __Wall_h__
#define __Wall_h__

#include <iostream>

class Gate;

class Wall
{
private:
    int stage;
    int wall[400][2];
    int size;
    friend class Gate;


public:
    Wall(int n);

};

#endif

