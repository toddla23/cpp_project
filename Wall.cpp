#include "Wall.h"


Wall::Wall(int stage)
{
    
    int n = 0;
    for(int i = 1; i < 20; i++)
    {
        wall[n][0] = i;
        wall[n][1] = 0;
        size++;
        n++;
    }
    for(int i = 1; i < 20; i++)
    {
        wall[n][0] = i;
        wall[n][1] = 20;
        size++;
        n++;
    }
    for(int i = 1; i < 20; i++)
    {
        wall[n][1] = i;
        wall[n][0] = 0;
        size++;
        n++;
    }
    for(int i = 1; i < 20; i++)
    {
        wall[n][1] = i;
        wall[n][0] = 20;
        size++;
        n++;
    }

}
