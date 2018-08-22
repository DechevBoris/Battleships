#pragma once
#include "Ship.h"

class Submarine : public Ship
{
public:
    Submarine();
    string getType()const;
    ~Submarine(){};
};

