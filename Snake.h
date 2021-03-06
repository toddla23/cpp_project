#ifndef __Snake_h__
#define __Snake_h__

#include <iostream>
#include <vector>

#include "Growth.h"
#include "Poison.h"
#include "Gate.h"

using namespace std;

class Growth;
class Poison;
class Gate;

class Snake
{
private:
    //vector <vector<int>> body(441, vector<int>(2)); body 크기를 적당하게 하려했는데 벡터가 안됨... (왜 안되는지 모르곘네)
    int body[20][2];
    int size;
    int direction;

public:
    Snake();
    void move(int dir);
    int getSize();
    int getBody_X(int n);
    int getBody_Y(int n);

    void iseatG(Growth G);
    void iseatP(Poison P);
    void is_enter_gate(Gate G);


    bool SnakeIsDead(Gate G);
};

#endif